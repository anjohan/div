# -*- coding: utf-8 -*-
import os
import re as regex
import io
import time

while True:
    for navn in ("total","klasse"):
        os.system("wget http://www.skeet.no/resultater/nm2016/jt_html%s.htm -O %s.htm" % (navn,navn))
    os.system("wget http://www.skeet.no/resultater/nm2016/jt_htmllag.htm -O lag.htm")
    with open("total.htm","r") as fil:
        total = fil.read()
    with open("klasse.htm","r") as fil:
        klasse = fil.read()
    with open("lag.htm","r") as fil:
        lag = fil.read()
    for fart, leser in zip([2,1],["","chrome"]):
        fil = open("resultater%s.html" % leser, "w")
        fil.write(r"""<!DOCTYPE html>
        <html>
        <head>
        <title>NM Skeet 2016</title>
        <meta charset="utf-8"/>
        <meta name="author" content="Anders Johansson"/>
        <meta name="Description" content="Resultatvisning, NM Skeet 2016"/>
        <meta http-equiv="refresh" content="121" >
        <style>
        td.tjuefem {
            color: red;
            font-weight: bold;
        }
        td.tjuefire {
            color: green;
            font-weight: bold;
        }
        </style>

        </head>
        <body>
        <h1 style="text-align: center;">Resultater NM Skeet 2016</h1>
        <p id="test" onload="test();"></p>
        <table style="width: 100%%; margin: auto;"><tr>
        """)

        try:
            for navn, typ in zip(["Totalresultater","Klassevise resultater"],[total,klasse]):
                fil.write("<td style=\"width: 50%%; vertical-align: top; text-align: center; padding: 0px 40px;\">")
                fil.write("<span style=\"font-weight: bold; font-size:24px;\">" + navn + "</span>")
                tabell = regex.search(r"(\<table(.|\n)*?)\<\/body",typ,regex.UNICODE).group(1)
                tabell = tabell.replace("</td><td>25","</td><td class=\"tjuefem\">25").replace("</td><td>24","</td><td class=\"tjuefire\">24")
                tabell = tabell.replace("<th>Omg</th><th>Fin</th>","")
                tabell = regex.sub(r"<td>0</td><td>0</td>(<td>\d+</td></tr>)",r"\1",tabell)
                fil.write(tabell + "</table></td>")
            fil.write("</tr></table>")
            fil.write("<table style=\"width: 100%%; margin: auto;\"><tr><td>")
            tabell = regex.search(r"(\<table(.|\n)*?\<\/table\>)",lag,regex.UNICODE).group(1)
            fil.write("<p style=\"font-weight: bold; font-size:24px;\">Lagresultater</p>")
            fil.write(tabell + "</td></tr></table>")
        except:
            print "Feil"
        fil.write("""
        <script>
        console.log("InnerHeight: " + window.innerHeight);
        var fart = %i;
        var pos0 = 0, pos1 = 0;
        window.scrollTo(0,0);
        function scrolling(){
            window.scrollBy(0,fart);
            pos0 = pos1;
            pos1 = window.scrollY;
            if(pos1 == pos0){
                fart *= -1;
            }
        }
        var scrollevent = setInterval(scrolling,12);
        scrolling();
        </script>
        """ % fart)
        fil.write("</body> </html>")
        fil.close()
        os.system("iconv -f ISO-8859-14 -t utf-8 resultater%s.html -o resultater%s.html" % (leser,leser))
        os.system("chmod 744 resultater%s.html" % leser)
        os.system("scp resultater%s.html ifi:~/www_docs" % leser)

    time.sleep(179)
