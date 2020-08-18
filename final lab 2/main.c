#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

nodo *InicLista()
{
    return NULL;
}

nodo *crearNodoDoble(persona cliente)
{
    nodo *aux=(nodo *)malloc(sizeof(nodo));
    aux->cliente=cliente;
    aux->sig=NULL;
    aux->ante=NULL;
    return aux;
}

nodo *agregarP(nodo *lista,nodo *nuevo)
{
    nodo *seg=lista;
    if(seg==NULL)
    {
        seg=nuevo;
    }
    else
    {
        seg->ante=nuevo;
        nuevo->sig=seg;
    }
    return nuevo;
}

nodo *agregaOrdenadoPorCant(nodo *lista,nodo *nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        if (nuevo->cliente.cantArticulos<lista->cliente.cantArticulos)
        {
            lista=agregarP(lista,nuevo);
        }

        else
        {
            nodo* ante=lista;
            nodo* seg=lista->sig;
            while ((seg!=NULL)&&(nuevo->cliente.cantArticulos>seg->cliente.cantArticulos))
            {
                ante=seg;
                seg=seg->sig;
            }
            ante->siguiente=nuevo;
            nuevo->siguiente=seg;
        }
    }
    return lista;
}



int busqdemat(celda Adl[],char mat[],int cant)
{
    int flag=-1;
    int a=0;
    while(a<cant && flag==-1)
    {
        if(strcmp(Adl[a].materia,mat)==0)
        {
            flag=a;
        }
a++:
    }
    return flag;
}

int agregarmat(celda Adl[],char mat[],int cant)
{
    strcpy(Adl[cant].materia,mat);
    Adl[cant].lista=inicLista();
    cant++;
    return cant;
}

nodo * buscarUltimo(nodo * lista)
{
    nodo * seg = lista;
    if(seg != NULL)
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    return seg;
}


nodo * agregarFinal(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}
int alta(celda Adl[],char mat[],char alumno[],int nota,int cant)
{
    nodo*nuevo=crearNodo(nota,alumno);
    int b=busqdemat(Adl,mat,cant);
    if(b==-1)
    {
        cant=agregarmat(Adl,mat,cant);
        b=cant-1;
    }
    Adl[b].lista=agregarFinal(Adl[b].lista,nuevo);
    return cant;
}


void muestralistaaux(nodo *aux)
{
    printf("\tNombre: %s \n",aux->cliente.nombres);
    printf("\tApellido: %s \n",aux->cliente.apellido);
    printf("\tCant Articulos : %d \n",aux->cliente.cantArticulos);
    printf("\tTiempo de espera : %d \n",aux->cliente.tiempoEspera);
    printf("\tTiempo Procesado: %d \n",aux->cliente.tiempoProcesado);
    if(aux->cliente.tipoCliente==1)
        {
            puts("\tTipo de cliente : Embarazada");
        }
        else if (aux->cliente.tipoCliente==2)
        {
            puts("\tTipo de cliente : Jubilado");
        }
        else
        {
            puts("\tTipo de cliente : Cliente comun");
        }
        if(aux->cliente.medioPago==1)
        {
            puts("\tMedio de pago: : Efectivo");
        }
        else if (aux->cliente.medioPago==2)
        {
            puts("\tMedio de pago: : Credito ");
        }
        else
        {
            puts("\tMedio de pago: : Todos");
        }
    printf("\n\n");
}


void mostrarListaDoble(nodo *lista)
{
    persona p;
    nodo *seg=lista;
    while (seg!=NULL)
    {
        muestralistaaux(seg);
        seg=seg->sig;
    }
}

void mostrarcelda(Celda adl[],nodo*lista,int z)
{
    printf("\nLos printeos que correspondan a la estrcutura celda");
    if(adl[z].lista!=NULL)
    {
        mostrarListaDoble(adl[z].lista);
    }
}


int busqueda(celda Adl[],int criterodebusqueda,int cant)
{
    int flag=-1;
    int a=0;
    if(a<cant && flag==-1)
    {
        if(Adl[a].criterodebusqueda==criterodebusqueda)
        {
            flag=1;
        }
        else
        {
            flag=busqueda(Adl,criterodebusqueda,cant);
        }

    }
    return flag;
}

int busquedaelemento(nodo*lista,int criterodebusqueda)
{
    int flag=-1;
    nodo*seg=NULL;
    while(lista!=NULL && flag==-1)
    {
        if(lista->criterodebusqueda==criterodebusqueda)
        {
            flag=1;
        }
        else
        {
            flag=busquedaelemento(lista->siguiente,criterodebusqueda)
        }
    }
    return flag;
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
