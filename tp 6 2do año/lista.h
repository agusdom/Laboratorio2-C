#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char dia[10];
    struct nodo * siguiente;
}nodo;

nodo * inicLista();
nodo * crearNodo(int cod,char dia[]);
nodo * agregarPpio(nodo * lista, nodo * nuevoNodo);
nodo * buscarUltimo(nodo * lista);
nodo * buscarNodo(int cod, nodo * lista);
nodo * agregarFinal(nodo * lista, nodo * nuevoNodo);
nodo * borrarNodoBuscado(int cod, nodo * lista);
nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo);
nodo * borrarTodaLaLista(nodo * lista);
nodo * borrarPrimerNodo(nodo * lista);
nodo * borrarUltimoNodo(nodo * lista);
int sumarcodigosLista(nodo * lista);
void mostrar(nodo * aux);
void recorrerYmostrar(nodo * lista);
nodo * IngresarDatosAlFinal(nodo * lista);
nodo * IngresarDatosAlPpio(nodo * lista);
nodo * AgregarUnNodoEnOrden(nodo * lista);
nodo * CrearListaOrdenada(nodo * lista);
void BusquedaDeUnNodo(nodo * lista);
nodo * BorrarNodo(nodo * lista);


#endif // LISTA_H_INCLUDED
