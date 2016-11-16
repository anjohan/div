# Bruk din egen epost-adresse for notify_user, f.eks:
notify_user    = anders.johansson@hotmail.no
# I hvilke tilfeller nsker du epost fra Condor (Always, Complete, Error, Never)
# Unngå Never.
notification   = Always

universe       = vanilla
output         = condorquickprint.txt
input          = /dev/null

arguments      = "condorquick_new_new.imp 100000 41 1"

executable     = phases.x
log            = condorquick_new_new.log
queue
