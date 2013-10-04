/*
 * Compito d'esame:
 * Autore: Domenico Luciani
 * Scrivere un programma che legga da tastiera una mat rice quadrata binaria. 
 * Scrivere una funzione in C che stabilisca se la matrice è costituita da cornici di zero che si 
 * alternano rispettivamente a partire dalla cornice esterna composta da tutti zero.
 * Es: Le matrici 
 * 1 1 1 1 1 1 1 e 0 0 0 0 0
 * 1 0 0 0 0 0 1   0 1 1 1 0
 * 1 0 1 1 1 0 1   0 1 1 1 0
 * 1 0 1 1 1 0 1   0 0 0 0 0
 * 1 0 0 0 0 0 1
 * 1 1 1 1 1 1 1
 * La prima non è di questo tipo, la seconda lo è. 
 */

#include <stdio.h>
#include <stdlib.h>

void stampa_M(int **M,int g)
{
    int i,j;

    puts("\n -- Stampa --");
    for(i=0; i < g; i++)
    {
        for(j=0; j < g; j++)
            printf("%d ",M[i][j]);
        putchar('\n');
    }
    puts(" -- Fine Stampa --");
}

int controlla(int **M,int inizio,int g,int flag)
{
    int i,j;

    if(inizio == g-1 && flag == M[inizio][g-1])
        return 0;

    for(i=inizio,j=inizio; i <= g-1, j<=g-2; i++,j++)
        if(M[inizio][i] != M[g-1][i] || M[inizio][i] != flag && M[j][inizio] != M[j][g-1] || M[j][inizio] != flag)
            return 1;

    if(controlla(M,inizio+1,g-1,!flag) == 0)
        return 0;
}

int main()
{
    int grande,
        i,j;
    int **M;

    printf("Quanto deve essere grande la matrice?\nRis: ");
    scanf("%d",&grande);
    
    M = (int**)malloc(grande*sizeof(int*));

    for(i=0;i < grande; i++)
    {
        M[i] = (int*)malloc(grande*sizeof(int));
        for(j=0; j < grande; j++)
        {
            printf("Inserisci[%d][%d]: ",i,j);
            scanf("%d",&M[i][j]);
            if(M[i][j] != 0 && M[i][j] != 1)
            {
                printf("Deve essere una matrice binaria!\n");
                return -1;
            }
        }

    }

    stampa_M(M,grande);

    if(controlla(M,0,grande,0) == 1)
        puts("La matrice NON è costituita da una cornice di 0 alternati ad 1");
    else
        puts("La matrice e' costituita da una cornice di 0 alternati ad 1");

    return 0;
}