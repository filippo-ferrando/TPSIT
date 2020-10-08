#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG 100

void printRLE(char str[])
{
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
 
        // Count occurrences of current character
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
 
        // Print character and its count
        printf("%d%c", count, str[i]);
    }
}

void decodeRLE(char str[]){

    //scroll the string
    for(int k=0; str[k] != '\0'; k++){
        //see if its a character
        if(str[k] >= '0' && str[k] <= '9'){
            //print x time the character
            for(int j=1; j<(str[k]-48); j++){

                printf("%c", str[k+1]);
            }
        }else{
            printf("%c", str[k]);
        }
    }
    
}
 
void main(){
    char str[LUNG];
    int scelta;

    printf("Decoding o Encoding? (0)(1): ");
    fflush(stdin);
    scanf("%d", &scelta);
    if(scelta == 0){
        //Decoding
        printf("inserisci stringa: ");
        fflush(stdin);
        scanf("%s", str);
        decodeRLE(str);
    }else{
        if(scelta == 1){
            //Encoding
            printf("inserisci stringa: ");
            scanf("%s", str);
            printRLE(str);
        }
        
    }
}

