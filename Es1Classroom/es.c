#include <stdio.h>
#include <stdlib.h>

struct El{
    int valore;
    struct El* next;
};

int is_empty(struct El *head){
    if(head == NULL) return 1;
    else return 0;
}

void stampa_lista(struct El *head){
    if(is_empty(head)){
        printf("lista vuota\n");
    }else{
        struct El *tmp = head;
        while (tmp!=NULL){
            printf("Numeri inseriti: \n");
            printf("%d - %p", tmp->valore, tmp->next);
            tmp = tmp->next;
        }
    }
}

void push(struct El **head, struct El *valore){
    if(is_empty(*head)){
        *head = valore;
        valore->next = NULL;
    }else{
        valore->next = *head;
        *head = valore;
    }
}

int main(){
    int n;

    struct El* lista;
    struct El* l;

    lista = NULL; //la lista creata potrebbe puntare a celle che già contengono dati, in questo modo si svuota il contenuto della cella

    do{
        printf("Inserisci un naturale o -1 per terminare: ");
        scanf("%d", &n);

        push(lista, n);
        /*
        if(n>=0){
            if(lista == NULL){//controlla se la lista contiene dati o meno
                //alloca dinamicamente lo spazio per lista
                lista = (struct El*)malloc(sizeof(struct El));
                l=lista;
            }else{ //se la lista non è vuota
                l->next = (struct El*)malloc(sizeof(struct El)); //se la lista non è vuota scorro la lista
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
        */
    }while(n>=0);

    l = lista; //ritorno al prima elemento nella lista
    /*
    printf("Numeri inseriti: \n");
    
    while(l!=NULL){
        printf("%d - %p \n", l->valore, l->next);
        l=l->next;//stampo i valori della lista, dopodichè passo alla lista successiva
    }
    */
   stampa_lista(l);

    printf("\n");
    return 0;
}