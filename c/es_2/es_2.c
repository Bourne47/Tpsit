/*
author: Pollicino Leonardo
date: 02/10/2023
es. 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM 10

int calcolaSomma (int vett[], int num){
    int somma = 0;
    for (int c = 0; c < num; c++){
        somma += *(vett + c);
        //somma += vett[k];
    }
    return somma;
}

int main(){
    int vett[DIM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int somma = calcolaSomma(vett, DIM);
    printf("%d", somma);

    return 0;
}