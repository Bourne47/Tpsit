/*
author: Pollicino Leonardo
date: 02/10/2023
es. 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM 10

void scambio(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int vett[], int n){
    int k, sup;
    for (sup = n-1; sup > 0; sup--){
        for (k = 0; k < sup ; k++){
            if (*(vett+k) > *(vett+k+1))
                scambio((vett+k), (vett+k+1));
        }
    }
}

void stampaVett(int vett[], int n){
    for (int k = 0; k < n; k++){
        printf("%d ", *(vett+k));
    }
}

int main(){
    int vett[DIM] = {5, 2, 7, 9, 1, 6, 3, 8, 4, 10};

    bubbleSort(vett, DIM);
    stampaVett(vett, DIM);

    return 0;
}