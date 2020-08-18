#include "lista.h"

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(int cod, char dia[])
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->codigo = cod;
    strcpy(aux->dia,dia);
    aux->siguiente = NULL;
    return aux;
}

nodo * agregarPpio(nodo * lista, nodo * nuevoNodo)
{

    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else

    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
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

nodo * buscarNodo(int cod, nodo * lista)

{
    nodo * seg;
    seg = lista;

    while ((seg != NULL) && (seg->codigo!=cod))
    {
        seg=seg->siguiente;
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

nodo * borrarNodoBuscado(int cod, nodo * lista)
{
    nodo * seg;
    nodo * ante;
    if((lista != NULL) && (lista->codigo==cod))
    {
        nodo * aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (seg->codigo!=cod))
        {
            ante = seg;
            seg = seg->siguiente;
        }
        if(seg!=NULL)
        {
            ante->siguiente = seg->siguiente;

            free(seg);
        }
    }
    return lista;
}

nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo)

{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {

        if(nuevoNodo->codigo < lista->codigo)
            lista = agregarPpio(lista, nuevoNodo);
        else
        {

            nodo * ante = lista;
            nodo * seg = lista;
            while(seg != NULL && nuevoNodo->codigo > seg->codigo)
            {
                ante = seg;
                seg = seg->siguiente;
            }

            ante->siguiente = nuevoNodo;
            nuevoNodo->siguiente = seg;
        }
    }
    return lista;
}

nodo * borrarTodaLaLista(nodo * lista)
{
    nodo * proximo;
    nodo * seg;
    seg = lista;
    while(seg != NULL)
    {
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}

nodo * borrarPrimerNodo(nodo * lista)
{
    nodo * aux=lista;
    lista=lista->siguiente;
    free(aux);
    return lista;
}

nodo * borrarUltimoNodo(nodo * lista)
{
    nodo * aux=lista;
    nodo * ante;
    while(aux->siguiente!=NULL)
    {
        ante=aux;
        aux=aux->siguiente;
    }
    free(aux);
    ante->siguiente=NULL;
    return lista;
}

int sumarcodigosLista(nodo * lista)
{
    int suma = 0;
    nodo * seg = lista;
    while (seg != NULL)
    {
        suma = suma + seg->codigo;
        seg = seg->siguiente;
    }
    return suma;
}

void mostrar(nodo * aux)
{
    printf("codigo:[%d] \tdia:%s ",aux->codigo,aux->dia);
}

void recorrerYmostrar(nodo * lista)
{
    nodo * aux=lista;
    while(aux!=NULL)
    {
        mostrar(aux);
        aux=aux->siguiente;
    }
    puts("\n");
}

nodo * IngresarcodsAlFinal(nodo * lista)
{
    int cod;
    int cant;
    char dia[10];
    nodo * aux;
    printf("ingrese cantidad ingresar: ");
    scanf("%d",&cant);
    while(cant>0)
    {
        printf("ingrese un codigo: ");
        scanf("%d",&cod);
        printf("ingrese un dia: ");
        fflush(stdin);
        gets(dia);
        aux=crearNodo(cod,dia);
        lista=agregarFinal(lista,aux);
        cant--;
    }
    return lista;
}

nodo * IngresarcodsAlPpio(nodo * lista)
{
    int cod;
    int cant;
    char dia[20];
    nodo * aux;
    printf("ingrese cantidad ingresar: ");
    scanf("%d",&cant);
    while(cant>0)
    {
        printf("ingrese un codigo: ");
        scanf("%d",&cod);
        printf("ingrese dia: ");
        fflush(stdin);
        gets(dia);
        aux=crearNodo(cod,dia);
        lista=agregarPpio(lista,aux);
        cant--;
    }
    return lista;
}

nodo * AgregarUnNodoEnOrden(nodo * lista)
{
    int cod;
    char dia[20];
    nodo * aux=lista;
    printf("ingrese un codigo: ");
    scanf("%d",&cod);
    printf("ingrese dia: ");
    fflush(stdin);
    gets(dia);
    aux=agregarEnOrden(lista,crearNodo(cod,dia));
    return aux;
}

nodo * CrearListaOrdenada(nodo * lista)
{
    int cant;
    nodo * aux=lista;
    printf("ingrese cantidad a ingresar: ");
    scanf("%d",&cant);
    while(cant>0)
    {
        aux=AgregarUnNodoEnOrden(aux);
        cant--;
    }
    return aux;
}

void BusquedaDeUnNodo(nodo * lista)
{
    int cod;
    printf("ingrese codigo a buscar: ");
    scanf("%d",&cod);
    nodo * aux=inicLista();
    aux=buscarNodo(cod,lista);
    if(aux!=NULL)
        printf("%d",aux->codigo);
}

nodo * BorrarNodo(nodo * lista){
    int cod;
    printf("ingrese codigo a borrar de la lista: ");
    scanf("%d",&cod);
    lista=borrarNodoBuscado(cod,lista);
    return lista;
}
