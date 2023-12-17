#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stampaVett(int* vett, int num){
    for (int* cont = vett; cont < vett + num; cont++){
        printf("%p %d ", cont, *cont);
    }
    printf("\n");
}

int main(){
    int num;
    printf("Inserisci la lunghezza del vettore: ");
    scanf("%d", &num);

    printf("%d\n", num);
    int *vett;
    vett = (int*)malloc(num*sizeof(int));
    for (int* cont = vett; cont < vett+num; cont++){
        printf("Inserisci un numero intero: ");
        scanf("%d", cont);
    }
    for (int* cont = vett; cont < vett+num; cont++)
        printf("%p %d ", cont, *cont);
    printf("\n");
    stampaVett(vett, num);
    free(vett);

    return 0;
}