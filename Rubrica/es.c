#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM_CONTATTI 1024

struct contatto{
    int id;
    char nome[64];
    char numero[16];
};

struct rubrica{
    int num_inseriti;
    struct contatto db[MAX_NUM_CONTATTI];
};

int inserisci(struct rubrica *r, char *nome, char *numero){
    struct contatto *p;
    if(r->num_inseriti == MAX_NUM_CONTATTI){
        printf("Rubrica piena");
        return -1;
    }
    p = &r->db[r->num_inseriti];

    strcpy(p->nome, nome);
    strcpy(p->numero, numero);
    p->id = r->num_inseriti;
    r->num_inseriti++;
    return 0;
}

char *trova_numero_da_nome(struct rubrica *r, char *nome){
    int i;
    struct contatto *p;

    for(i=0;i<MAX_NUM_CONTATTI;i++){
        if(i==r->num_inseriti)
            break;
        p=&r->db[i];

        if(strcmp(p->nome, nome) == 0)
            return p->numero;
    }
    return NULL;
}

void stampa_rubrica(struct  rubrica *r){
    int i;
    struct contatto *p;

    printf("\nStampa rubrica; %d contatti\n", r->num_inseriti);

    for(i=0;i<MAX_NUM_CONTATTI;i++){
        if(i==r->num_inseriti)
            break;
        p = &r->db[i];

        printf("&s, %s\n", p->nome, p->numero);
    }
}
