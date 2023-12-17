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

void selectionSort(int vett[],int n) {
    for(int *k = vett; k < vett + n - 1; k++) {
        int *kmin = k;
        for(int *j = k + 1; j < vett + n; j++){
            if(*kmin > *j)
                kmin = j;
        }
        if(*kmin != *k)
            scambio(k, kmin);
    }
}

void stampaVett(int vett[], int n){
    for (int *k = vett; k < vett + n; k++){
        printf("%d ", *k);
    }
}

int main(){
    int vett[DIM] = {5, 2, 7, 9, 1, 6, 3, 8, 4, 10};

    selectionSort(vett, DIM);
    stampaVett(vett, DIM);

    return 0;
}