#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct nodo{
    char valore;
    struct nodo *next;
}Nodo;

int isEmpty(Nodo *head){
    if(head == NULL)
        return 1;
    else
        return 0;   
}

void push(Nodo **head, Nodo *element){
    if(isEmpty(*head)){     //= if(isEmpty(*head) == 0)
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

Nodo *pop(Nodo **head){
    Nodo *ret = *head;

    if(isEmpty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

void main(){
    char stringa[100];
    Nodo *head = NULL;
    Nodo *pila = NULL;
    Nodo *appoggio = NULL;
    bool ok = true;

    char controllo[6] = ")(][}{";

    printf("inserisci una stringa: ");
    scanf("%s", stringa);

    for(int k = 0; stringa[k] != '\0' && ok == true; k++){
        if(stringa[k] == '(' || stringa[k] == '[' || stringa[k] == '{'){
            push(&head, pila);
        }

        if(stringa[k] == ')' || stringa[k] == ']' || stringa[k] == '}'){
            if(pop(&pila) != controllo[stringa[k]] || strlen(pila) == 0){
                ok = true;
            }
        }
        ok = false;
    }

    if (ok)
        printf("Espressione corretta");
    else
        printf("espressione errata");
}