#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define LUNG 30
#define DIM 50
#define LUNG_P 200

typedef struct canzone
{ //struttura canzone, suddivisoine file csv
    int numero;
    char titolo[LUNG];
    char artista[LUNG];
} Canzone;

void randomSong(Canzone songs[], int n)
{ //prende il contenuto della struttura playlist e lo carica rndomizzato in un vettore, poi lo stampa
    int k, i, j;

    srand(time(NULL));
    int vetRand[DIM];

    for (int k = 0; k < n; k++)
    {
        vetRand[k] = rand() % n;
        for (int i = 0; i < k; i++)
        {
            if (vetRand[k] == vetRand[i])
            {
                k--;
                break;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        printf("%d %s  %s\n", songs[vetRand[k]].numero, songs[vetRand[k]].titolo, songs[vetRand[k]].artista);
    }
}

int dimVett(FILE *file){
    file = fopen("canzoni.csv","r");

    char riga[LUNG_P];
    int k = 0;

    int *n_righe;

    if(file==NULL){
        printf("Il file non esiste");
    }else{
        while(fgets(riga, LUNG_P, file)){
            k++;
        }

    }
    n_righe = (int*)malloc(k*sizeof(Canzone));

    return *n_righe;
}

void main()
{
    int k = 0;
    char nFile[] = "canzoni.csv";
    char linea[LUNG_P];
    int dimPlaylist;
    
    FILE *fp;
    fp = fopen(nFile, "r");

    dimPlaylist = dimVett(fp);

    Canzone playlist[dimPlaylist];
    
    
    if (fp == NULL)
    {
        printf("File non trovato");
    }
    else
    {
        while (fgets(linea, LUNG_P, fp))
        {
            playlist[k].numero = atoi(strtok(linea, ","));
            strcpy(playlist[k].titolo, strtok(NULL, ","));
            strcpy(playlist[k].artista, strtok(NULL, "\n"));
            k++;
        }
        randomSong(playlist, k);
    }
}