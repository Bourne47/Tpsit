/*
author: Leonardo Pollicino
date: 24/11/2023
es. lista 
testo: Si consideri una lista dinamica di interi, i cui elementi sono del tipo definito
come di seguito riportato:

typedef struct El {
    int dato;
    struct El *next;
} ELEMENTO;

• Si codifichi in C la funzione somma avente il seguente prototipo:

int somma(ELEMENTO *Testa, int M)

• Tale funzione riceve come parametro la testa della lista e un intero M.

Quindi,
restituisce la somma dei soli valori della lista che sono multipli di M. Se la
lista è vuota, la funzione restituisce il valore -1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct El {
    int dato;
    struct El *next;
} ELEMENTO;

int sommaLista(ELEMENTO *Testa, int M){
    ELEMENTO* l = Testa;
    int somma = 0;
    if (l == NULL)
        return -1;
    while (l != NULL){
        if (l->dato % M == 0)
            somma+=l->dato;
        l = l ->next;
    }
    return somma; 
}

int main(){
    int n;
    int somma = 0;
    ELEMENTO* lista = NULL;
    ELEMENTO* l;
    do{
        printf("inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (ELEMENTO*) malloc(sizeof(ELEMENTO));
                l = lista;
            } else {
                l->next = (ELEMENTO*) malloc(sizeof(ELEMENTO));
                l = l->next;
            }
            l->dato = n;
            l->next = NULL;
        }
    } while (n >= 0);
    l = lista;
    printf("inserire il numero divisore: ");
    scanf("%d", &n);
    somma = sommaLista(lista, n);
    printf("%d", somma);

    free(lista);
    return 0;
}