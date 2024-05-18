#!/bin/bash

# Compile the program
gcc -o aco_program main.c ACO.c -lm

# Test case 1
echo -e "kota_05.csv\nMakassar" | ./aco_program > output1.txt

# Test case 2
echo -e "kota_16.csv\nJayapura" | ./aco_program > output2.txt
