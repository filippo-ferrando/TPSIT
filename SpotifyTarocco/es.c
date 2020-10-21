#include <stdlib.h>
#include <stdio.h>

#define LUNG 50
#define MAXSONG 10

typedef struct canzone{
    int numero;
    char titolo[LUNG];
    char artista[LUNG];
}Canzone;



void main(){
    int k=0;

    Canzone playlist[MAXSONG];

    FILE *fp;

    fopen("canzoni.csv","r");

    if(fp==NULL){
        printf("File non trovato");
    }else{
        for(k=0;k<MAXSONG;k++){


        }
    }

   

}