#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

typedef struct
{
    char nombre[20];
    int edad;
    struct nodos * siguiente;
} nodos;

typedef struct
{
    char nombre[20];
    int edad;
} persona;

void cargararc(char nom[])
{
    persona aux;
    FILE*archi=fopen(nom,"wb");
    char letra='s';
    if(archi!=NULL)
    {
        while(letra=='s')
        {
            printf("\ningrese nombre:");
            fflush(stdin);
            scanf("%s", &aux.nombre);

            printf("\ningrese edad:");
            scanf("%d",&aux.edad);

            fwrite(&aux,sizeof(persona),1,archi);

            printf("\nDesea continuar: s/n");
            fflush(stdin);
            scanf("%c",&letra);
        }
        fclose(archi);
    }

}

nodos*cargarlista(char nom[],nodos*lista)
{
    nodos*nuevonodo;
    persona aux;
    FILE*archi=fopen(nom,"rb");
    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(persona),1,archi)>0)
        {
            nuevonodo=crearnodo(aux.nombre,aux.edad);
            lista=agregarultimo(lista,nuevonodo);

        }

    }
    fclose(archi);
    return lista;
}

void cargararcarr(char nom[])
{
    persona aux;
    FILE*archi=fopen(nom,"wb");
    char letra='s';
    if(archi!=NULL)
    {
        while(letra=='s')
        {
            printf("\ningrese nombre:");
            fflush(stdin);
            scanf("%s", &aux.nombre);

            printf("\ningrese edad:");
            scanf("%d",&aux.edad);

            fwrite(&aux,sizeof(persona),1,archi);

            printf("\nDesea continuar: s/n");
            fflush(stdin);
            scanf("%c",&letra);
        }
        fclose(archi);
    }

}
nodos*cargarlistaenorden(char nom[],nodos*lista)
{
    nodos*nuevonodo;
    persona aux;
    FILE*archi=fopen(nom,"rb");
    if(archi!=NULL)
    {
        while(fread(&aux,sizeof(persona),1,archi)>0)
        {
            nuevonodo=crearnodo(aux.nombre,aux.edad);
            lista=agregarenorden(lista,nuevonodo);

        }

    }
    fclose(archi);
    return lista;
}
int buscaelemento(nodos*lista,char nombre[20])
{
    int flag=0;
    nodos*ante;
    while(lista!=NULL && flag==0)
    {
        if(strcmp(lista->nombre,nombre)==0)
        {
            flag=1;

        }
        else
        {
            ante=lista;
            lista=lista->siguiente;
        }

    }

    return flag;
}
nodos*carga(nodos*lista2)
{
    nodos*nuevonodo;
    char letra='s';
    while(letra=='s')
    {
        nuevonodo=nuevoDato();
        lista2=agregarultimo(lista2,nuevonodo);

        printf("desea continuar: s/n");
        fflush(stdin);
        scanf("%c",&letra);
    }
    return lista2;
}

nodos* listaordenada(nodos*lista,nodos*lista2,nodos*listaord)
{
    nodos*aux=NULL;
    nodos*auxi=NULL;
    while(lista!=NULL && lista2!=NULL)
    {
        if(lista->edad<lista2->edad)
        {
            aux=lista;
            lista=lista->siguiente;
            aux->siguiente=NULL;
            listaord=agregarultimo(listaord,aux);
        }
        else
        {
            auxi=lista2;
            lista2=lista2->siguiente;
            auxi->siguiente=NULL;
            listaord=agregarultimo(listaord,auxi);
        }

    }

    if(lista!=NULL)
    {
        listaord=agregarultimo(listaord,lista);
    }
    if(lista2!=NULL)
    {
        listaord=agregarultimo(listaord,lista2);
    }

    return listaord;
}

nodos*invertirlista(nodos*lista,nodos*lista2)
{
    nodos*aux;
    while(lista!=NULL)
    {
       aux=lista;
            lista=lista->siguiente;
            aux->siguiente=NULL;
            lista2=agregarppio(lista2,aux);


    }
    return lista2;

}



int main()
{
    /*char nom[50]="listas.dat";
    // cargararc(nom);
    nodos*lista;
    lista=iniclista();
    lista=cargarlista(nom,lista);
    puts("lista 1");
    recorrerYmostrar(lista);
    /*nodos*listaord;
    listaord=iniclista();
    listaord=cargarlistaenorden(nom,listaord);
    recorrerYmostrar(listaord);
    char nombre[20];
    printf("ingrese nombre ha buscar:");
    scanf("%s",&nombre);
    lista=buscaelemento(lista,nombre);
    if(lista==1)
    {
        printf("\nse encuentra");

    }
    else
    {
        printf("\nno se encuentra");
    }
    nodos*lista2;
    nodos*listafinal;
    lista2=iniclista();
    listafinal=iniclista();
    lista2=carga(lista2);
    puts("lista 2");
    recorrerYmostrar(lista2);
    listafinal=listaordenada(lista,lista2,listafinal);
    puts("lista final");
    recorrerYmostrar(listafinal);*/
    nodos*lista2;
    nodos*lista;
    lista=iniclista();
    lista2=iniclista();
    lista=carga(lista);
    puts("lista 1");
    recorrerYmostrar(lista);
    lista2=invertirlista(lista,lista2);
    puts("lista 2 invertida");
    recorrerYmostrar(lista2);
    return 0;
}
