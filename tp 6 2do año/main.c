#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "lista dobles.h"

typedef struct
{
    int codigo;
    char titulo[30];
    int cantidad;
    struct nodo2 * ste;
    struct nodo2 * ante;
} nodo2;

typedef struct
{
    int codigo;
    char dia[10];
    struct nodo *ste;
} nodo;

typedef struct
{
    int numero_socio;
    char nombre[30];
    nodo *lista;
} celda;

void iniclista(celda*lista)
{
    (*lista)=NULL;
}

void pedirdatos()
{
    char dia[10];
    int codigo;
    int numerodsocio;
    char nombre[30];
    char titulo[30];

    printf("ingrese nombre del socio:");
    fflush(stdin);
    gets(nombre);

    printf("ingrese numero de socio:");
    fflush(stdin);
    scanf("%d",&numerodsocio);

    printf("ingrese codigo de la pelicula:");
    fflush(stdin);
    scanf("%d",&codigo);

    printf("ingrese dia del alquiler:");
    fflush(stdin);
    gets(dia);


}

celda *crearnodo(char dia[10],int codigo,int numerodsocio,char nombre[30])
{
    celda* aux= (celda*) malloc(sizeof(celda));
    aux->aux.codigo=codigo;
    aux->aux.cantidad=cantidad;
    strcpy(aux->aux.titulo,titulo);
    aux->ante=NULL;
    aux->ste=NULL;
    return aux;
}

celda *crearnodo2(char dia[10],int codigo,int numerodsocio,char nombre[30])
{
    celda* auxx= (nodo2*) malloc(sizeof(nodo2));
    auxx->auxx.codigo=codigo;
    strcpy(auxx->auxx.dia,dia);
    strcpy(auxx->auxx.nombre,nombre);
    aux->ste=NULL;
    return auxx;
}

int buscaPospelicula(celda adl[], char pelicula[],int validos)
{
    int rta=-1;
    int i=0;

    while((i<validos)&&(rta==-1) )
    {
        if(strcmp(adl[i].pelicula, pelicula)==0)
        {
            rta=i;
        }
        i++;
    }
    return rta;
}

int agregarpelicula(celda adl, char pelicula[], int validos)
{
    strcpy(adl[validos].pelicula, pelicula);
    adl[validos].lista = inicLista();
    validos++;
    return validos;
}

nodo*agregarPpio(nodo*lista,nodo*nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nuevo->siguiente=lista;
        lista=nuevo;

    }
    return lista;
}

int alta(celda adl,char dia[10],int codigo,int numerodsocio,char nombre[30],int validos)
{
    nodo*aux=crearnodo(dia,codigo,numerodsocio,nombre);
    int pos=buscaPospelicua(adl,pelicula,validos);
    if(pos==-1)
    {
        validos=agregarpelicula(adl,pelicula,validos);
        pos=validos-1;
    }
    adl[pos].lista=agregarPpio(adl[pos].lista,aux);
    return validos;
}

int cant_d_peliculas(celda adl,int validos,int numerods)
{
   {
    int i=0;
    int cant=0;
    while(i<validos && adl[i].numero_socio != numerods)
        i++;
    if(i != validos && adl[i].lista != NULL)
    {
        nodo * aux=adl[i].lista;
        while(aux!=NULL)
        {
            cant++;
            aux=aux->siguiente;
        }
    }
    return cant;
}
}

void MostrarPelisClientes(celda adl[], int validos, nodoD * pelis)
{
    int i=0;
    int hay=0;
    nodoD * aux=NULL;
    nodo * listacliente=NULL;
    while(i<validos)
    {
        if(adl[i].lista != NULL)
        {
            hay=1;
            printf("peliculas alquiladas por: %s\n\t",adl[i].nombre);
            listacliente=adl[i].lista;
            while(listacliente != NULL)
            {
                aux=buscarNodoPeli(pelis,listacliente->codigo);
                printf("\t\t\t%s\n",aux->titulo);
                listacliente=listacliente->siguiente;
            }
        }
        i++;
    }
    if(!hay)
        printf("no existen peliculas alquiladas\n");
    system("pause");
}

int main()
{

    return 0;
}
