#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int valor;
    struct nodo*ste;
} nodo;

int verprimero(nodo*lista)
{
    int primero=0;
    if(lista!=NULL)
    {
        primero=lista->valor;
    }
    return primero,
}

nodo*extraerprimero(nodo**lista)
{
    nodo*aux=NULL;
    if(*lista!=NULL)
    {
        aux=*lista;
        *lista=*lista->ste;
    }
    return aux;
}

nodo*buscarUltimo(nodo*lista)
{
    nodo*seg=lista;
    if(seg!=NULL)
    {
        while(seg->ste!=NULL)
        {
            seg=seg->ste;
        }
    }
    return seg;
}

nodo*agregarFinal(nodo*lista,nodo*nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nodo*ultimo=buscarUltimo(lista);
        ultimo->ste=nuevo;
    }
    return lista;
}

nodo*crearListaordenada(nodo**lista,nodo**lista2)
{
    nodo*lista3=NULL;
    nodo*aux=NULL;
    nodo*auxi=NULL;
    while(*lista!=NULL && *lista2!=NULL)
    {
        if(*lista->valor<*lista2->valor)
        {
            aux=*lista;
            *lista=*lista->ste;
            aux->ste=NULL;
            lista3=agregarFinal(*lista,aux);
        }
        else
            {
            auxi=*lista2;
            *lista2=*lista2->ste;
            auxi->ste=NULL;
            lista3=agregarFinal(*lista2,auxi);
        }
    }
    if(*lista!=NULL)
    {
       lista3=agregarFinal(*lista,*lista);
    }
     if(*lista2!=NULL)
    {
       lista3=agregarFinal(*lista,*lista2);
    }
    return lista3;
}



typedef struct
{
    int dato;
    struct nodo*ste;
    struct nodo*ante;
} nododoble;

nododoble*agregarppio(nododoble*lista,nododoble*nuevo)
{
    nuevo->ste=lista;
    if(lista!=NULL)
    {
        lista->ante=nuevo;
    }
    return lista;
}
nododoble*agregarenorden(nododoble*lista,nododoble*nuevo)
{
    if(lista==NULL)
    {
        lista=dato;
    }
    else
    {
        if(lista->dato>nuevo->dato)
        {
            lista=agregarppio(lista,nuevo);
        }
        else
        {
            nododoble*seg=lista->ste;
            nododoble*anter=lista;
            while(seg!=NULL && lista->dato<nuevo)
            {
                ante=seg;
                seg=seg->ste;
            }
            anter->ste=nuevo;
            nuevo->ante=anter;
            nuevo->ste=seg;
            if(seg!=NULL)
            {
                seg->ante=nuevo;
            }
        }
    }
    return lista;
}
typedef struct
{
    int dato;
    struct nodolista*sig;
} nodolista;



typedef struct
{
    int dato;
    struct nodoArbol*izq;
    struct nodoArbol*der;
} nodoArbol;

nodoArbol*crearnodo(int dato)
{
    nodoArbol*aux=(nodoArbol*)malloc(sizeof(nodoArbol));
    aux->dato=dato;
    aux->der=NULL;
    aux->izq=NULL;
    return aux;
}
nodoArbol*ingresar(nodoArbol*arbol,int dato)
{
    if(arbol==NULL)
    {
        arbol=crearnodo(dato);
    }
    else
    {
        if(arbol->dato>dato)
        {
            arbol->izq=ingresar(arbol->izq,dato);
        }
        else
        {
             arbol->der=ingresar(arbol->der,dato);
        }
    }
    return arbol;
}

nodoArbol*copiarcontenido(nodoArbol*arbol,nodo*lista)
{
    while(lista!=NULL)
    {
        arbol=ingresar(arbol,lista->valor);
        lista=lista->ste;
    }
    return arbol;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
