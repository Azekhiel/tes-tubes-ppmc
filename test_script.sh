#!/bin/bash

# Debugging: List files to ensure paths are correct
echo "Listing files in the current directory"
ls -al

# Compile the program
gcc -o aco_program main.c ACO.c -lm

# Debugging: Check if the compilation was successful
if [ ! -f ./aco_program ]; then
    echo "Compilation failed or aco_program not found!"
    exit 1
fi

# Test case 1
echo -e "kota_05.csv\nMakassar" | ./aco_program > output1.txt

# Test case 2
echo -e "kota_16.csv\nJayapura" | ./aco_program > output2.txt
