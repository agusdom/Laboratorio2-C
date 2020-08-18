#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

nodo*iniclista()
{
    return NULL;
}

nodo*crearnodo(char nombre[20],int edad)
{
    nodo*aux=(nodo*)malloc(sizeof(nodo));
    aux->edad=edad;
    strcmp(aux->nombre,nombre);
    aux->siguiente=NULL;
    return aux;

}

nodo*agregarppio(nodo*lista,nodo*nuevonodo)
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

nodo*buscar(nodo*lista,char nombre[20])
{
    nodo*seg;
    seg=lista;
    while(seg!=NULL &&  strcmp(seg->nombre,nombre)!=0)
    {
        seg=seg->siguiente;
    }
    return seg;
}

nodo*buscarultimo(nodo*lista)
{
    nodo*seg=lista;
    if(seg!=NULL)
    {
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
        return seg;
    }

}

nodo*agregarultimo(nodo*lista,nodo*nuevonodo)
{
    if(lista==NULL)
    {
        lista=nuevonodo;
    }
    else
    {
        nodo*ultimo=buscarultimo(lista);
        ultimo->siguiente=nuevonodo;
    }
    return lista;
}

nodo*agregarenorden(nodo*lista,nodo*nuevonodo)
{

    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if(strcmp(nuevoNodo->nombre,lista->nombre)<0)
            lista = agregarPpio(lista, nuevoNodo);
        else
        {

            nodo * ante = lista;
            nodo * seg = lista->siguiente;
            while( (seg != NULL)&&(strcmp(nuevoNodo->nombre,seg->nombre)>=0) )
            {
                ante = seg;
                seg = seg->siguiente;
            }
            nuevoNodo->siguiente = seg;
            ante->siguiente = nuevoNodo;
        }
    }
    return lista;

}

void escribir(nodo*aux)
{
    printf("nombre: %s \n", aux->nombre);
    printf("edad: %d \n\n", aux->edad);
}


void recorrerYmostrar(nodo*lista)
{
    nodo*seg=lista;
    while(seg!=NULL)
    {
        escribir(seg);
        seg=seg->siguiente;
    }
}

nodo * borrarNodo(char nombre[20], nodo * lista)
{
    nodo * seg;
    nodo * ante;

    if((lista != NULL) && (strcmp(nombre, lista->nombre)==0 ))
    {
        nodo * aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (strcmp(nombre, seg->nombre)!=0 ))
        {
            ante = seg;
            seg = seg->siguiente;
        }

        if( seg!= NULL)
        {
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}

nodo * borrarTodaLaLista(nodo * lista)
{
    nodo * proximo;
    nodo * seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}
