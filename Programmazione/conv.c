/*
 * Prova d'esame di programmazione e laboratorio by Domenico Luciani aka DLion
 * 01/02/13 - 03:17
*/

#include <stdio.h>
#include <stdlib.h>

void convoluzione(int);

int main()
{
    int n;

    printf("Inserisci n: ");
    scanf("%d",&n);
    
    convoluzione(n);
    
    return 0;
}

void convoluzione(int n)
{
    int i,j;

    float *a = (float*)malloc(n*sizeof(float));
    float *b = (float*)malloc(n*sizeof(float));
    float *ris = (float*)malloc(n*sizeof(float));
    
    puts("--- Stampo an ---");
    for(i=1; i <= n; i++)
    {
        a[i-1] = (i+1.)*(i+1.);
        printf("%d: %2.2f ",i,a[i-1]);
    }

    puts("\n--- Stampo bn ---");
    for(i=1; i <= n; i++)
    {
        b[i-1] = 1./(i+2.);
        printf("%d: %2.2f ",i,b[i-1]);
    }

    puts("\n--- Stampo la convoluzione di an e bn ---");
    for(i=0; i < n; i++)
    {
        for(j=0; j <= i; j++)
            ris[i] += a[j] * b[i-j];
        printf("%d: %2.2f ",i+1,ris[i]);
    }

    putchar('\n');
    return;
}