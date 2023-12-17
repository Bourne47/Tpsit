/*
author: Leonardo Pollicino
date: 14/12/2023
es. lista 3
testo:
typedef struct El {
    int s;
    struct El *next;
}ElementoLista;

typedef ElementoLista *ListaDiInteri;

• definire una funzione FirstEven che, data
una ListaDiInteri restituisce la posizione (puntatore) del primo elemento pari
nella lista (restituisce NULL se la lista non contiene elementi pari).

ListaDiInteri FirstEven(ListaDiInteri lis) {
    while (lis != NULL) {
        if (lis->s % 2 == 0)
            return lis; // il primo pari è in lis 
        else
            lis = lis->next;
    }
    return NULL;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct El {
    int s;
    struct El *next;
}ElementoLista;

typedef ElementoLista *ListaDiInteri;

ListaDiInteri FirstEven(ListaDiInteri lis) {
    int indice = 0;
    while (lis != NULL) {
        if (lis->s % 2 == 0){
            return lis;
        } else {
            lis = lis->next;
            indice++;
        }
    }
    return NULL;
}

int main(){
    int n;
    int somma = 0;
    ElementoLista* lista = NULL;
    ElementoLista* l;
    do{
        printf("inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (ElementoLista*) malloc(sizeof(ElementoLista));
                l = lista;
            } else {
                l->next = (ElementoLista*) malloc(sizeof(ElementoLista));
                l = l->next;
            }
            l->s = n;
            l->next = NULL;
        }
    } while (n >= 0);
    ListaDiInteri primoPari = FirstEven(lista);
    if (primoPari != NULL) {
        printf("Primo elemento pari trovato con valore %d all'indirizzo %p\n", primoPari->s, primoPari);
    } else {
        printf("Nessun elemento pari trovato nella lista.\n");
    }
    free(lista);
    free(primoPari);
    return 0;
}