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
        while(fscanf(fp,"%d,%s,%s", &playlist[k].numero, playlist[k].titolo, playlist[k].artista)!=EOF){
            k++;
        }
    }

   

}