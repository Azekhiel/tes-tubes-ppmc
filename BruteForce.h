#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    char name[50];
    double latitude;
    double longitude;
} City1;

double deg2rad_brute(double deg) {
    return deg * (3.14159265359/180);
}

double hitungJarak_brute(City1 kota1, City1 kota2) {
    double latitude1 = deg2rad_brute(kota1.latitude);
    double longitude1 = deg2rad_brute(kota1.longitude);
    double latitude2 = deg2rad_brute(kota2.latitude);
    double longitude2 = deg2rad_brute(kota2.longitude);
    
    double longitudeDiff = longitude2 - longitude1;
    double latitudeDiff = latitude2 - latitude1;
    
    double jarak = 2 * 6371 * asin(sqrt(pow(sin(latitudeDiff / 2), 2) + cos(latitude1) * cos(latitude2) * pow(sin(longitudeDiff / 2), 2)));
    
    return jarak;
}

int Index(City1 kota[], int numKota, char *kotaTujuan) {
    for (int i = 0; i < numKota; i++) {
        if (strcmp(kota[i].name, kotaTujuan) == 0) { //Cek index kota Starting Point
            return i;
        }
    }
    return -1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

double hitungJarak_bruteRute(City1 kota[], int route[], int numKota) {
    double jarak = 0;
    for (int i = 0; i < numKota - 1; i++) {
        jarak += hitungJarak_brute(kota[route[i]], kota[route[i + 1]]); //Menghitung jarak kota sekarang dan selanjutnya
    }
    jarak += hitungJarak_brute(kota[route[numKota - 1]], kota[route[0]]); //Kembali ke Starting Point
    return jarak;
}

void copyRoute(int a[], int b[], int numKota) {
    for (int i = 0; i < numKota; i++) {
        b[i] = a[i];
    }
}

void printRoute(City1 kota[], int route[], int numKota) {
    for (int i = 0; i < numKota; i++) {
        printf("%s -> ", kota[route[i]].name);
    }
    printf("%s\n", kota[route[0]].name);
}

void bruteForce(City1 kota[], int route[], int start, int end, int bestRoute[], double *minDistance, int numKota) {
    if (start == end) { //start = 1 ; end = jumlah kota (numKota-1)
        double currentDistance = hitungJarak_bruteRute(kota, route, numKota); //Cari jarak antar kota
        /* periksa tiap iterasi
        printf("Temp Route: ");
        printRoute(kota, route, numKota);
        printf("Route distance: %.5f km\n", currentDistance);
        */
        if (currentDistance < *minDistance) {
            *minDistance = currentDistance;
            copyRoute(route, bestRoute, numKota); //Memasukan nilai jarak yang ada ke bestRoute
        }
    } 
    else {
        for (int i = start; i <= end; i++) { //Menambahkan kota per kota ke Route
            swap(&route[start], &route[i]);
            bruteForce(kota, route, start + 1, end, bestRoute, minDistance, numKota); //Mulai iterasi dengan index + 1
            swap(&route[start], &route[i]);
        }
    }
}

double cariJarak(City1 kota[], int numKota, char *kotaTujuan, int bestRoute[]) {
    int indexAwal = Index(kota, numKota, kotaTujuan);
    if (indexAwal == -1) {
        printf("Starting point city : '%s' not found.\n", kotaTujuan); //Jika starting point city tidak ditemukan
        exit(1);
    }
    int route[numKota];
    for (int i = 0; i < numKota; i++) { //Array route sementara
        route[i] = i;
    }
    swap(&route[0], &route[indexAwal]); // Array route pertama = kota Starting Point
    
    double minDistance = INFINITY;
    bruteForce(kota, route, 1, numKota - 1, bestRoute, &minDistance, numKota);
    return minDistance;
}

int bruteForce_final(char fileName[],char kotaTujuan[]) {
    printf("\nAlgoritma BruteForce:\n");
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File not found or empty.\n");
        return 1;
    }
    
    int numKota = 0;
    char line[100];
    while (fgets(line, sizeof(line), file)) { //numKota = jumlah kota yang ada
        numKota++;
    }
    rewind(file);
    
    City1 kota[numKota];
    char cityName[50];
    double latitude, longitude;
    int index = 0;
    while (fscanf(file, "%49[^,],%lf,%lf\n", cityName, &latitude, &longitude) == 3) {
        strcpy(kota[index].name, cityName);
        kota[index].latitude = latitude;
        kota[index].longitude = longitude;
        index++;
    }
    fclose(file);
    
    int bestRoute[numKota];
    clock_t start = clock();
    double Jarak = cariJarak(kota, numKota, kotaTujuan, bestRoute);
    clock_t end = clock();
    double timeElapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Best route found:\n");
    for (int i = 0; i < numKota; i++) {
        printf("%s -> ", kota[bestRoute[i]].name);
    }
    printf("%s\n", kotaTujuan);
    
    printf("Best route distance: %.5f km\n", Jarak);
    printf("Time elapsed: %.10f s\n", timeElapsed);
    
    return 0;
}