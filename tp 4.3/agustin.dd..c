#include <stdio.h>
#include <stdlib.h>
#include "agustin.d..h"

Nodo2 * inicLista()
{
return NULL;
}

Nodo2 * crearNodo(int dato)
{
Nodo2 * aux = (Nodo2 *) malloc (sizeof(Nodo2));
aux->dato = dato;
aux->ante = NULL;
aux->ste = NULL;
return aux;
}

Nodo2 * agregarAlPrincipio(Nodo2 * lista, Nodo2 * nuevoNodo)
{
nuevoNodo->ste = lista;
if(lista != NULL)
{
lista->ante = nuevoNodo;
}
return nuevoNodo;
}

Nodo2 * buscarUltimo(Nodo2 * lista)
{
Nodo2 * rta;
if (lista == NULL)
{
 rta = NULL;
}

else  if (lista->ste == NULL)
{
rta = lista;

}

else
{
rta = buscarUltimo(lista->ste);
}

return rta;
}

Nodo2 * agregarAlFinal(Nodo2 * lista, Nodo2 *nuevoNodo)
{
Nodo2 * ultimo = NULL;
if (lista == NULL)
{
lista = nuevoNodo;
}
else
{
ultimo = buscarUltimo(lista);
ultimo->ste = nuevoNodo;
nuevoNodo->ante = ultimo;
}
return lista;
}

Nodo2 * insertarNodo(Nodo2 * lista, Nodo2 * nuevoNodo)
{
if (lista == NULL)
{
lista = nuevoNodo;
}
else
if (nuevoNodo->dato < lista->dato)
{
lista = agregarAlPrincipio(lista, nuevoNodo);
}
else
{
Nodo2 * seg = lista->ste;
Nodo2 * ante = lista;
while ( seg!= NULL && nuevoNodo->dato > seg->dato)
{
ante = seg;
seg = seg->ste;
}
ante->ste = nuevoNodo;
nuevoNodo->ante = ante;
nuevoNodo->ste = seg;
if( seg!= NULL)
{
 seg->ante = nuevoNodo;
}
}
return lista;
}

void mostra(Nodo2 * lista)
{
    Nodo2 *seg;
    int dato;
    while(lista!=NULL)
    {
        printf("%d",dato);
        seg=seg->ste;

    }
}
