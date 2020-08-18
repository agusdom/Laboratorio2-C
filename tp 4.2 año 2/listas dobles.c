#include "listas dobles.h"
#include <stdio.h>
#include <stdlib.h>

nodos2*inicLista()
{
    return NULL;
}

nodos2*crearNodo(int dato)
{
    nodos2*aux=(nodos2*)malloc(sizeof(nodos2));
    aux->dato=dato;
    aux->ante=NULL;
    aux->ste=NULL;
    return aux;
}

nodos2*ingresarppio(nodos2*lista,nodos2*nuevo)
{
    nuevo->ste=lista;
    if(lista!=NULL)
    {
        lista->ante=nuevo;
    }
    return lista;
}

nodos2*buscarUltimo(nodos2*lista)
{
    nodos2*seg=lista;
    if(lista!=NULL)
    {
        while(lista->ste!=NULL)
        {
            seg=seg->ste;
        }
    }
    return seg;
}

nodos2*ingresarFinal(nodos2*lista,nodos2*nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nodos2*ultimo=buscarUltimo(lista);
        ultimo->ste=nuevo;
        nuevo->ante=ultimo;
    }
    return lista;
}

nodos2*ingresarEnOrden(nodos2*lista,nodos2*nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        if(lista->dato>nuevo->dato)
        {
            lista=ingresarppio(lista,nuevo);
        }
        else
        {
            nodos2*seg=lista->ste;
            nodos2*anter=lista;
            while(seg!=NULL && lista->dato<nuevo->dato)
            {
                anter->ste=nuevo;
                nuevo->ste=seg;
                nuevo->ante=anter;
                if(seg!=NULL)
                {
                    seg->ante=nuevo;
                }
            }

        }
    }
    return lista;
}

nodos2 * nuevoDato()
{
    int dato;
    nodos2*nuevonodo;

    printf("\ningrese dato:");
    fflush(stdin);
    scanf("%d",&dato);

    nuevonodo=crearNodo(dato);
    return nuevonodo;

}

void elementos(int dato)
{
    printf("\nDato:%d",dato);
}

void recorrerYmostrar(nodos2*lista)
{
    nodos2*seg=lista;
    while(seg!=NULL)
    {
        elementos(seg->dato);
        seg=seg->ste;
    }
}
