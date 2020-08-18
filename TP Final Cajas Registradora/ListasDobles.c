#include "Estructuras.h"
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

nodo *buscarUltimo(nodo *lista)
{
    nodo *seg=lista;
    if (lista==NULL) return NULL;
    else
    {
        while (seg->sig!=NULL)  seg=seg->sig;
    }
    return seg;
}

nodo *agregarF(nodo *lista,nodo *nuevo)
{
    nodo *aux;
    nodo *seg=lista;
    if (seg==NULL) lista=nuevo;
    else
    {
        aux=buscarUltimo(lista);
        aux->sig=nuevo;
        nuevo->ante=aux;

    }
    return lista;
}

nodo *buscarNodoDoble(nodo *lista,char nombre[10])
{
    nodo *seg=lista;
    if (lista!=NULL)
    {
        while (strcmp(seg->cliente.nombres,nombre)>0)
        {
            seg=seg->sig;
        }
    }
    return seg;
}

int SumaArticulos (nodo * lista)
{
    nodo * aux = lista;
    int suma = 0;

    while (aux != NULL)
    {
        suma = suma + aux->cliente.cantArticulos;
        aux= aux->sig;
    }
    return suma;
}

nodo * borrarPrimero (nodo * lista)
{
    if(lista)
    {
        nodo * aux=lista;
        lista=lista->sig;
        free(aux);
    }
    return lista;
}

nodo * borrarNodo(nodo * lista, char lastname[10])
{
    nodo * elegido=NULL;
    nodo * seg=NULL;
    if(lista!=NULL)
    {
        if(strcmp(lista->cliente.apellido,lastname)==0)
        {
            elegido=lista;
            lista=lista->sig;
            if(lista!=NULL) lista->ante=NULL;
            free(elegido);
        }
        else
        {
            seg=lista->sig;
            while(seg!=NULL && (strcmp(seg->cliente.apellido,lastname)!=0)) seg=seg->sig;

            if (seg!= NULL)
            {
                nodo * ante=seg->ante;
                ante->sig = seg->sig;

                if(seg->sig)
                {
                    nodo * siguiente = seg->sig;
                    siguiente->ante=ante;
                }
                free(seg);
            }
        }
    }
    return lista;
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
            nuevo->ante=ante;
            nuevo->sig=seg;
            ante->sig=nuevo;
            if (seg!=NULL)
            {
                seg->ante=nuevo;
            }
        }
    }
    return lista;
}

nodo *agregaOrdenadoPorTipo(nodo *lista,nodo *nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        if (nuevo->cliente.tipoCliente<lista->cliente.tipoCliente)
        {
            lista=agregarP(lista,nuevo);
        }

        else
        {
            nodo *ante=lista;
            nodo *seg= lista->sig;
            while ((seg!=NULL)&&(nuevo->cliente.tipoCliente>seg->cliente.tipoCliente))
            {
                ante=seg;
                seg=seg->sig;
            }
            nuevo->ante=ante;
            nuevo->sig=seg;
            ante->sig=nuevo;
            if (seg!=NULL)
            {
                seg->ante=nuevo;
            }
        }
    }
    return lista;
}

nodo *agregaOrdenadoPorTipoPRIORIDADES(nodo *lista,nodo *nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        if (nuevo->cliente.tipoCliente<lista->cliente.tipoCliente)
        {
            lista=agregarP(lista,nuevo);
        }

        else
        {
            nodo *ante=lista;
            nodo *seg= lista->sig;
            while ((seg!=NULL)&&(nuevo->cliente.tipoCliente>=seg->cliente.tipoCliente))
            {
                ante=seg;
                seg=seg->sig;
            }
            nuevo->ante=ante;
            nuevo->sig=seg;
            ante->sig=nuevo;
            if (seg!=NULL)
            {
                seg->ante=nuevo;
            }
        }
    }
    return lista;
}



