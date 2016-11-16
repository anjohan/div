# Bruk din egen epost-adresse for notify_user, f.eks:
notify_user    = anjohan@uio.no
# I hvilke tilfeller nsker du epost fra Condor (Always, Complete, Error, Never)
# Unngå Never.
notification   = Always

universe       = vanilla
output         = condorquickprint.txt
input          = /dev/null

arguments      = "condorquick.dat 100000 40 2"

executable     = phases.x
log            = condorquick.log
queue
