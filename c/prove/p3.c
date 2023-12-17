#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct macchina{
    int velocita;
    int posti;
}Macchina;

/*void inserisciDatiMacchine(Macchina* macchine, int num){
    for (){
        
    }
}*/ 
int main(){
    int num;
    printf("Inserisci il numero di macchine: ");
    scanf("%d", &num);
    Macchina* macchine = (Macchina*)malloc(num*sizeof(Macchina));
    for (Macchina* macchina = macchine; macchina < macchine + num; macchina++){
        macchina->velocita = 100;
        macchina->posti = 4;
    }
    //inserisciDatiMacchine(macchine, num);
    for (Macchina* macchina = macchine; macchina < macchine + num; macchina++){
        printf("%d %d\n", macchina->velocita, macchina->posti);
    }
    free(macchine);
    return 0;
}