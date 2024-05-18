#!/bin/bash

# Compile the program
gcc -o main.c -lm

# Test case 1
echo -e "kota_05.csv\nMakassar" | output > output1.txt

# Test case 2
echo -e "kota_16.csv\nJayapura" | output > output2.txt
