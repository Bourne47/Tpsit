/*
author: Leonardo Pollicino
date: 13/11/2023
es. lista 
testo creazione di una lista
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
    char valore;
    struct node* next;   
}Node;

typedef struct node_int
{
    int valore;
    struct node_int* next;   
}Node_int;

bool is_empty(Node* lista){
    if (lista == NULL)
        return true;
    return false;
}

bool is_empty_int(Node_int* lista){
    if (lista == NULL)
        return true;
    return false;
}

void push(Node** Head, Node* elemento){
    if (is_empty(*Head)){
        *Head = elemento;
        elemento->next = NULL;
    }else{
        elemento->next = *Head;
        *Head = elemento;
    }
}

void push_int(Node_int** Head, Node_int* elemento){
    if (is_empty_int(*Head)){
        *Head = elemento;
        elemento->next = NULL;
    }else{
        elemento->next = *Head;
        *Head = elemento;
    }
}

Node* pop(Node** Head){
    Node* ret = *Head;
    if (is_empty(*Head)){
        return NULL;
    }else{
        *Head = ret->next;
        return ret;
    }
}

Node_int* pop_int(Node_int** Head){
    Node_int* ret = *Head;
    if (is_empty_int(*Head)){
        return NULL;
    }else{
        *Head = ret->next;
        return ret;
    }
}

void stampaPila(Node* Head){
    Node* l = Head;
    printf("\nValori pila: ");
    while (l != NULL)
    {
        printf("%c - ", l->valore);
        l = l->next;
    }
}

int main(){
    char stringa[] = "{1+[2+3]*5}";
    bool errore = false;
    int cont = 0;
    int n;
    int lung = 0;
    int posizione_errore;
    Node_int* posizione_errore_node;
    Node* Head = NULL;
    Node* apertura_parentesi = NULL;
    Node* apertura_parentesi_singolo = NULL;
    Node_int* apertura_parentesi_posizione = NULL;
    Node_int* apertura_parentesi_posizione_singolo = NULL;
    Node* l;
    Node* elemento_aggiunto;
    for (int i = 0; i < strlen(stringa); i++){
        cont++;
        if (stringa[i] == '{' || stringa[i] == '[' || stringa[i] == '('){
            l = pop(&Head);
            if (l != NULL){
                if (l->valore == stringa[i]){
                    errore = true;
                    posizione_errore = cont;
                }else{
                    push(&Head, l);
                    elemento_aggiunto = (Node*)malloc(sizeof(Node));
                    elemento_aggiunto->valore = stringa[i];
                    push(&Head, elemento_aggiunto);
                    apertura_parentesi_singolo = (Node*)malloc(sizeof(Node));
                    apertura_parentesi_singolo->valore = stringa[i];
                    push(&apertura_parentesi, apertura_parentesi_singolo);
                    apertura_parentesi_posizione_singolo = (Node_int*)malloc(sizeof(Node_int));
                    apertura_parentesi_posizione_singolo->valore = cont;
                    push_int(&apertura_parentesi_posizione, apertura_parentesi_posizione_singolo);
                }
            }else{
                elemento_aggiunto = (Node*)malloc(sizeof(Node));
                elemento_aggiunto->valore = stringa[i];
                push(&Head, elemento_aggiunto);
                apertura_parentesi_singolo = (Node*)malloc(sizeof(Node));
                apertura_parentesi_singolo->valore = stringa[i];
                push(&apertura_parentesi, apertura_parentesi_singolo);
                apertura_parentesi_posizione_singolo = (Node_int*)malloc(sizeof(Node_int));
                apertura_parentesi_posizione_singolo->valore = cont;
                push_int(&apertura_parentesi_posizione, apertura_parentesi_posizione_singolo);
            }      
        }else{
           if (stringa[i] == '}' || stringa[i] == ']' || stringa[i] == ')'){
                l = pop(&Head);
                if (l != NULL){
                    if (!((l->valore == '{' && stringa[i] == '}') || (l->valore == '[' && stringa[i] == ']') || (l->valore == '(' && stringa[i] == ')'))){
                        errore = true;
                        posizione_errore = cont;
                    }else{
                        pop(&apertura_parentesi);
                        pop_int(&apertura_parentesi_posizione);
                    }
                }else{
                    errore = true;
                    posizione_errore = cont;
                    break;
                }      
            }  
        }
    }
    if (Head != NULL){
        errore = true;
        posizione_errore_node = pop_int(&apertura_parentesi_posizione);
        push_int(&apertura_parentesi_posizione, posizione_errore_node);
        posizione_errore = posizione_errore_node->valore;
    }
    if (errore)
        printf("Errore nella posizione: %d", posizione_errore);
    else
        printf("Corretto");
    free(Head);
    free(l);
    free(elemento_aggiunto);
    free(posizione_errore_node);
    free(apertura_parentesi);
    free(apertura_parentesi_singolo);
    free(apertura_parentesi_posizione);
    free(apertura_parentesi_posizione_singolo);
    return 0;
}