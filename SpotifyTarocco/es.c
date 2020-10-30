#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct canzone{
    int numero;
    char titolo[100];
    char artista[100];
}Canzone;

/*
void leggiFile(Canzone playlist[],FILE *fp, int *cnt){
    char lettera;
    char parola[100];
    int indice=0;

    while(fscanf(fp,"%c",&lettera)!=EOF){
        if(lettera==','){
            parola[strlen(parola)]='\0';

            switch(indice){
                case 0:
                    playlist[*cnt].numero=(*cnt)+1;
                    break;
                case 1:
                    strcpy(playlist[*cnt].titolo, parola);
                    break;
                case 2:
                    strcpy(playlist[*cnt].artista, parola);
                    break;
            }

            indice=(indice+1)%3;
            memset(&parola[0],0,sizeof(parola));
            if(indice==0)
                *cnt = *cnt +1;
            }else{
                parola[strlen(parola)] = lettera;
            }
        }
        return;
}

*/



void main(){
    int k=0;

    Canzone playlist[50];

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

while(fgets(buffer,BSIZE,fp)){

}ù

//strdup copia stringa
