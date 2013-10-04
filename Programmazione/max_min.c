int M(struct nodo *T)
{
   if(T == NULL)
        return 0;
    else
    {
        if(T->data < M(T->sx))
            return M(T->sx);
        else if(T->data < M(T->dx))
            return M(T->dx);
        else
            return T->data;
    }
}

int m(struct nodo *T)
{
    if(T == NULL)
        return 2000;
    else
    {
        if(T->data > m(T->sx))
            return m(T->sx);
        else if(T->data > m(T->dx))
            return m(T->dx);
        else
            return T->data;
    }
}