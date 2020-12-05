#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define LUNG 50
#define DIM 50
#define LUNG_P 200
#define MAX_RAND 700

typedef struct song{
    int num;
    char author[LUNG];
    char title[LUNG];
    int ind;
    struct song* next;
}Song;

void read(Song* playlist, FILE *f, int *cnt){
    char* line = (char*)malloc(sizeof(char)*100);
    Song* temp = playlist;

    while(fgets(line,LUNG_P,f)){
        temp->num = atoi(strtok(line,","));
        strcpy(temp->author,(strtok(NULL,",")));
        strcpy(temp->title,(strtok(NULL,",")));

        temp->next = (Song*)malloc(sizeof(Song));
        temp->ind = rand()%MAX_RAND;
        temp = (temp->next);

        *cnt++;

        free(line);
        line = (char*)malloc(sizeof(char)*100);
    }
    free(temp);
    return;
}

Song* retriveSong(Song* playlist, int n){
    Song* temp = playlist;
    for(int k=0;k<n;k++){
        temp=(temp->next);
    }
    return temp;
}

void randomSong(Song *playlist, int n){
    int max, pMax;

    Song* temp;

    for(int i=0;i<n;i++){
        temp=playlist;
        pMax=0;
        max = temp->ind;

        for(int k=0;k<n;k++){
            if(max < temp->ind){
                max = temp->ind;
                pMax = k;
            }
            temp = temp->next;
        }

        temp = retriveSong(playlist, pMax);
        printf("%d. %s - %s\n", temp->num, temp->title, temp->author);
        temp->ind = -1;    
    }
    return;
}       

void rFree(Song* playlist){
    if(playlist->next != NULL){
        rFree(playlist->next);
        free(playlist);
    }
    return;
}


void main(){
    srand(time(NULL));

    FILE *f;
    
    if((f=fopen("canzoni.csv","r"))==NULL){
        printf("FILE NON ESISTENTE");
    }else{
        int k=0;
        Song* playlist = (Song*)malloc(sizeof(Song));
        read(playlist,f,&k);

        fclose(f);
        randomSong(playlist,k);
        rFree(playlist);
    }
    
}