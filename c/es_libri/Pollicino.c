#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DIM 100
#define LUNG 35
#define DIM_RIGA 210

typedef struct{
    char *titolo;
    char *autore;
    int anno;
}Libro;

int menu() {
    int scelta;
    printf("0. - esci\n");
    printf("1. - stampa lista libri\n");
    printf("2. - stampa lista libri con informazioni\n");
    printf("3. - cerca libri usciti in un particolare anno\n");
    printf("4. - ordina libri per anno di uscita\n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

int contaRighe(char filename[], char riga[]){
    FILE *fp;
    int k = 0;

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("il file non esiste");
    }else{
        while(fgets(riga, DIM_RIGA, fp)){
            k++;
        }
    }

    fclose(fp);

    return k;
}

void stampaLibri(Libro lista[], int nLibri){
    for (int c = 0; c < nLibri; c++){
        printf("%d. %s\n", c+1, lista[c].titolo);
    }
}

void stampaInformazioni(Libro lista[], int nLibri){
    for (int c = 0; c < nLibri; c++){
        printf("%d. %s, %s, %d\n", c+1, lista[c].titolo, lista[c].autore, lista[c].anno);
    }
}

void ricercaAnnoLibro(Libro lista[], int nLibri, int anno){
    for (int c = 0; c < nLibri; c++){
        if (lista[c].anno == anno){
            printf("%s, %s, %d\n", lista[c].titolo, lista[c].autore, lista[c].anno);
        }
    }
}

void scambio(Libro* x, Libro* y){
    Libro temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void ordinaLibri(Libro lista[], int nLibri){
    int k, sup, sca;
    sup= nLibri-1 ;
    while (sup > 0) {
        sca = 0;
        for (k = 0; k < sup; k++) {
            if (lista[k].anno > lista[k + 1].anno){
                scambio(&lista[k], &lista[k + 1]);
                sca=k ;
            }
        }
        sup=sca ;
    }
}

int main(){
    Libro *lista;
    FILE *fp;
    int anno;
    int scelta;
    int cont = 0;
    char* campo;
    char riga[DIM_RIGA];
    char nomeFile[LUNG] = {"lista_libri.csv"};
    int righe = contaRighe(nomeFile, riga);

    lista = (Libro*)malloc(righe*sizeof(Libro));
    fp = fopen(nomeFile, "r");
    if (fp == NULL){
        printf("Problemi ad aprire il file!!!\n");
        exit(1);
    }
    while(fgets(riga, DIM_RIGA, fp)){
        campo = strtok(riga, ",");
        (lista+cont)->titolo = strdup(campo);
        campo = strtok(NULL, ",");
        (lista+cont)->autore = strdup(campo);
        campo = strtok(NULL, ",");
        (lista+cont)->anno = atoi(campo);
        cont++;
    }
    fclose(fp);
    do{
        scelta = menu();
        switch (scelta){
            case 0:
                break;
            case 1:
                stampaLibri(lista, cont);
                break;
            case 2:
                stampaInformazioni(lista, cont);
                break;
            case 3:
                printf("Inserisci l'anno del quale vuoi vedere i libri pubblicati: ");
                scanf("%d", &anno);
                ricercaAnnoLibro(lista, cont, anno);
                break;
            case 4:
                ordinaLibri(lista, cont);
                stampaInformazioni(lista, cont);
                break;
        }
    }while (scelta != 0);
    free(lista);
    return 0;
}