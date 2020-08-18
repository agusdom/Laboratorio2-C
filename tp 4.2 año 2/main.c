#include <stdio.h>
#include <stdlib.h>
#include "listas dobles.h"

nodos2*carga(nodos2*lista)
{
    nodos2*nuevo=NULL;
    char letra='s';
    int dato=0;
    while(letra=='s')
    {
       nuevo=nuevoDato();
       lista=ingresarFinal(lista,nuevo);


        printf("Desea continuar: s/n");
        fflush(stdin);
        scanf("%c",&letra);

    }
    return lista;
}

nodos2*borrar(nodos2*lista,nodos2*elemento)
{
    nodos2*borrada=NULL;
    nodos2*seg=NULL;
    if(lista!=NULL)
    {
        if(lista->dato==elemento->dato)
        {
            borrada=lista;
            lista=lista->ste;
            if(lista!=NULL)
            {
                borrada->ante=NULL;
            }
            free(borrada);
        }
        else
        {
            seg=lista->ste;
            while(seg!=NULL && lista->dato!=elemento->dato)
            {
                seg=seg->ste;
            }
            if(seg!=NULL)
            {
                nodos2*anteR=seg->ante;
                anteR->ste=seg->ste;
                if(seg->ste!=NULL)
                {
                    nodos2*sig=seg->ste;
                    sig->ante=anteR;

                }
                free(seg);
            }

        }
    }
    return lista;
}

nodos2*capicua(nodos2*lista)
{
    int flag=1;
    nodos2*ultimo=buscarUltimo(lista);
    while(lista!=NULL)
    {
        if(lista->dato!=ultimo->dato)
        {
            flag=0;
        }
        lista=lista->ste;
        ultimo=ultimo->ante;

    }
    return flag;
}


int main()
{
    nodos2*lista;
    lista=inicLista();
    lista=carga(lista);
    lista=borrar(lista,3);
    puts("lista con elemento borrado");
    recorrerYmostrar(lista);
    /*int r=capicua(lista);
    if(r==1)
    {
        printf("\nes capicua");
    }
    else
    {
        printf("\nno es capicua");
    }*/
    return 0;
}
