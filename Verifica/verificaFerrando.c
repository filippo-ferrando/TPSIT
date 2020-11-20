#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define LUNG 100
#define MAXSIZE 1000

typedef struct anomalia{ //struct gestione file errori
    int tempo;
    char errore[LUNG];
}Anomalia;

typedef struct voloDrone{ //struct gestione file log di volo
    int tempo;
    float lati;
    float longi;
}voloDrone;

void confronto(Anomalia *anomalie, voloDrone *volo, int k, int j){ //confronto le date delle 2 struct per trovare coordinate errore
    for(int i=0;i<k;i++){
        for(int d=0;d<j;d++){
            if((volo + d)->tempo == (anomalie + i)->tempo){
            printf("anomalia verificata, coordinate: \n");
            printf("latitudine: %f\n", (volo + i)->lati);
            printf("longitudine: %f\n", (volo + i)->longi);
            printf("Tipo errore: %s\n", (anomalie + i)->errore);
            }
        }
    }
}

void main(){
    FILE *fErrori, *fVolo; //dichiaro puntatori file
    
    Anomalia *anomalie; //dichiaro puntatori struct
    voloDrone *volo;

    char *buffer = (char *)malloc(MAXSIZE * sizeof(char));  //dichiaro e alloco memoria per buffer lettura file;
    char *buffer1 = (char *)malloc(MAXSIZE * sizeof(char));

    int k=0, j=0;   //contatori per la dimensione

    if((fErrori = fopen("Anomalie_drone.csv","r")) == NULL){
        printf("il file non esiste");
    }else{
        while(fgets(buffer, MAXSIZE, fErrori)){ //calcolo dimensione vettore anomalie
            k++;
        }
        fclose(fErrori);
        fErrori = fopen("Anomalie_drone.csv","r");
        anomalie = (Anomalia *)malloc(k * sizeof(Anomalia)); //alloco spazio ad anomalie
        k=0;

        fgets(buffer, MAXSIZE, fErrori);
        *(buffer+0) = 0;
        while(fgets(buffer, MAXSIZE, fErrori)){
            (anomalie +k)->tempo = atoi(strtok(buffer, ","));   //lettura del file tramite fgets
            strcpy((anomalie + k)->errore, strtok(NULL, ","));
            k++;
        }
    }


    if((fVolo = fopen("Volo_drone.csv","r")) == NULL){
        printf("il file non esiste");
    }else{
        while(fgets(buffer1, MAXSIZE, fVolo)){ //calcolo spazio per vettore volo
            j++;
        }
        fclose(fVolo);
        fVolo = fopen("Volo_drone.csv","r");
        volo = (voloDrone *)malloc(j * sizeof(voloDrone)); //alloco spazione per vettore volo
        j=0;

        fgets(buffer1, MAXSIZE, fVolo);
        *(buffer1+0) = 0;
        while(fgets(buffer1, MAXSIZE, fVolo)){
            (volo + j)->tempo = atoi(strtok(buffer1, ",")); //lettura file tramite fgets
            (volo + j)->lati = atof(strtok(NULL, ","));
            (volo + j)->longi = atof(strtok(NULL, ","));
            j++;
        }
        confronto(anomalie, volo, k, j);    //chiamata procedura

    }
    free(buffer);   //disalloco spazione di buffer, buffer1, volo, anomalie
    free(buffer1);
    free(volo);
    free(anomalie);

}