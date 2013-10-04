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