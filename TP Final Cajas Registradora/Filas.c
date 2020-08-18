#include "Estructuras.h"


void InicFila(Fila *filita)
{
    filita->inicio=InicLista();
    filita->fin=InicLista();
}

void cargarFila(Fila * filita,persona cliente)
{
    nodo *aux=crearNodoDoble(cliente);
    filita->fin=InicLista();
    if(filita->inicio==NULL)
    {
        filita->inicio=aux;
    }
    else
    {
        filita->inicio=agregarF(filita->inicio,aux);
    }
    filita->fin=aux;
}

void agregar(Fila * filita,nodo *nuevo)
{
    if(filita->inicio==NULL)
    {
        filita->inicio=nuevo;
        filita->fin=nuevo;
    }
    else
    {
        filita->inicio=agregarF(filita->inicio,nuevo);
        filita->fin=nuevo;
    }

    nodo*ultimo=buscarUltimo(filita->inicio);
    filita->fin = ultimo;

}

void mostrarFila(Fila *filita)
{
    if(filita->inicio)
    {
        printf("\n-------------PERSONAS EN LA FILA-------------\n");
        printf("\n\n");
        mostrarListaDoble(filita->inicio);
        printf("\n-----------------FIN DE FILA-----------------\n");

    }
}

int filaVacia(Fila  filita)
{
    int rta=0;
    if(filita.inicio)
    {
        rta=1;
    }
    return rta;
}

persona sacarDeFila(Fila * filita)
{
    persona rta;
    if(filita->inicio)
    {
        nodo * aux=filita->inicio;
        nodo * cabezaNueva=aux->sig;
        if(filita->inicio!=filita->fin)
        {
            cabezaNueva->ante=NULL;
            filita->inicio=cabezaNueva;
        }
        else
        {
            filita->inicio=NULL;
            filita->fin=NULL;
        }
        rta=aux->cliente;
        free(aux);
    }
    return rta;
}

int contarValidosFila(Fila *filita)
{
    int x=0;
    while (filita->inicio)
    {
        x++;
        filita->inicio=filita->inicio->sig;

    }
    return x;
}
