#include <stdio.h>
#include <stdlib.h>

struct El{
    int valore;
    struct El* next;
};

int is_empty(struct El *lista){
    if(lista == NULL) return 1;
    else return 0;
}

void stampa_lista(struct El *lista){
    if(is_empty(lista)){
        printf("lista vuota\n");
    }else{
        struct El *tmp = lista;
        printf("Numeri inseriti: \n");
        while (tmp!=NULL){
            printf("%d - %p\n", tmp->valore, tmp->next);
            tmp = tmp->next;
        }
    }
}
/*
void push(struct El ** lista, int valore){
    if(is_empty(*lista)){
        lista = (struct El*)malloc(sizeof(struct El));
        lista->valore = valore;
        lista->next = NULL;
    }else{
        while(lista->next!=NULL){
            lista = lista->next;
        }
        lista->next = (struct El*)malloc(sizeof(struct El));
        lista->next->valore = valore;
        lista->next->next = NULL;
    }
}
*/

void push(struct El **lista, int valore){
    if(is_empty(*lista)){
        struct El *tmp;
        *lista = tmp;
        tmp->next = NULL;
    }else{
        struct El * tmp;
        tmp = (struct El*)malloc(sizeof(struct El));

        tmp->valore = valore;
        tmp->next = *lista;
        *lista = tmp; 
    }
}

int main(){
    int n;

    struct El* lista;
    struct El* l;

    lista = NULL; //la lista creata potrebbe puntare a celle che già contengono dati, in questo modo si svuota il contenuto della cella
    l = NULL;

    do{
        printf("Inserisci un naturale o -1 per terminare: ");
        scanf("%d", &n);

        push(&lista, n);
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