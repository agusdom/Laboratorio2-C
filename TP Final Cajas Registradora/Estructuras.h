//#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "string.h"
#include <windows.h>


//       ESTRUCTURA   USUARIOS           //


typedef struct
{
    int id;
    char nombre[30];
    char apellido[30];
    char usuario[20];
    int pass[2][5];
    int eliminado;
} usuario;

//Prototipado de funciones
void AltaUsuarios(char nombre_archivo[]);
void muestrauxusuarios(usuario a);
void MostrarUsuarios(char nom[]);
void modificacion_usuarios(char nom[],int id);
void Baja_usuarios(char nom[],int id);
void muestraauxlistadousuarios (usuario a);
void revivir_usuario (char nom[],int id);
int entry(char nombre_archivo[]);
int existente(char nombre_archivo[],char usu[]);
int cuenta_usuario(char nombre[50]);
void ListadoUsuarios();
void mostrarMatriz (int M[2][5]);



//          GENERAL          //
void mostrarMatriz (int M[2][5]);
void color(int x);
void gotoxy(int X,int Y);
int whereX();
int whereY();
void hidecursor(int ver);


//        ESTRUCTURA  PERSONAS          //

typedef struct
{
    int id;
    char apellido[30];
    char nombres [40];
    int tipoCliente;
    int medioPago;
    int cantArticulos;
    int tiempoEspera;
    int tiempoProcesado;
    int eliminado;
}persona;

//Prototipado de funciones
void AltaPersonas(char nombre_archivo[]);
int cuenta_personas(char nombre[50]);
void modificacion_personas(char nom[],int id);
void muestraauxlistadopersonas(persona a);
void ListadoPersonas();
void baja_personas(char nom[],int id);
void revivir_persona (char nom[],int id);
void MostrarPersonas(char nom[]);
void muestrauxpersonas(persona p);

// ESTRUCTURA ARBOLES

typedef struct nodoArbol
{
    persona p;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

nodoArbol *inicArbol();
nodoArbol *crearNodoA(persona Persona);
nodoArbol *insertar(nodoArbol *Arbol,persona Persona); //Inserta por nombre
void verArbol (persona aux);
nodoArbol* PasarArchivoArbol(char nombre[10],nodoArbol *Arbol);
nodoArbol * arbolDer_nodoMasIzq(nodoArbol *Arbol);
nodoArbol * arbolIzq_nodoMasDer(nodoArbol *Arbol);
nodoArbol * borrarNodoArbol(nodoArbol * Arbol,char nomb[40]);
void mostrarArbolPostorder(nodoArbol *Arbol);
void mostrarArbolPreorder(nodoArbol *Arbol);
void mostrarArbolInOrder(nodoArbol *Arbol);



//        ESTRUCTURA  LISTAS DOBLES //

typedef struct nodo
{
 persona cliente;
 struct nodo *sig;
 struct nodo *ante;
}nodo;

nodo *InicLista();
nodo *crearNodoDoble(persona cliente);
nodo *agregarP(nodo *lista,nodo *nuevo);
void mostrarListaDoble(nodo *lista);
nodo *buscarUltimo(nodo *lista);
nodo *agregarF(nodo *lista,nodo *nuevo);
nodo *buscarNodoDoble(nodo *lista,char nombre[10]);
nodo *borrarNodo(nodo *lista,char nomb[10]);
nodo *agregaOrdenadoPorCant(nodo *lista,nodo *nuevo);
nodo *agregaOrdenadoPorTipo(nodo *lista,nodo *nuevo);
nodo *BorrarPrimero(nodo *lista);
nodo *agregaOrdenadoPorTipoPRIORIDADES(nodo *lista,nodo *nuevo);



// ESTRUCTURA   MATRIZ //

void fCalculoInversa(double md[][2]);
int fDeterminante();
void fMatrizEncripting(int m2[][5],int mp[][5],int mDim);
int fPass2Matrix(char texto[],int matrizTexto[][5]);
void fMatrizEncrypting(int m2[][5],int mp[][5],int mDim);
int fCalculoDimension(int m[][5]);
void fDecrypting(char pass[],int matrizPass[][5]);
int fMatrizDecrypting(double m1[][2],int m2[][5],int mp[][5]);

//    ESTRUCTURA  FILAS  //

typedef struct
{
    struct nodo * inicio;
    struct nodo * fin;
} Fila;

void InicFila(Fila *filita);
void cargarFila(Fila * filita,persona cliente);
void agregar(Fila * filita,nodo *nuevo);
void mostrarFila(Fila *filita);
int filaVacia(Fila filita);
persona sacarDeFila(Fila * filita);
int contarValidosFila(Fila *filita);


//Cajas // ESTRUCTURAS_H_INCLUDED
typedef struct
{
    int nro_de_caja;
    char nombreCajero[40];
    int tipo_pago;
    int abiertaOcerrada;
    char algoritmoPlanificacion[30];
    Fila filita ;
} caja;
void pasarDeArbolACajaPreorden(nodoArbol*arbol,caja cajin[]);
void pasarDeArbolACajaInorden(nodoArbol*arbol,caja cajin[]);
void pasarDeArbolACajaPosOrden(nodoArbol*arbol,caja cajin[]);
void cargarcaja(caja Cajasuper[],caja Cajero[],int validos);
void Cajastotales(caja Cajero[]);
void cerrarcaja(caja Cajasuper[],int pos);
int abrircaja(caja cajin[], int pos);
void abrirAllCajas (caja caja[]);
void cerrarAllCajas(caja caja[]);
void MostrarCaja(caja Cajasuper[], int pos);
void mostrarcajasabiertas(caja Cajasuper[]);
int contarClientes(caja cajin[], int pos);
void agregar_FIFO(caja cajin[],int pos, nodo * nuevo);
void agregar_SRTF (caja cajin[],int pos, nodo * nuevo);
void agregar_PRIOR(caja cajin[],int pos, nodo * nuevo);
void agregar_RR (caja cajin[],int pos, nodo * nuevo);
void AgregarCliente(nodoArbol * arbol, caja cajin[]);
void InsertarCliente (caja cajin[], nodo * nuevo, int tiempo);
void TiempoDeEspera (Fila * fila);
void TiempoDeEsperaRoundRobin (Fila * fila);
void TiempoDeEjecucion (Fila * fila);
void TiemposDeEjecucionEnTodas (caja cajin[]);
int SumaTiempoDeEjecucion (Fila * fila);
int SumaTiempoDeEspera(Fila * fila);
float PromedioDeEspera (Fila * fila);
float PromedioDeEjecucion (Fila * fila);
void atender(caja cajin[],int pos);
void Procesar(caja cajin[]);
void ProcesarRR(caja cajin[],int pos);
persona subProgramaAgregarPersona();
void CargarClienteNuevo(caja cajin[]);
void InsertarFIFO(caja cajin[], int pos, nodo * nuevo, int tiempo);
void InsertarSRTF(caja cajin[], int pos, nodo * nuevo, int tiempo);
void InsertarRR(caja cajin[], int pos, nodo * nuevo, int tiempo);
void InsertarSJF(caja cajin[], int pos, nodo * nuevo, int tiempo);
void InsertarPrioridadesApropiativo(caja cajin[], int pos, nodo * nuevo, int tiempo);
void InsertarPrioridadesNoApropiativo(caja cajin[], int pos, nodo * nuevo, int tiempo);
void ReiniciarFilas(caja cajin[]);
int busquedaCaja(caja Cajasuper[],int tipo_d_pago);

//MENUS
int menu_principal();
int ABMusuarios();
int ABMpersonas();
int MenuArbol();
int MenuOrdenArbol();
