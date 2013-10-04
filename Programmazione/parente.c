#include <stdio.h>
#include <stdlib.h>

struct nodo 
{
    int data;
    struct nodo *dx,*sx;
};

struct nodo *parentetica(FILE *fp)
{
    struct nodo *temp = NULL;
    char cara = '\0';
    
    fscanf(fp,"%c",&cara);
    //Si apre
    if(cara == '(')
    {
        fscanf(fp,"%c",&cara);
        //Si chiude
        if(cara == ')')
            return NULL;
        else
        {
            temp = (struct nodo*)malloc(sizeof(struct nodo));
            //Leggo il valore della label del nodo
            fscanf(fp,"%d",&(temp->data));
            printf("LEGGIO: %d\n",temp->data);
            //Leggo lo spazio
            fscanf(fp,"%c",&cara);
            temp->sx = parentetica(fp);
            fscanf(fp,"%c",&cara);
            temp->dx = parentetica(fp);
            //Leggo lo spazio
            fscanf(fp,"%c",&cara);
            //Leggo ')'
            fscanf(fp,"%c",&cara);
            
            return temp;
        }
    }
    else
        return NULL;
}

struct nodo *crea_albero_da_file(char *filename)
{
    FILE *fp;
    struct nodo *albero = NULL;
    
    fp = fopen(filename,"r");
    
    if(fp == NULL)
        puts("Impossibile aprire il file");
    else
        albero = parentetica(fp);
    
    return albero;
}

stampa_pre(struct nodo *T)
{
    if(T != NULL)
    {
        printf("%d ",T->data);
        stampa_r(T->sx);
        stampa_r(T->dx);
    }
}

int main()
{
    struct nodo *T = NULL;
    
    T = crea_albero_da_file("albero.txt");
    stampa_pre(T);
}