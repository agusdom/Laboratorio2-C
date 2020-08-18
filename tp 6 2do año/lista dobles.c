#include "lista dobles.h"

nodoD * inicListaD()
{
    return NULL;
}

nodoD * crearNodoD(int cod, char titu[30], int cant)
{
    nodoD * aux=(nodoD*)malloc(sizeof(nodoD));
    aux->codigo=cod;
    strcpy(aux->titulo,titu);
    aux->cantidad=cant;
    aux->ante=NULL;
    aux->sig=NULL;
}

nodoD * agregarPpioD(nodoD * lista, nodoD * nuevo)
{
    if(lista == NULL)
        lista=nuevo;
    else
    {
        nuevo->sig=lista;
        lista->ante=nuevo;
        lista=nuevo;
    }
    return lista;
}

void mostrarlistaD(nodoD * lista)
{
    nodoD * aux=lista;
    while(aux!=NULL)
    {
        printf("codigo:[%d] \tcantidad:%d \ttitulo:%s\n",aux->codigo,aux->cantidad,aux->titulo);
        aux=aux->sig;
    }
}

void borrarNodoD(nodoD ** lista, int pos)
{
    if(*lista != NULL)
    {
        if(pos == 1)
        {
            nodoD * aux = *lista;
            (*lista)=(*lista)->sig;
            (*lista)->ante=NULL;
            free(aux);
        }
        else
        {
            nodoD * anterior;
            nodoD * seg=*lista;
            while(seg != NULL && pos>1)
            {
                anterior=seg;
                seg=seg->sig;
                pos--;
            }
            if(seg != NULL)
            {
                nodoD * proximo=seg->sig;
                anterior->sig=proximo;
                if(proximo != NULL)
                    proximo->ante=anterior;
                free(seg);
            }
        }
    }
}

nodoD * buscaUltimoD(nodoD * lista)
{
    nodoD * aux=lista;
    if(aux!=NULL)
    {
        while(aux->sig != NULL)
        {
            aux=aux->sig;
        }
    }
    return aux;
}

nodoD * agregarFinalD(nodoD * lista, nodoD * nuevo){
    if(lista == NULL)
        lista=nuevo;
    else{
        nodoD * aux=buscaUltimoD(lista);
        nuevo->ante=aux;
        aux->sig=nuevo;
    }
    return lista;
}

nodoD * agregarEnOrdenD(nodoD * lista, nodoD * nuevoNodo)

{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {

        if(nuevoNodo->codigo < lista->codigo)
            lista = agregarPpioD(lista, nuevoNodo);
        else
        {

            nodoD * ante = lista;
            nodoD * seg = lista;
            while(seg != NULL && nuevoNodo->codigo > seg->codigo)
            {
                ante = seg;
                seg = seg->sig;
            }

            ante->sig = nuevoNodo;
            nuevoNodo->ante = ante;
            nuevoNodo->sig = seg;
            if(seg!=NULL)
                seg->ante = nuevoNodo;
        }
    }
    return lista;
}
