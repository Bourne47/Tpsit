/*
author: Pollicino Leonardo
date: 22/10/2023
es. malloc intero
*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    int dim;
    printf("Inserisci il numero di numeri che vuoi inserire: ");
    do{
        scanf("%d", &dim);
    }while (dim < 0 || dim > 100);
    int *array = (int*) malloc(dim*sizeof(int));
    if (array == NULL){
        printf("errore!!!\n");
        return 1;
    }
    for (int *i = array; i < array+dim; i++){
        printf("Inserisci il numero: ");
        scanf("%d", i);
    }
    for (int *c = array; c < array+dim; c++){
        printf("%d\n", *c);
    }
    free(array);
    return 0;
}
