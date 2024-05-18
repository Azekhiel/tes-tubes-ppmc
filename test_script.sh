#!/bin/bash

# Compile the program
gcc -o aco_program main.c src/ACO.c -I src -lm

# Test case 1
echo -e "kota_05.csv\nMakassar" | ./aco_program > output1.txt

# Test case 2
echo -e "kota_16.csv\nJayapura" | ./aco_program > output2.txt
