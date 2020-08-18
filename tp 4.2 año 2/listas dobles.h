#ifndef LISTAS_DOBLES_H_INCLUDED
#define LISTAS_DOBLES_H_INCLUDED

typedef struct
{
int dato;
struct nodos2 * ste;
struct nodos2 * ante;
}nodos2;

nodos2 * inicLista();
nodos2 *crearNodo(int dato);
nodos2 *agregarAlPrincipio(nodos2 * lista, nodos2 * nuevoNodo);
nodos2 *buscarUltimo(nodos2 * lista);
nodos2 *agregarAlFinal(nodos2 * lista, nodos2 *nuevoNodo);
void recorrerYmostrar(nodos2*lista);
nodos2 *insertarNodo(nodos2 * lista, nodos2 * nuevoNodo);
nodos2 * nuevoDato();


#endif // LISTAS_DOBLES_H_INCLUDED
