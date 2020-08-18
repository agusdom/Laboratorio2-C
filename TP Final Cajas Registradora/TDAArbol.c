#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "TDAArbol.h"

nodoArbol * InicArbol ()
{
    return NULL;
}
/// CREA EL NODO

nodoArbol * crearNodoArbol (persona p)
{
    nodoArbol * aux = (nodoArbol*) malloc (sizeof(nodoArbol));
    aux->p  = p;
    aux -> izq = NULL;
    aux -> der = NULL;
    return aux;
}
/// INSERTA EL NODO ORDENADO POR NOMBRE

nodoArbol * insertarNodoArbol (nodoArbol * arbol, persona p)
{
    if (arbol == NULL)
    {
        arbol = crearNodoArbol(p);
    }
    else
    {
        if (strcmp(p.nombreApellido,arbol->p.nombreApellido)>0)
        {
            arbol -> der = insertarNodoArbol (arbol -> der,p);
        }
        else
        {
            arbol -> izq = insertarNodoArbol (arbol -> izq,p);
        }
    }
    return arbol;
}

/// PASA LOS CLIENTES DEL ARCHIVO AL ARBOL X NOMBRE USANDO LA FUN INSERTAR X NOMBRE

nodoArbol * Pasar_ARCHIVO_a_ARBOL (nodoArbol * arbol, char nombre_archivo[])
{
    FILE * archi;
    archi=fopen(nombre_archivo,"rb");
    persona aux;
    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(persona),1,archi) >0)
        {
            arbol = insertarNodoArbol(arbol,aux);
        }
    }
    fclose(archi);

    return arbol;

}

/// PRINTS DE LOS CLIENTES
void Show_cliente (persona p)
{
    puts("\n---------------------------------------");

    printf("\n || Nombre y Apellido: %s||",p.nombreApellido);
    printf("\n || Cantidad de Articulos: %d||",p.cantArticulos);
    printf("\n || Tiempo De Espera: %d||",p.tiempoDeEspera);
    printf("\n || Tiempo Procesado: %d||",p.tiempoProcesado);
    printf("\n || Tipo De Cliente: %d||",p.tipo_cliente);
    printf("\n || Tipo De Pago: %d||",p.tipo_pago);

    puts("\n---------------------------------------");
}
/// PREGUNTAR AL PROFRE SI ESTA TODO OK

void preOrden (nodoArbol * arbol)
{
    if (arbol != NULL)
    {
        Show_cliente(arbol->p);
        preOrden (arbol -> izq);
        preOrden (arbol -> der);
    }
}

void inOrder (nodoArbol * arbol)
{
    if (arbol != NULL)
    {
        inOrder (arbol -> izq);
        Show_cliente(arbol->p);
        inOrder(arbol -> der);
    }
}

void postOrder (nodoArbol * arbol)
{
    if (arbol != NULL)
    {
        postOrder (arbol -> izq);
        postOrder (arbol -> der);
        Show_cliente(arbol->p);
    }
}

/// BORRAR NODO X NOMBRE .

nodoArbol * nodoMasDerecho (nodoArbol * arbol)
{
    nodoArbol * aux;
    if(arbol->der == NULL)
    {
        aux = arbol;
    }
    else
    {
        aux = nodoMasDerecho(arbol->der);
    }
return aux;
}

nodoArbol * nodoMasIzquierdo (nodoArbol * arbol)
{
    nodoArbol * aux;

    if(arbol->izq == NULL)
    {
        aux = arbol;
    }
    else
    {
        aux = nodoMasIzquierdo (arbol ->izq);
    }
return aux;
}

nodoArbol * BorrarNodo (nodoArbol * arbol, char nombreApellido[])
{
    if (arbol != NULL)
    {
        if (strcmp(nombreApellido,arbol->p.nombreApellido)>0)
        {
            arbol->der = BorrarNodo(arbol->der,nombreApellido);
        }
        else if (strcmp(nombreApellido,arbol->p.nombreApellido)<0)
        {
            arbol->izq = BorrarNodo(arbol->izq,nombreApellido);
        }
        else
        {
            if (arbol->izq != NULL)
            {
                arbol->p = (nodoMasDerecho(arbol->izq))->p;
                arbol->izq = BorrarNodo(arbol->izq, arbol->p.nombreApellido);
            }
            else if (arbol->der != NULL)
            {
                arbol->p = (nodoMasIzquierdo(arbol->der))->p;
                arbol->der = BorrarNodo(arbol->der,arbol->p.nombreApellido);
            }
            else
            {
                free(arbol);
                arbol = NULL;
            }
        }

    }

return arbol;
}

/// PASAR DE ARBOL A CAJA (ADF)

/// preguntar al profe si hay que pasar con las tres y si va en el tda arbol o en el ADF

