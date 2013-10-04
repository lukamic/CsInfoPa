#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 100

void randomico(int *A)
{
    int i;
    srand(time(NULL));
    
    for(i=0; i < DIM; i++)
        A[i] = rand() % 1000;
}

void stampa(int *A)
{
    int i;

    puts("\n- INIZIO STAMPA -");

    for(i=0; i < DIM; i++)
        printf("%d: %d\n",i,A[i]);

    puts("\n- FINE STAMPA -");
}

void scambia(int *i,int *j)
{
    int temp;

    temp = *i;
    *i = *j;
    *j = temp;
}

void ordina(int *A)
{
    int i,f,pos,p;

    puts("\n- INIZIO ORDINAMENTO -");

    do
    {
        f=0;
        for(i=0; i < DIM-1; i++)
        {
            if(A[i] > A[i+1])
            {
                scambia(&A[i],&A[i+1]);
                f=1;
                p=i+1;
            }
        }
        pos = p;
    }while(f && pos > 1);

    puts("\n- FINE ORDINAMENTO -");
}

int main()
{
    int array[DIM];

    randomico(array);

    stampa(array);

    ordina(array);

    stampa(array);

    return 0;
}