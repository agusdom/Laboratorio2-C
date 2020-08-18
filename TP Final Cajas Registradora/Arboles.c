#include "Estructuras.h"


nodoArbol *inicArbol()
{
    return NULL;
}

nodoArbol *crearNodoA(persona Persona)
{
    nodoArbol*aux=(nodoArbol*)malloc(sizeof(nodoArbol));
    strcpy(aux->p.nombres,Persona.nombres);
    strcpy(aux->p.apellido,Persona.apellido);
    aux->p.id=Persona.id;
    aux->p.cantArticulos=Persona.cantArticulos;
    aux->p.tiempoProcesado=Persona.tiempoProcesado;
    aux->p.tiempoEspera=Persona.tiempoEspera;
    aux->p.tipoCliente=Persona.tipoCliente;
    aux->p.medioPago=Persona.medioPago;///PREGUNTAR
    //aux->p= Persona;
    aux->der=NULL;
    aux->izq=NULL;
    return aux;
}


nodoArbol *insertar(nodoArbol *Arbol,persona p)
{
    if (Arbol==NULL)
    {
        Arbol=crearNodoA(p);
    }
    else
    {
        if (strcmp(Arbol->p.nombres,p.nombres)>0)
            Arbol->izq=insertar(Arbol->izq,p);
        else
            Arbol->der=insertar(Arbol->der,p);
    }
    return Arbol;
}

void verArbol (persona aux)
{
    printf("\nNombre:%s",aux.nombres);
    printf("\nApellido:%s",aux.apellido);
    printf("\nId del cliente:%d\n",aux.id);

    if(aux.tipoCliente==1)
    {
        puts("Tipo de cliente : Embarazada");
    }
    else if (aux.tipoCliente==2)
    {
        puts("Tipo de cliente : Jubilado");
    }
    else
    {
        puts("Tipo de cliente : Cliente comun");
    }
    if(aux.medioPago==1)
    {
        puts("Medio de pago: : Efectivo");
    }
    else if (aux.medioPago==2)
    {
        puts("Medio de pago: : Credito ");
    }
    else
    {
        puts("Medio de pago: : Todos");
    }
    printf("Cantidad de articulos:%d\n",aux.cantArticulos);
    puts("Estado del cliente : Activo");

}

void mostrarArbolInOrder(nodoArbol *Arbol)
{
    if (Arbol!=NULL)
    {
        mostrarArbolInOrder(Arbol->izq);
        verArbol(Arbol->p);
        mostrarArbolInOrder(Arbol->der);

    }
}

void mostrarArbolPreorder(nodoArbol *Arbol)
{
    if (Arbol!=NULL)
    {
        verArbol(Arbol->p);
        mostrarArbolPreorder(Arbol->izq);
        mostrarArbolPreorder(Arbol->der);
    }
}
void mostrarArbolPostorder(nodoArbol *Arbol)
{
    if (Arbol!=NULL)
    {
        mostrarArbolPostorder(Arbol->izq);
        mostrarArbolPostorder(Arbol->der);
        verArbol(Arbol->p);
    }
}


nodoArbol* PasarArchivoArbol(char nombre_archivo[],nodoArbol *Arbol)
{
    FILE * archi;
    archi=fopen(nombre_archivo,"rb");
    persona p;
    if(archi!=NULL)
    {
        while(fread(&p,sizeof(persona),1,archi) >0)
        {
            if(p.eliminado==0)
            {
                Arbol = insertar(Arbol,p);
            }

        }
    }
    fclose(archi);

    return Arbol;
}

nodoArbol * arbolIzq_nodoMasDer(nodoArbol *Arbol)
{
    nodoArbol * aux;
    if(Arbol->der == NULL)
    {
        aux = Arbol;
    }
    else
    {
        aux = arbolIzq_nodoMasDer(Arbol->der);
    }
    return aux;
}



nodoArbol * arbolDer_nodoMasIzq(nodoArbol *Arbol)
{
    nodoArbol * aux;

    if(Arbol->izq == NULL)
    {
        aux = Arbol;
    }
    else
    {
        aux = arbolDer_nodoMasIzq(Arbol ->izq);
    }
    return aux;
}


nodoArbol * borrarNodoArbol(nodoArbol * Arbol,char nombre[])
{
    if (Arbol != NULL)
    {
        if (strcmp(nombre,Arbol->p.nombres)>0)
        {
            Arbol->der = borrarNodoArbol(Arbol->der,nombre);
        }
        else if (strcmp(nombre,Arbol->p.nombres)<0)
        {
            Arbol->izq = borrarNodoArbol(Arbol->izq,nombre);
        }
        else
        {
            if (Arbol->izq != NULL)
            {
                Arbol->p = (arbolIzq_nodoMasDer(Arbol->izq))->p;
                Arbol->izq = borrarNodoArbol(Arbol->izq, Arbol->p.nombres);
            }
            else if (Arbol->der != NULL)
            {
                Arbol->p = (arbolDer_nodoMasIzq(Arbol->der))->p;
                Arbol->der = borrarNodoArbol(Arbol->der,Arbol->p.nombres);
            }
            else
            {
                free(Arbol);
                Arbol = NULL;
            }
        }

    }

    return Arbol;
}

void pasarDeArbolACajaPreorden(nodoArbol*arbol,caja cajin[])
{
    if(arbol!=NULL)
    {
        AgregarCliente(arbol,cajin);
        pasarDeArbolACajaPreorden(arbol->izq,cajin);
        pasarDeArbolACajaPreorden(arbol->der,cajin);
    }
}

void pasarDeArbolACajaInorden(nodoArbol*arbol, caja cajin[])
{
    if(arbol!=NULL)
    {
        pasarDeArbolACajaInorden(arbol->izq,cajin);
        AgregarCliente(arbol,cajin);
        pasarDeArbolACajaInorden(arbol->der,cajin);
    }
}

void pasarDeArbolACajaPosOrden(nodoArbol*arbol, caja cajin[])
{
    if(arbol!=NULL)
    {
        pasarDeArbolACajaPosOrden(arbol->izq,cajin);
        pasarDeArbolACajaPosOrden(arbol->der,cajin);
        AgregarCliente(arbol,cajin);
    }
}
