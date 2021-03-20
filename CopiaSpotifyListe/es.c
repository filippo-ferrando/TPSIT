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
    struct song* next;  //next element
}Song;

void read(Song* playlist, FILE *f, int *cnt){
    char* line = (char*)malloc(sizeof(char)*LUNG_P); //line for reading file (with fgets)

    while(fgets(line,LUNG_P,f)){
        playlist->num = 0;      //check the content of the variable is empty
        *playlist->author = "";
        *playlist->title = "";

        playlist->num = atoi(strtok(line,","));
        strcpy(playlist->title,(strtok(NULL,",")));
        strcpy(playlist->author,strtok(NULL,","));
        //playlist->author[strlen(playlist->author)] = '\0';
        //playlist("%s", playlist->author);
        
        playlist->next = (Song*)malloc(sizeof(Song));   //allocation of memory for the next list
        playlist->ind = *cnt;    //index of the list is random because you cant acces a item of the list without intercat with the previous one
        
        playlist = (playlist->next); //use the next item in the list

        *cnt += 1; //count of item in the list

        free(line); //to prevent overflow the line variable, disallocate and riallocate it
        line = (char*)malloc(sizeof(char)*100);
    }
}

Song* retriveSong(Song* playlist, int n){   // "navigate" to specificated item (n), and return it
    for(int k=0;k<n;k++){
        playlist=(playlist->next);
    }
    return playlist;
}

void randomSong(Song *playlist, int n){ //make the max value of the random index and then print it
    srand(time(NULL));


    int* vRand = (int*)malloc(sizeof(int)*n);
    Song* temp = (Song*)malloc(sizeof(Song)*n);
    temp = playlist;


    for(int k=0; k<n; k++){
        *(vRand + k) = rand()%n;
        for (int i = 0; i < k; i++)
        {
            if (*(vRand + k) == *(vRand + i))
            {
                k--;
                break;
            }
        }
    }

    for(int k=0; k<n;k++){
        temp = retriveSong(playlist, *(vRand + k));
        printf("%d. %s - %s", temp->num, temp->title, temp->author);
    }
}       

void rFree(Song* playlist){ //recursive function for deallocate the list
    if(playlist->next != NULL){
        rFree(playlist->next);
        free(playlist);
    }
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