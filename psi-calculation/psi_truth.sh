#!/bin/bash -l
#SBATCH -J psi_truth_test                       #job name
#SBATCH --time=00-01:20:00                      #requested time (DD-HH:MM:SS)
#SBATCH -p batch,preempt                        #running on "batch" or "preempt" partition, wherever resource is available first
#SBATCH -N 1                                    #1 nodes #for many shared-memory programs,please leave -N as 1.
#SBATCH -n 2                                    #2 tasks total and 1 cpu per task, that gives you 2 cpu cores for this job
#SBATCH --mem=2g                                #requesting 2GB of RAM total for the number of cpus you requested
#SBATCH --output=psi_truth_test.%j.%N.out       #saving standard output to file, %j=JOBID, %N=NodeName
#SBATCH --error=psi_truth_test.%j.%N.err        #saving standard error to file, %j=JOBID, %N=NodeName
#SBATCH --mail-type=ALL                         #email options
#SBATCH --mail-user=sam.venetianer@tufts.edu    #please make sure to use your own Tufts email

export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase                      # these lines setup ROOT via CVMFS
source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh
lsetup "root recommended"

rm psi_truth
rm psi_truth.o
make
./psi_truth