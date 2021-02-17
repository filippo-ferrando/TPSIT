#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

struct queue_node{
    struct queue_node *next;
    int val;
};


int isEmpty(struct queue_node *head){
    if(head == NULL)
        return 1;
    else
        return 0;   
}

void enqueue(struct queue_node **head, struct queue_node **tail, struct queue_node *element){
    if(isEmpty(*head))
        *head = element;
    else
        (*tail)->next = element;

    *tail = element;
    element->next = NULL;
}

struct queue_node *dequeue(struct queue_node **head, struct queue_node **tail){
    struct queue_node *ret = *head;

    if(isEmpty(*head))
        return NULL;
    else
        *head = ret->next;

    if(*head == NULL)
        *tail = NULL;
    
    return ret;
}

void push(struct queue_node **head, struct queue_node **tail, struct queue_node *element){
    enqueue(head, tail, element); 
}

struct queue_node *pop(struct queue_node **head, struct queue_node **tail){
    struct queue_node *ret = (struct queue_node*) malloc(sizeof(struct queue_node));
    struct queue_node *testa=NULL;
    struct queue_node *fondo=NULL;
    struct queue_node* rinfila=NULL;
    if(!isEmpty(*head)){
        do{ 
            ret = dequeue(head, tail);// (tail) D c b a (head) | NULL --->  D c b | a -->  c D |  (tail) b a (head) --> D | c b a---> NULL | a b c ret= D
            if(!isEmpty(*head)){
                push(&testa, &fondo, ret);
            }
        }while(!isEmpty(*head));

        *head=testa;
        *tail=fondo;
        return ret;
    }
    *tail=NULL;
    return NULL;
    
}

int main(){
    struct queue_node *head = NULL;
    struct queue_node *element = NULL;
    struct queue_node *tail = NULL;

    do{
        element = (struct queue_node*) malloc(sizeof(struct queue_node));

        printf("Inserisci il numero: ");
        scanf("%d", &element->val);
        
        push(&head, &tail, element);


    }while(element->val != -1); //fino a quando la risposta è s o S carico numeri

    while(!isEmpty(head)){  //fino a quando la coda ha elementi
        printf("n: %d ", pop(&head, &tail)->val);   //stampa
    }

    return 0;
}