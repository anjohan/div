from matplotlib.pyplot import *
from subprocess import check_output, CalledProcessError
from argparse import ArgumentParser
from datetime import datetime
import re as regex
import os
import sys

figure(figsize=(6,5))
rc("font",size=10,family="serif")
parser = ArgumentParser()
#Command-line arguments.
parser.add_argument("-d","--dir",default=".",help="The directory for which to find the git log.")
parser.add_argument("-s","--show",action="store_true",help="Option to show the resulting plot on screen.")
parser.add_argument("-o","--outfile",default=None,help="Save the resulting plot to the given OUTFILE. Filename must be given relative to the directory of this file.")

args = parser.parse_args()

#Store name of current directory, move to specified.
thisdirname = os.path.abspath(os.path.dirname(sys.argv[0]))
os.chdir(args.dir)
dirname = check_output("pwd")

#Checking if specified directory is in a git repository.
try:
    output = check_output(["git","rev-parse","--git-dir"])
except CalledProcessError:
    print "Given directory is not a git repository!"
    sys.exit(1)

#Extract information from git log, in a regex-friendly format.
log = check_output(["git","log","--format= %ae|%ai "])
regexres = regex.findall(r"\s+([^\|]+)\|(\d{4}\-\d{2}\-\d{2} \d{2}\:\d{2}\:\d{2}) (\+|\-)\d+",log)

logdict = {}
#Go through all the commits, extract information.
for res in regexres:
    email, time, stuff = res
    #Convert time from ISO-format to a datetime object (plottable by matplotlib).
    time = datetime.strptime(time,"%Y-%m-%d %H:%M:%S")
    if email in logdict:
        logdict[email].append(time)
    else:
        logdict[email] = [time]

#Go through all the authors, plot their total number of commits.
for email in logdict:
    #Time on the x-axis
    xvals = logdict[email][::-1]
    #Total amount of gits on the y-axis. The number of commits increases with one for every time.
    yvals = range(len(logdict[email]))
    xvals.append(datetime.now())
    yvals.append(yvals[-1])
    plot(xvals,yvals,"-",label=email)

#Matplotlib automagically formats xtics.
gcf().autofmt_xdate()
legend(loc="upper left")
ylim(ymin=-1)
xlabel("Time of commit")
ylabel("Total number of commits")
title("Commit log for %s" % dirname)

#Save file in given path relative to current directory.
if not args.outfile is None:
    savefig(thisdirname + "/" +  args.outfile)

#Show the resulting plot on screen.
if args.show:
    show()
