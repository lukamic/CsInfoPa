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



void stampa_spirale(int **M,int inizio,int g)
{
    int i,j;
    
    
    for(i=inizio; i <= g-1; i++)
        printf("%d ",M[inizio][i]);
    for(j=inizio+1; j <= g-1; j++)
        printf("%d ",M[j][g-1]);
    for(i=g-2; i >= inizio; i--)
        printf("%d ",M[g-1][i]);
    for(j=g-2; j> inizio; j--)
        printf("%d ",M[j][inizio]);
    
    if(inizio == g-1)
        return;
    else
        stampa_spirale(M,inizio+1,g-1);
}

int main()
{
    int **M,
        grande,
        i,j;
     
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
         }
          
     }

    stampa_M(M,grande);

    stampa_spirale(M,0,grande);
    putchar('\n');
    return 0;
}