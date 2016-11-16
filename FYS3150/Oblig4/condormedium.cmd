# Bruk din egen epost-adresse for notify_user, f.eks:
notify_user    = anjohan@uio.no
# I hvilke tilfeller nsker du epost fra Condor (Always, Complete, Error, Never)
# Unngå Never.
notification   = Complete

universe       = vanilla
output         = condormediumprint.txt
input          = /dev/null

arguments      = "condormedium.dat 500000 40 1"

executable     = phases.x
log            = condormedium.log
queue
