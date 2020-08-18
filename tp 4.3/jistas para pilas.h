#ifndef JISTAS_PARA_PILAS_H_INCLUDED
#define JISTAS_PARA_PILAS_H_INCLUDED

typedef struct
{
    int dato;
    struct nodos*siguiente;
} nodos;

nodos*iniclistas();
nodos*crearnodos(int dato);
nodos * nuevoDato();
nodos*agregarppios(nodos*lista,nodos*nuevonodo);
int buscarprimero(lista);
nodos * borrarprimerNodos(nodos * lista);
void recorrerYmostrarr(nodos*lista);



#endif // JISTAS_PARA_PILAS_H_INCLUDED
