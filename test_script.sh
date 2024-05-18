#!/bin/bash

gcc main.c -o aco_program -lm

echo "Test case 1:"
echo -e "kota_05.csv\nMakassar\n" | ./aco_program | tee output_test_case_1.txt

echo "Test case 2:"
echo -e "kota_06.csv\nJakarta\n" | ./aco_program | tee output_test_case_2.txt

echo "Test case 3:"
echo -e "kota_07.csv\nSurabaya\n" | ./aco_program | tee output_test_case_3.txt

echo "Test case 4:"
echo -e "kota_08.csv\nBandung\n" | ./aco_program | tee output_test_case_4.txt

echo "Test case 5:"
echo -e "kota_09.csv\nMedan\n" | ./aco_program | tee output_test_case_5.txt

echo "Test case 6:"
echo -e "kota_10.csv\nPalembang\n" | ./aco_program | tee output_test_case_6.txt

echo "Test case 7:"
echo -e "kota_11.csv\nTangerang\n" | ./aco_program | tee output_test_case_7.txt

echo "Test case 8:"
echo -e "kota_12.csv\nDepok\n" | ./aco_program | tee output_test_case_8.txt

echo "Test case 9:"
echo -e "kota_13.csv\nSemarang\n" | ./aco_program | tee output_test_case_9.txt

echo "Test case 10:"
echo -e "kota_14.csv\nPadang\n" | ./aco_program | tee output_test_case_10.txt

echo "Test case 11:"
echo -e "kota_15.csv\nDenpasar\n" | ./aco_program | tee output_test_case_11.txt

echo "Test case 12:"
echo -e "kota_16.csv\nMataram\n" | ./aco_program | tee output_test_case_12.txt

echo "Test case 13:"
echo -e "kota_17.csv\nManado\n" | ./aco_program | tee output_test_case_13.txt
