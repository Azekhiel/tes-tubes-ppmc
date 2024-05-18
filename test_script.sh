#!/bin/bash

# Compile the program
gcc -o aco_program main.c ACO.c -lm

# Test case 1
echo -e "kota_05.csv\nMakassar" | ./aco_program > output1.txt
if grep -q "Jarak Tempuh:" output1.txt; then
    echo "Test case 1 passed."
else
    echo "Test case 1 failed."
    cat output1.txt
    exit 1
fi

# Test case 2
echo -e "kota_16.csv\nJayapura" | ./aco_program > output2.txt
if grep -q "Jarak Tempuh:" output2.txt; then
    echo "Test case 2 passed."
else
    echo "Test case 2 failed."
    cat output2.txt
    exit 1
fi
