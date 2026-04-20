#!/bin/bash -l

#SBATCH -p gpu-h100
#SBATCH --gres=gpu:1
#SBATCH -D ./
#SBATCH --export=ALL

./deviceQuery
