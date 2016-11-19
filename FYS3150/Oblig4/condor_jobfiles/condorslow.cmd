# Bruk din egen epost-adresse for notify_user, f.eks:
notify_user    = anders.johansson@hotmail.no
# I hvilke tilfeller nsker du epost fra Condor (Always, Complete, Error, Never)
# Unngå Never.
notification   = Always

universe       = vanilla
output         = condormediumprint.txt
input          = /dev/null

arguments      = "condorslow_new_new.imp 5000000 81 1"

executable     = phases.x
log            = condorslow_new_new.log
queue
