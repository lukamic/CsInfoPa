#include <stdio.h>
#include <stdlib.h>

int accoppiata(int **M,int g)
{
    int n,i,
        somma_r = 0,
        somma_c = 0;

    for(n=0; n < g; n++)
    {
        for(i=0; i < g; i++)
        {
            somma_r += M[n][i];
            somma_c += M[i][n];
        }

        if(somma_r % 2 == 0)
            if(somma_c % 2 != 0)
                return 1;
    }

    return 0;
}

int main()
{
    int **M;
    int i,j,n;

    printf("Inserisci la grandezza della matrice: ");
    scanf("%d",&n);

    M = (int**)malloc(n*sizeof(int*));

    for(i=0; i < n; i++)
    {
        M[i] = (int*)malloc(n*sizeof(int));
        for(j=0; j < n; j++)
        {
            printf("Elemento [%d][%d]: ",i,j);
            scanf("%d",&M[i][j]);
        }
    }

    if(!accoppiata(M,n))
        puts("La matrice E' accoppiata");
    else
        puts("La matrice NON e' accoppiata");

    return 0;
}