#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int dato;
    struct lista *next;
}lista;

lista* crea(lista* p,int n)
{
    if(p == NULL)
    {
        p = (lista*)malloc(sizeof(lista));
        p->dato = n;
        p->next = NULL;
    }
    else
        p->next = crea(p->next,n);

    return p;
}


lista* domanda(lista *p)
{
    int n;

    do
    {
        printf("Inserisci : ");
        scanf("%d",&n);

        if(n > 0)
            p = crea(p,n);
    }while(n > 0);

    return p;
}

void stampo(lista *p)
{
    if(p != NULL)
    {
        printf("%d -> ",p->dato);
        stampo(p->next);
    }
    else
        printf("NULL ");
}

lista* copia(lista *P, lista *Q, int *i)
{
    lista *temp=NULL;

    if(P == NULL)
    {
        P = Q;
    }
    else
    {
        if(Q != NULL)
        {
            if((*i) == 2)
            {
                temp = P->next;
                P->next = Q;
                (*i) = 1;
                Q->next = copia(temp,Q->next,i);
            }
            else
            {
                (*i)++;
                P->next = copia(P->next,Q,i);
            }
        }
    }
    return P;
}


int main()
{
    int n,
        i=1;
    lista *Q=NULL,
          *P=NULL;


    printf("-- P --\n");
    P = domanda(P);
    printf("-- Q --\n");
    Q = domanda(Q);

    printf("-- STAMPO P --\n");
    stampo(P);
    printf("\n-- STAMPO Q --\n");
    stampo(Q);

    P = copia(P,Q,&i);

    printf("\n-- STAMPO COPIA --\n");
    stampo(P);

    return 0;
}