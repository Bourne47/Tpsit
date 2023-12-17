/*
author: Pollicino Leonardo
date: 18/09/2023
es. 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM_RIGA 200
#define NUM_RIGHE 20000

typedef struct {
    int numero;
    char* titolo;// char[10]
    char* genere;
    int anno;
    char* disponibilita;
} film;

void chiediAnno (int *anno){
    printf("Inserisci l'anno del quale vuoi vedere i film: \n");
    do {
        scanf("%d", anno);
    }while (*anno < 1800 || *anno > 2023);
}

void stampaFilmAnno(int anno, film array_film[], int c){
    for (film *cont = array_film; cont < array_film+c; cont++) {
        //if (array_film[cont].anno == anno)
        if (cont->anno == anno)
            printf("%d %s %s %d %s\n", cont->numero, cont->titolo, cont->genere, cont->anno, cont->disponibilita);
    }
}

void stampaTutto(film array_film[], int c){
    for (film *cont = array_film; cont < array_film+c; cont++) {
        printf("%d %s %s %d %s\n", cont->numero, cont->titolo, cont->genere, cont->anno, cont->disponibilita);
    }
}

int main () {
    char filename[] = "listafilm.csv";
    char riga[DIM_RIGA];
    FILE *fp;
    char *campo;
    film array_film[NUM_RIGHE];
    film *c = array_film;
    int anno;
    int cont = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("il file %s non esiste.\n", filename);
        exit(1);//fa uscire dal programma
    }
    while(fgets(riga, DIM_RIGA, fp)) {
        campo = strtok(riga, ",");
        //(*(array_film + c)).numero = atoi(campo);//altra versione
        c->numero = atoi(campo);//converte in intero atof converte in float
        campo = strtok(NULL, ",");//null perché strtok si ricorda la riga
        c->titolo = strdup(campo);
        campo = strtok(NULL, ",");
        c->genere = strdup(campo);
        campo = strtok(NULL, ",");
        c->anno = atoi(campo);
        campo = strtok(NULL, ",");
        c->disponibilita = strdup(campo);
        c++;
        cont++;
    }
    chiediAnno(&anno);
    stampaFilmAnno(anno, array_film, cont);
    
    return 0;
}
