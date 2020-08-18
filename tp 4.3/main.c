#include <stdio.h>
#include <stdlib.h>
#include "jistas para pilas.h"

nodos*carga(nodos*lista)
{
    nodos*nuevo;
    char letra='s';
    int dat=0;
    while(letra=='s')
    {
        printf("Ingrese elemento:");
        fflush(stdin);
        scanf("%d",&dat);

        nuevo=crearnodos(dat);
        lista=agregarppios(lista,nuevo);

        printf("Desea continuar: s/n");
        fflush(stdin);
        scanf("%c",&letra);
    }
    return lista;
}

void mostrarinvertido(nodos*lista)
{
    if(lista!=NULL)
    {
        mostrarinvertido(lista->siguiente);
        printf("\nElementos:%d",lista->dato);
    }
}

int sumalista(nodos*lista)
{
    int sum=0;
    if(lista==NULL)
    {
        sum=0;
    }
    else
    {
        sum=lista->dato+sumalista(lista->siguiente);
    }
    return sum;
}

void mostrarpar(nodos*lista)
{
    nodos*seg=lista->siguiente;
    if(seg!=NULL)
    {
        printf("\nElementos:%d",lista->dato);
        mostrarpar(seg->siguiente);
    }
}

nodos*invertir(nodos*lista)
{
    nodos*aux=NULL;
    if(lista!=NULL)
    {
        aux=lista;
        lista=lista->siguiente;
        aux->siguiente=NULL;
        lista=agregarFinal(invertir(lista),aux);
    }
    return lista;
}

nodos*borrar(nodos*lista,int dato)
{
    nodos*borrada=NULL;
    if(lista!=NULL)
    {
        if(lista->dato=dato)
        {
            borrada=lista;
            lista=lista->siguiente;
            free(borrada);
        }
        else
        {
            lista->siguiente=borrar(lista->siguiente,dato);
        }
    }
    return lista;
}

nodos*insertar(nodos*lista,int dato)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        if(lista->dato>dato)
        {
            lista=agregarppios(lista,dato):
        }
        else
        {
            lista->siguiente=insertar(lista->siguiente,dato):
        }
    }
    return lista;
}
int main()
{
    nodos*lista;
    lista=iniclistas();
    lista=carga(lista);
    recorrerYmostrarr(lista);
    puts("lista invertida");
    mostrarinvertido(lista);
    int s=0;
    s=sumalista(lista);
    printf("\nEl resultado de la suma es:%d",s);
  puts("\nLugares pares");
    mostrarpar(lista);
      /*lista=invertir(lista);
    lista=borrar(lista,3);
    puts("lista con elemento borrado");
    recorrerYmostrarr(lista);
    lista=insertar(lista,crearnodos(2));
    puts("lista con elemento insertado");
    recorrerYmostrarr(lista);*/

    return 0;
}
