#ifndef LISTA_DOBLES_H_INCLUDED
#define LISTA_DOBLES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char titulo[30];
    int cantidad;
    struct nodoD * sig;
    struct nodoD * ante;
}nodoD;

nodoD * inicListaD();
nodoD * crearNodoD(int cod, char titu[30], int cant);
nodoD * agregarPpioD(nodoD * lista, nodoD * nuevo);
void mostrarlistaD(nodoD * lista);
void borrarNodoD(nodoD ** lista, int pos);
nodoD * buscaUltimoD(nodoD * lista);
nodoD * agregarFinalD(nodoD * lista, nodoD * nuevo);
nodoD * agregarEnOrdenD(nodoD * lista, nodoD * nuevoNodo);

#endif // LISTA_DOBLES_H_INCLUDED
