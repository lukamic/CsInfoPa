/*
 * Sommare gli elementi di un vettore A con puntatori e funzioni ricorsive.
 * Domenico Luciani aka DLion anno 2013 Facoltà di Scienze Informatiche, 1° anno.
 * 20/02/2013
 */

#include <stdio.h>
#include <stdlib.h>

void stampa(int*,int);
int somma(int*,int);

int main()
{
    int *A,num,i;
    
    printf("Quanti elementi vuoi inserire ?\nRisposta: ");
    scanf("%d",&num);

    A = (int*)malloc(num*sizeof(int));

    printf("- Inserisci gli elementi dell'array -\n");
    
    for(i=0; i < num; i++)
    {
        printf("Valore %d: ",i);
        scanf("%d",&A[i]);
    }

    stampa(A,num);

    //Mettiamo num-1 perché così non inizia da num ma da num - 1 dato che un array va da 0 ad n-1
    printf("La somma degli elementi del vettore A e': %d\n",somma(A,num-1));

    return 0;
}

void stampa(int *A,int num)
{
    int i;
    for(i=0; i < num; i++)
        printf("Pos %d: %d\n",i,A[i]);
}

int somma(int *A,int num)
{
    if(!num)
        return A[num];
    else
        return A[num] + somma(A,num-1);
}