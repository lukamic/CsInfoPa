#include <stdio.h>
#include <stdlib.h>

void scambia(int*,int*);
void stampa(int*,int);
void crea(int*,int);
void quicksort(int*,int,int);

int main()
{
    int num,*A;

    printf("Inserisci il numero di elementi nell'array: ");
    scanf("%d",&num);
    
    A = (int*) malloc(num * sizeof(int));

    crea(A,num);

    stampa(A,num);

    quicksort(A,num-1,0);

    stampa(A,num);

    return 0;
}

//Funzione per scambiare i con j
void scambia(int *i,int *j)
{
    int tmp = *i;

    *i = *j;

    *j = tmp;
}

void stampa(int *A,int num)
{
    int i;
    
    for(i=0; i < num; i++)
        printf("num %d: %d\n",i,A[i]);
}

void crea(int *A,int num)
{
    int i=0;

    for(i=0; i < num; i++)
    {
        printf("Inserisci il numero della posizione %d: ",i);
        scanf("%d",&A[i]);
    }
}

//A = Insieme, h = Hight, l = Low
void quicksort(int *A,int high,int low)
{
    int pivot = (A[high] + A[low]) / 2;
    int i=low,j=high,temp;

    do
    {
        while(A[i] < pivot)
            i++;
        while(A[j] > pivot)
            j--;

        if(i <= j)
        {
            scambia(&A[i],&A[j]);
            i++;
            j--;
        }
    }while(j >= i);

    if(low < j)
        quicksort(A,j,low);

    if(i < high)
        quicksort(A,high,i);
}