#include "jistas para pilas.h"
#include <stdio.h>
#include <stdlib.h>

nodos*iniclistas()
{
    return NULL;
}

nodos*crearnodos(int dato)
{
    nodos*aux=(nodos*)malloc(sizeof(nodos));
    aux->dato=dato;
    aux->siguiente=NULL;
    return aux;

}
nodos * nuevoDato()
{
    int dato;
    nodos*nuevonodo;

    printf("\ningrese dato:");
    fflush(stdin);
    scanf("%d",&dato);

    nuevonodo=crearnodos(dato);
    return nuevonodo;



}

nodos*agregarppios(nodos*lista,nodos*nuevonodo)
{
    if(lista==NULL)
    {
        lista=nuevonodo;
    }
    else
    {
        nuevonodo->siguiente=lista;
        lista=nuevonodo;
    }
    return lista;
}


int buscarprimero(nodos*lista)
{
    int b=0;

    if(lista!=NULL)
    {
        b=lista->dato;

    }
    return b;
}



nodos * borrarprimerNodos(nodos * lista)
{
    nodos * seg;
    nodos * ante;

    if(lista != NULL)
    {
        nodos * aux = buscarprimero(lista);
        lista = lista->siguiente;
        free(aux);
    }

    return lista;
}



void recorrerYmostrarr(nodos*lista)
{
    nodos*seg=lista;
    while(seg!=NULL)
    {
        escribirr(seg);
        seg=seg->siguiente;
    }
}


void escribirr(nodos*aux)
{
    printf("\ndato: %d \n\n", aux->dato);
}

nodos*buscarUltimo(nodos*lista)
{
    nodos*seg=lista;
    if(seg!=NULL)
    {
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
    }
    return seg;
}

nodos*agregarFinal(nodos*lista,nodos*nuevonodo)
{
    if(lista==NULL)
    {
        lista=nuevonodo;
    }
    else
    {
        nodos*ultimo=buscarUltimo(lista);
        ultimo->siguiente=nuevonodo;
    }
    return lista;
}
