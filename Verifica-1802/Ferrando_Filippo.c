#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct carta{
    char seme;      //seme della carta
    int numero;     //numero della carta
    struct carta *next; //prossimo elemento della pila
}Carta;

int isEmpty(Carta *head){
    if(head == NULL)
        return 1;
    else
        return 0;   
}

void push(Carta **head, Carta *element){
    if(isEmpty(*head)){  
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

Carta *pop(Carta **head){
    Carta *ret = *head;

    if(isEmpty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

void stampaPila(Carta** head){  //stampo la pila
    Carta *ret;
    ret=pop(head);
    while(ret!=NULL){   //ripeto finchè ci sono elementi
        printf("\n%d",ret->numero);
        printf(" - %c",ret->seme);
        free(ret);
        ret=pop(head);  //leggo il prossimo elemento
    }
}

void main(){
    Carta *head = NULL; //pila principale

    Carta *elemento = NULL; //elemento per caricare inizialmente le carte

    Carta *alice = NULL; //pila per la mano di bob
    Carta *bob = NULL; //pila per la mano di alice

    Carta *cartaData = NULL; //elemento per caricare le mani di alice e bob

    srand(time(NULL)); //randomizzo il seme del random

    for(int k=0; k<13; k++){                            //caricamento carte cuori
        elemento = (Carta*) malloc(sizeof(Carta));
        elemento->seme = 'C';
        elemento->numero = k+1;
        push(&head, elemento);
    }

    for(int k=0; k<13; k++){                            //caricamento carte picche
        elemento = (Carta*) malloc(sizeof(Carta));
        elemento->seme = 'P';
        elemento->numero = k+1;
        push(&head, elemento);
    }

    for(int k=0; k<13; k++){                             //caricamento carte denari
        elemento = (Carta*) malloc(sizeof(Carta));
        elemento->seme = 'D';
        elemento->numero = k+1;
        push(&head, elemento);
    }

    for(int k=0; k<13; k++){                            //caricamento carte fiori
        elemento = (Carta*) malloc(sizeof(Carta));
        elemento->seme = 'F';
        elemento->numero = k+1;
        push(&head, elemento);
    }

    while(!isEmpty(head)){  //ciclo finchè la pila continene elementi
        if(rand()%2 == 1){//scielgo radomicamente quale sarà il primo giocatore a ricevere la carta
            //printf("1");
            cartaData = (Carta*) malloc(sizeof(Carta)); //alloco lo spazio per caricare la carta
            
            cartaData = pop(&head); //carico la carta dalla pila principale nell'elemento
            push(&bob, cartaData); //pusho la carta dall'elemento alla pila 

            cartaData = pop(&head); //stesso di sopra
            push(&alice, cartaData);
        }else{
            //printf("2");
            cartaData = (Carta*) malloc(sizeof(Carta));
            
            cartaData = pop(&head);
            push(&alice, cartaData);

            cartaData = pop(&head);
            push(&bob, cartaData);
        }
    }

    //stampaPila(&head);
    stampaPila(&alice); //stampo la mano di alice
}