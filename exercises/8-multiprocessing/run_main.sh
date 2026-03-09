#!/bin/bash

N=100000000
rm -f log.main

for t in 1 2 3 4 5 6 7 8
do
    /usr/bin/time --format "$t %e" ./main -threads $t -terms $N >> log.main 2>&1
done
