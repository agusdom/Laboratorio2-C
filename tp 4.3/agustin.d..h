#ifndef AGUSTIN_D__H_INCLUDED
#define AGUSTIN_D__H_INCLUDED
typedef struct
{
int dato;
struct Nodo2 * ste;
struct Nodo2 * ante;
}Nodo2;

Nodo2 * inicLista();
Nodo2 * crearNodo(int dato);
Nodo2 * agregarAlPrincipio(Nodo2 * lista, Nodo2 * nuevoNodo);
Nodo2 * buscarUltimo(Nodo2 * lista);
Nodo2 * agregarAlFinal(Nodo2 * lista, Nodo2 *nuevoNodo);
Nodo2 * insertarNodo(Nodo2 * lista, Nodo2 * nuevoNodo);
void  mostra(Nodo2 * lista);

#endif // AGUSTIN_D__H_INCLUDED
