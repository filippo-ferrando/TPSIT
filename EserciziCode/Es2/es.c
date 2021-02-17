#include <stdio.h>
#include <stdlib.h>

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

void push(struct queue_node **head, struct queue_node *element){
    if(isEmpty(*head)){  
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }
}

struct queue_node *pop(struct queue_node **head){
    struct queue_node *ret = *head;

    if(isEmpty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}

struct queue_node * dequeue(struct queue_node **head, struct queue_node **tail){
    struct queue_node *ret = *head;

    if(isEmpty(*head))
        return NULL;
    else
        *head = ret->next;

    if(*head==NULL)
        *tail = NULL;

    return ret;
}

void main(){
    struct queue_node *head = NULL;
    struct queue_node *tail = NULL;
    struct queue_node *ret = NULL;

    struct queue_node *pila = NULL;
    struct queue_node *headPila = NULL;

    int valore;

    do{
        printf("Inserisci valore: ");
        scanf("%d",&valore);

        ret = (struct queue_node*) malloc(sizeof(struct queue_node));
        ret->val = valore;        

        push(&headPila, ret);

    }while(valore != -1);

    while(isEmpty(headPila) == 0){
        enqueue(&head, &tail, pop(&headPila));
    }

    while(isEmpty(head) == 0){
        printf("%d\n", (dequeue(&head, &tail))->val);
    }

}