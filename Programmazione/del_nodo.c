#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct ABR
{
    int label;
    struct ABR *sx,*dx;
}ABR;

ABR* crea_abr(ABR *p, int n)
{
    if(p == NULL)
    {
        p = (ABR*)malloc(sizeof(ABR));
        p->label = n;
        p->sx = p->dx = NULL;
    }
    else
    {
        if(n > p->label)
            p->dx = crea_abr(p->dx,n);
        else
            p->sx = crea_abr(p->sx,n);
    }

    return p;
}

void stampa_abr(ABR *p)
{
    if(p != NULL)
    {
        stampa_abr(p->sx);
        printf("%d -> ",p->label);
        stampa_abr(p->dx);
    }
}

ABR* scorri(ABR *p, ABR *q)
{
    if(p == NULL)
        p = q;
    else
    {
        if(q->label > p->label)
            p->dx = scorri(p->dx,q);
        else
            p->sx = scorri(p->sx,q);
    }

    return p;
}

ABR *del_nodo(ABR *p,int n)
{
    ABR *temp = NULL;

    if(p != NULL)
    {
        if(p->label == n)
        {
            temp = p;

            if(p->dx == NULL && p->sx == NULL)
                p = NULL;
            else
            {
                if(p->dx != NULL && p->sx == NULL)
                    p = p->dx;
                else if(p->sx != NULL && p->dx == NULL)
                    p = p->sx;
                else
                {
                    p = p->sx;
                    if(p->sx != NULL && p->dx == NULL)
                        p->sx = scorri(p->sx,temp->dx);
                    else if(p->dx != NULL && p->sx == NULL)
                        p->dx = scorri(p->dx,temp->dx);
                }
            }
            free(temp);
        }
        else
        {
            if(n > p->label)
                p->dx = del_nodo(p->dx,n);
            else
                p->sx = del_nodo(p->sx,n);
        }
        return p;
    }
}


int main()
{
    ABR *radice = NULL;
    int dati[] = {2,5,10,3,1,4,6,9,7,8};
    int i;

    for(i=0; i < MAX; i++)
        radice = crea_abr(radice,dati[i]);

    stampa_abr(radice);
    putchar('\n');
    radice = del_nodo(radice,5);

    stampa_abr(radice);

    return 0;
}