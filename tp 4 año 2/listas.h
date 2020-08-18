#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

typedef struct
{
    char nombre[20];
    int edad;
    struct nodo * siguiente;
} nodo;

nodo*iniclista();
nodo*crearnodo(char nombre[],int edad);
nodo*agregarppio(nodo*lista,nodo*nuevonodo);
nodo*buscar(nodo*lista,char nombre[20]);
nodo*buscarultimo(nodo*lista);
nodo*agregarultimo(nodo*lista,nodo*nuevonodo);
nodo*agregarenorden(nodo*lista,nodo*nuevonodo);
void recorrerYmostrar(nodo*lista);
nodo * borrarNodo(char nombre[20], nodo * lista);
nodo * borrarTodaLaLista(nodo * lista);
#endif // LISTAS_H_INCLUDED
