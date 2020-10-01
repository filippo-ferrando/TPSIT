#include <stdlib.h>
#include <stdio.h>

#define N 21 //numero persone in classe
#define DIM 100

void main()
{
    float R;      //costante aumento contagi
    float x;      //persone contagiate
    float v[DIM]; //vettore di salvataggio
    int k = 0;

    printf("inserisci R: ");
    scanf("%f", &R);

    x = 1;

    do
    { //calcolo contagi
        x = x * R;
        v[k] = x;
        k++;

    } while (x < (float)N);

    for (int j = 0; j < k; j++)
    { //visualizzazione vettore
        printf("%f\n", v[j]);
    }

    printf("\n%d giorni \n", k);
}