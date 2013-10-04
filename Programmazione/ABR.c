/*
Si crei un file di testo di nome vettore.txt contenente nella prima riga un intero positivo N e nelle consecutive N righe un intero.
Si crei un array dinamico V di dimensione N contenente gli N interi definiti nelle ultime N righe del file.
--------------------------------------------DONE------------------------------------------------------------
Si costruisca l’albero binario di ricerca A contenente gli interi del vettore V inserendoli da quello in posizione 0 a quello in posizione N-1.
-------------------------------------------DONE------------------------------------------------------------------------------------------------
Si scriva una funzione ricorsiva che, dato l’ albero binario di ricerca A e un intero k,restituisca il numero di nodi di A con etichetta maggiore di k. 
Tale funzione deve restituire utilizzando le proprietà dell’ABR, ovvero evitando di esaminare tutti i nodi dell’albero. 
------------------------------------------DONE---------------------------------------------------------------------------------
Si scriva una funzione ricorsiva che, preso in input un ABR e un intero m stampi i primi m elementi di A nell’ordine crescente. 
Si applichi la funzione all’ABR A. 
------------------------------------------DONE----------------------------------------------------------------------------------------------
Scrivere una funzione ricorsiva che preso in input l’ABR A e due interi m e n, con m<=n, stampi tutti gli elementi di A compresi tra m e n.
------------------------------------------DONE---------------------------------------------------------------------------------------------
Scrivere una funzione che, dato un ABR e un intero i, restituisca il puntatore al nodo contenente l'i-esimo valore nell'ordine crescente.
La si applichi su A.
-----------------------------------------------------DONE---------------------------------------------------------------------------------
Si scriva una funzione ricorsiva che crei una copia B dell’albero A.
----------------------------------------------------------------------------------------------------------------------------------------
Creare una funzione ricorsiva che dato l’ albero binario B, sostituisca l'etichetta di ogni nodo n in B con la somma delle etichette nelcammino dalla radice di B al
nodo n.
----------------------------------------------------DONE-----------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define FILETTO "vettore.txt"

typedef struct albero
{
    int valore;
    struct albero *sx,*dx;
}ABR;

int* leggiDaFile(int *V,int *N)
{
    FILE *fp;
    int i;
    
    if((fp = fopen(FILETTO,"r")) == NULL)
    {
        puts("Impossibile aprire il file");
        exit(1);
    }
    
    fscanf(fp,"%d\n",N);
    
    V = (int*) malloc((*N)*sizeof(int));
    
    for(i=0; i < *N; i++)
        fscanf(fp,"%d\n",&V[i]);
    
    return V;
}

ABR *creaAbr(ABR *p,int x)
{
    if(p == NULL)
    {
        p = (ABR*)malloc(sizeof(ABR));
        p->dx = NULL;
        p->sx = NULL;
        p->valore = x;
    }
    else
    {
        if(x > p->valore)
            p->dx = creaAbr(p->dx,x);
        else
            p->sx = creaAbr(p->sx,x);
    }
    return p;
}

void stampa_simm(ABR *p)
{
    if(p != NULL)
    {
        stampa_simm(p->sx);
        printf("%d -> ",p->valore);
        stampa_simm(p->dx);
    }
}

int num_nodi(ABR *p,int k)
{
    if(p == NULL)
        return 0;
    
    if(p->valore <= k)
        return num_nodi(p->dx, k);
        
    return 1 + num_nodi(p->sx, k) + num_nodi(p->dx, k);
}

void stampaMnodi(ABR *p,int *m)
{
    if (p != NULL)
    {
        
        if ((*m) > 0)
            stampaMnodi(p->sx,m);

        if ((*m) > 0)
        {
            printf("%d | %d ",p->valore,*m);
            (*m)--;
        }

        if ((*m) > 0)
            stampaMnodi(p->dx,m);
    }    
}

//Controlla solo i nodi compresi
void stampa_compresi(ABR *p,int m, int n)
{
    if(p != NULL)
    {
        if(p->valore > m)
        {
            if(p->valore < n)
            {
                stampa_compresi(p->sx,m,n);
                printf("%d ",p->valore);
                stampa_compresi(p->dx,m,n);
            }
            else
                stampa_compresi(p->sx,m,n);
            
        }
        else
            stampa_compresi(p->dx,m,n);
    }
}

//Controlla tutti i nodi, meno efficente
void stampa_compresi_alternativa(ABR *p,int m,int n)
{
    if(p != NULL)
    {
        stampa_compresi_alternativa(p->sx,m,n);
        if(p->valore > m && p->valore < n)
            printf("%d ",p->valore);
        stampa_compresi_alternativa(p->dx,m,n);
    }
}

ABR* nodoI(ABR *p,int *i)
{ 
    ABR *temp = NULL;
    
    if (p != NULL)
    {
        if(*i > 0)
            temp = nodoI(p->sx,i);
        
        if(*i > 0)
            (*i)--;

        if(*i == 0)
        {
            temp = (ABR*)malloc(sizeof(ABR));
            temp->valore = p->valore;
            temp->dx = NULL;
            temp->sx = NULL;
            *i = -1;
            return temp;
        }
        
        if(*i > 0)
            temp = nodoI(p->dx,i);
    }    
     return temp;
}

ABR *copia(ABR *a,ABR *b)
{
   if(a != NULL)
   {
       if(b == NULL)
       {
           b = (ABR*)malloc(sizeof(ABR));
           b->valore = a->valore;
           b->dx = copia(a->dx,b->dx);
           b->sx = copia(a->sx,b->sx);
           return b;
       }
   }
}

ABR *somma(ABR *b,int i)
{   
    if(b != NULL)
    {
       somma(b->sx,b->valore+i);
       somma(b->dx,b->valore+i);
       b->valore +=i;
       return b;
    }
}


int main()
{
    int *V,N,i,k,m,n;
    ABR *radice = NULL;
    ABR *nodo = NULL;
    ABR *copia_radice = NULL;
    
    V = leggiDaFile(V,&N);
    
    for(i=0; i < N; i++)
        radice = creaAbr(radice,V[i]);
    printf("START ");    
    stampa_simm(radice);
    puts("END");
    
    printf("Inserisci k: ");
    scanf("%d",&k);
    
    printf("I nodi sono: %d\n",num_nodi(radice,k));
    
    printf("Inserisci m: ");
    scanf("%d",&m);
    
    printf("Gli m nodi sono: ");
    stampaMnodi(radice,&m);
    putchar('\n');
    
    printf("Inserisci m ed n: ");
    scanf("%d %d",&m,&n);
    
    stampa_compresi(radice,m,n);
    putchar('\n');
    stampa_compresi_alternativa(radice,m,n);
    putchar('\n');
 
    printf("Inserisci i: ");
    scanf("%d",&i);
    
    printf("I: %d\n",i);
    
    nodo = nodoI(radice,&i);
    stampa_simm(nodo);
    putchar('\n');

    copia_radice = copia(radice,copia_radice);
    stampa_simm(copia_radice);
    putchar('\n');

    copia_radice = somma(copia_radice,0);
    stampa_simm(copia_radice);
    putchar('\n');

    return 0;
}