#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/*
CAMPI FILE CSV

data,
stato,
codice_regione,
denominazione_regione,
lat,
long,
ricoverati_con_sintomi,
terapia_intensiva,
totale_ospedalizzati,
isolamento_domiciliare,
totale_positivi,
variazione_totale_positivi,
nuovi_positivi,
dimessi_guariti,
deceduti,
casi_da_sospetto_diagnostico,
casi_da_screening,
totale_casi,
tamponi,
casi_testati
*/

#define LUNG 25
#define SIZE 1000
#define TOP 3

typedef struct regione
{
    char data[LUNG];
    char stato[LUNG];
    int codice_regione;
    char denominazione_regione[LUNG];
    float latitudine;
    float longitudine;
    int ricoverati_con_sintomi;
    int terapia_intensiva;
    int totale_ospedalizzati;
    int isolamento_domiciliare;
    int totale_positivi;
    int variazione_totale_positivi;
    int nuovi_positivi;
    int dimessi_guariti;
    int deceduti;
    int casi_da_sospetto_diagnostico;
    int casi_da_screening;
    int totale_casi;
    int tamponi;
    int casi_testati;
    bool controllato;
} Regione;

void TopRegioniTerapiaIntensiva(Regione *regioni, int dim) //trova il massimo e stampa anche i 2 prima
{
    int k, i;
    int max;
    int *vet = (int *)malloc(TOP * sizeof(int));
    Regione temp;

    for (k = 0; k < TOP; k++)
    {
        max = 0;
        for (i = 0; i < dim; i++)
        {
            if ((regioni + max)->terapia_intensiva < (regioni + i)->terapia_intensiva)
            {
                if ((regioni + i)->controllato == false)
                {
                    max = i;
                }
            }
        }
        (regioni + max)->controllato = true;
        *(vet + k) = max;
        printf("\n%s: %d", (regioni + max)->denominazione_regione, (regioni + max)->terapia_intensiva);
    }
    for (i = 0; i < TOP; i++)
    {
        (regioni + *(vet + i))->controllato = false;
    }
    free(vet);
}

void SommaCasiTerapiaIntensiva(Regione *regioni, int dim) //somma casi
{
    int somma = 0;
    for (int j = 0; j < dim; j++)
    {
        somma += (regioni + j)->terapia_intensiva;
    }
    printf("\n%d", somma);
}

void TopRegioniMenoCasi(Regione *regioni, int dim) //trova il massimo tra il numero dei contagi delle regioni estampa anche i 2 prima
{
    int k, i;
    int max;
    int *vet = (int *)malloc(TOP * sizeof(int));
    Regione temp;

    for (k = 0; k < TOP; k++)
    {
        max = 0;
        for (i = 0; i < dim; i++)
        {
            if ((regioni + max)->totale_casi > (regioni + i)->totale_casi)
            {
                if ((regioni + i)->controllato == false)
                {
                    max = i;
                }
            }
        }
        (regioni + max)->controllato = true;
        *(vet + k) = max;
        printf("\n%s: %d", (regioni + max)->denominazione_regione, (regioni + max)->totale_casi);
    }

    for (i = 0; i < TOP; i++)
    {
        (regioni + *(vet + i))->controllato = false;
    }
    free(vet);
}

void main()
{
    FILE *fp;
    Regione *regioni;
    char *buffer = (char *)malloc(SIZE * sizeof(char));
    int k = 0;
    if ((fp = fopen("data.csv", "r")) == NULL)
    {
        printf("File non esistente");
    }
    else
    {
        while (fgets(buffer, SIZE, fp))
        {
            k++;
        }

        fclose(fp);
        fp = fopen("data.csv", "r");
        regioni = (Regione *)malloc(k * sizeof(Regione));
        k = 0;

        while (fgets(buffer, SIZE, fp))
        {
            strcpy((regioni + k)->data, strtok(buffer, ",")); //strtok per l'estrapolazione dalla stringa del file
            strcpy((regioni + k)->stato, strtok(NULL, ","));
            (regioni + k)->codice_regione = atoi(strtok(NULL, ","));
            strcpy((regioni + k)->denominazione_regione, strtok(NULL, ","));
            (regioni + k)->latitudine = atof(strtok(NULL, ","));
            (regioni + k)->longitudine = atof(strtok(NULL, ","));
            (regioni + k)->ricoverati_con_sintomi = atoi(strtok(NULL, ","));
            (regioni + k)->terapia_intensiva = atoi(strtok(NULL, ","));
            (regioni + k)->totale_ospedalizzati = atoi(strtok(NULL, ","));
            (regioni + k)->isolamento_domiciliare = atoi(strtok(NULL, ","));
            (regioni + k)->totale_positivi = atoi(strtok(NULL, ","));
            (regioni + k)->variazione_totale_positivi = atoi(strtok(NULL, ","));
            (regioni + k)->nuovi_positivi = atoi(strtok(NULL, ","));
            (regioni + k)->dimessi_guariti = atoi(strtok(NULL, ","));
            (regioni + k)->deceduti = atoi(strtok(NULL, ","));
            (regioni + k)->casi_da_sospetto_diagnostico = atoi(strtok(NULL, ","));
            (regioni + k)->casi_da_screening = atoi(strtok(NULL, ","));
            (regioni + k)->totale_casi = atoi(strtok(NULL, ","));
            (regioni + k)->tamponi = atoi(strtok(NULL, ","));
            (regioni + k)->casi_testati = atoi(strtok(NULL, "\n"));
            (regioni + k)->controllato = false;
            k++;
        }
        printf("Totale dei ricoverati in terapia intensiva:");
        SommaCasiTerapiaIntensiva(regioni, k);

        printf("\n\nTop 3 delle regioni per numero di ricoveri in terapia intensiva:");
        TopRegioniTerapiaIntensiva(regioni, k);

        printf("\n\nTop 3 delle regioni con meno casi totali positivi:");
        TopRegioniMenoCasi(regioni, k);
    }
    free(regioni); //free memory
    free(buffer);
}