alias sq='squeue -u $USER'
alias sqs='squeue -u $USER --start'
alias sqp='squeue -A PARTITION'
alias sqps='squeue -A PARTITION --start'
alias part='sinfo -S+P -o "%18P %8a %20F"'

function log {
    tail -n 100 -f $(ls slurm* | tail -n 1)
}
