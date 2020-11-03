#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define LUNG 30
#define DIM 50
#define LUNG_P 200

typedef struct canzone{     //struttura canzone, suddivisoine file csv
    int numero;
    char titolo[LUNG];
    char artista[LUNG];
}Canzone;

void randomSong(Canzone playlist[], int n){ //prende il contenuto della struttura playlist e lo carica rndomizzato in un vettore, poi lo stampa
    int k, i, j;
    
    srand(time(NULL));
    int vetRand[DIM];

    for(k=0;k<n;k++){
        vetRand[k]=rand()%n;
        for(i=0;i<k;i++){
            if(vetRand[k] == vetRand[i]){
                k--;
                break;
            }  
        }
    }
    for(j=0;j<n;j++){
        printf("%d %s  %s\n", playlist[vetRand[k]].numero, playlist[vetRand[k]].titolo, playlist[vetRand[k]].artista);
    }

}

void main(){
    int k=0;
    Canzone playlist[DIM];
    char nFile[] = "canzoni.csv";
    FILE *fp;
    fp = fopen(nFile,"r");
    char linea[LUNG_P];

    if(fp==NULL){
        printf("File non trovato");
    }else{
        while(fgets(linea,LUNG_P,fp)){
            playlist[k].numero=atoi(strtok(linea,","));
            strcpy(playlist[k].titolo,strtok(NULL,","));
            strcpy(playlist[k].artista,strtok(NULL,"\n"));
            k++;
        }
        randomSong(playlist,k);
    }
}