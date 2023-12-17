#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct macchina{
    int velocita;
}Macchina;

int main(){
    Macchina macchina;

    macchina.velocita = 200;
    printf("%d\n", macchina.velocita);
    scanf("%d", &macchina.velocita);
    printf("%d\n", macchina.velocita);
    Macchina* macchina2;

    macchina2 = (Macchina*)malloc(sizeof(Macchina));
    macchina2->velocita = 150;
    printf("%d\n", macchina2->velocita);
    scanf("%d", &macchina2->velocita);
    printf("%d\n", macchina2->velocita);
    free(macchina2);
    
    return 0;
}