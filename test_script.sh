#!/bin/bash

# Compile the program
gcc main.c -o aco_program

# Test case 1
echo "Test case 1:"
echo -e "kota_05.csv\nMakassar\n" | ./aco_program | tee output_test_case_1.txt

# Test case 2
echo "Test case 2:"
echo -e "kota_16.csv\nJayapura\n" | ./aco_program | tee output_test_case_2.txt
