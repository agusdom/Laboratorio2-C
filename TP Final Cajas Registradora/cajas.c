#include "Estructuras.h"
const int validos=12;

void cargarcaja(caja Cajasuper[],caja Cajero[],int validos)
{
    printf("Ingrese numero de caja:");
    fflush(stdin);
    scanf("%d",&Cajasuper[validos].nro_de_caja);
    printf("Ingrese nombre del cajero:");
    fflush(stdin);
    scanf("%s",&Cajero[validos].nombreCajero);
    printf("Ingrese tipo de pago de la caja:");
    fflush(stdin);
    scanf("%d",&Cajasuper[validos].tipo_pago);
    printf("Ingrese tipo de algoritmo de la caja:");
    fflush(stdin);
    scanf("%s",&Cajasuper[validos].algoritmoPlanificacion);
    Cajasuper[validos].abiertaOcerrada=1;
    InicFila(&Cajasuper[validos].filita);
}

void Cajastotales(caja Cajero[])
{
    strcpy(Cajero[0].nombreCajero,"Ruben Gomez");
    Cajero[0].nro_de_caja=1;
    Cajero[0].abiertaOcerrada=0;
    Cajero[0].tipo_pago=1;
    strcpy(Cajero[0].algoritmoPlanificacion,"FIFO");
    InicFila(&Cajero[0].filita);

    ///REVISAR
    strcpy(Cajero[1].nombreCajero,"Silvana Flores");
    Cajero[1].nro_de_caja=2;
    Cajero[1].tipo_pago=2;
    strcpy(Cajero[1].algoritmoPlanificacion,"SJF no Apropiativo");
    Cajero[1].abiertaOcerrada=0;
    InicFila(&Cajero[1].filita);

    ///REVISAR
    strcpy(Cajero[2].nombreCajero,"Evangelina Pereyra");
    Cajero[2].nro_de_caja=3;
    Cajero[2].tipo_pago=3;
    strcpy(Cajero[2].algoritmoPlanificacion,"SRTF");
    Cajero[2].abiertaOcerrada=0;
    InicFila(&Cajero[2].filita);

    strcpy(Cajero[3].nombreCajero,"Mercedes Arce");
    Cajero[3].nro_de_caja=4;
    Cajero[3].tipo_pago=2;
    strcpy(Cajero[3].algoritmoPlanificacion,"Prioridades Apropiativo");
    Cajero[3].abiertaOcerrada=0;
    InicFila(&Cajero[3].filita);

    strcpy(Cajero[4].nombreCajero,"Manuel Taranto");
    Cajero[4].nro_de_caja=5;
    Cajero[4].tipo_pago=1;
    strcpy(Cajero[4].algoritmoPlanificacion,"Prioridades no Apropiativo");
    Cajero[4].abiertaOcerrada=0;
    InicFila(&Cajero[4].filita);

    strcpy(Cajero[5].nombreCajero,"Camila Esteban");
    Cajero[5].nro_de_caja=6;
    Cajero[5].tipo_pago=3;
    strcpy(Cajero[5].algoritmoPlanificacion,"RR");
    Cajero[5].abiertaOcerrada=0;
    InicFila(&Cajero[5].filita);

    strcpy(Cajero[6].nombreCajero,"Antonio Santos");
    Cajero[6].nro_de_caja=7;
    Cajero[6].tipo_pago=3;
    strcpy(Cajero[6].algoritmoPlanificacion,"RR");
    Cajero[6].abiertaOcerrada=0;
    InicFila(&Cajero[6].filita);

    strcpy(Cajero[7].nombreCajero,"Sebastian Seta");
    Cajero[7].nro_de_caja=8;
    Cajero[7].tipo_pago=2;
    strcpy(Cajero[7].algoritmoPlanificacion,"Prioridades Apropiativo");
    Cajero[7].abiertaOcerrada=0;
    InicFila(&Cajero[7].filita);

    strcpy(Cajero[8].nombreCajero,"Andres Scarpitta");
    Cajero[8].nro_de_caja=9;
    Cajero[8].tipo_pago=1;
    strcpy(Cajero[8].algoritmoPlanificacion,"FIFO");
    Cajero[8].abiertaOcerrada=0;
    InicFila(&Cajero[8].filita);

    strcpy(Cajero[9].nombreCajero,"Emmanuel Marin");
    Cajero[9].nro_de_caja=10;
    Cajero[9].tipo_pago=1;
    strcpy(Cajero[9].algoritmoPlanificacion,"Prioridades no Apropiativo");
    Cajero[9].abiertaOcerrada=0;
    InicFila(&Cajero[9].filita);

    strcpy(Cajero[10].nombreCajero,"Rosalia Vaccaro");
    Cajero[10].nro_de_caja=11;
    Cajero[10].tipo_pago=2;
    strcpy(Cajero[10].algoritmoPlanificacion,"SJF no Apropiativo");
    Cajero[10].abiertaOcerrada=0;
    InicFila(&Cajero[10].filita);

    strcpy(Cajero[11].nombreCajero,"Pepe Suarez");
    Cajero[11].nro_de_caja=12;
    Cajero[11].tipo_pago=3;
    strcpy(Cajero[11].algoritmoPlanificacion,"SRTF");
    Cajero[11].abiertaOcerrada=0;
    InicFila(&Cajero[11].filita);
}

void cerrarcaja(caja Cajasuper[],int pos)
{
    int i = 0;
    while (i < 12)
    {
        if(Cajasuper[i].nro_de_caja == pos)
        {
            if (Cajasuper[i].filita.inicio != NULL)
            {
                printf("\nLa caja contiene datos, no se puede cerrar \n",pos);
            }
            else
            {
                if (Cajasuper[i].abiertaOcerrada == 0)
                {
                    Cajasuper[i].abiertaOcerrada = 1;
                    printf("Caja %d cerrada con exito!\n",pos);
                }
                else
                {
                    if(Cajasuper[i].abiertaOcerrada == 1)
                    {
                        printf("\nLa caja ya esta cerrada\n",pos);
                    }
                }
            }
        }
        i++;
    }
}
int abrircaja(caja cajin[], int pos)
{
    int rta = 1;

    if (pos != 0 && rta < 12) /// si esta entre 0-12
    {
        if (cajin[pos-1].abiertaOcerrada == 1) //si la caja esta cerrada
        {
            cajin[pos-1].abiertaOcerrada = 0; // procedo a abrirla
        }
        else //si esta abierta, rta es 0
        {
            rta = 0;
        }
        printf("Caja %d abierta con exito!\n",pos);
    }
    else // si no esta entre 0-12, es decir, si no es valido, retorno -1 xq ya uso el 0
    {
        rta = -1;
    }

    return rta;
}

void abrirAllCajas (caja caja[])
{
    int i = 0;
    while (i<12)
    {
        if(caja[i].abiertaOcerrada == 1)
        {
            caja[i].abiertaOcerrada = 0;
        }
        i++;
    }
}

void cerrarAllCajas(caja caja[])
{
    int a=0;
    while(a<12)
    {
        cerrarcaja(caja,a+1);
        a++;
    }
}

void MostrarCaja(caja Cajasuper[], int pos)
{
    printf("*************************************************** CAJA N%c : %d ***********************************\n",248,Cajasuper[pos].nro_de_caja);
    printf("\n\nNombre del cajero: %s",Cajasuper[pos].nombreCajero);
    if(Cajasuper[pos].nro_de_caja==1 || Cajasuper[pos].nro_de_caja==9)
    {
        printf("\nAlgoritmo: FIFO\n");
    }
    else if(Cajasuper[pos].nro_de_caja==2 || Cajasuper[pos].nro_de_caja==11)
    {
        printf("\nAlgoritmo: SJF\n");
    }
    else if(Cajasuper[pos].nro_de_caja==3 || Cajasuper[pos].nro_de_caja==12)
    {
        printf("\nAlgoritmo: SRTF\n");
    }
    else if(Cajasuper[pos].nro_de_caja==4 || Cajasuper[pos].nro_de_caja==8)
    {
        printf("\nAlgoritmo: Prioridades Apropiativo\n");
    }
    else if(Cajasuper[pos].nro_de_caja==5 || Cajasuper[pos].nro_de_caja==10)
    {
        printf("\nAlgoritmo: Prioridades NO Apropiativo\n");
    }
    else if(Cajasuper[pos].nro_de_caja==6 || Cajasuper[pos].nro_de_caja==7)
    {
        printf("\nAlgoritmo: Round Robin\n");
    }

    if(Cajasuper[pos].tipo_pago == 1)
    {
        printf("\nTipo de Pago: Efectivo\n");
    }
    else if (Cajasuper[pos].tipo_pago == 2)
    {
        printf("\nTipo de Pago: Credito\n");
    }
    else
    {
        printf("\nTipo de Pago: Todos\n");
    }

    if(Cajasuper[pos].abiertaOcerrada==0)
    {
        printf("\nCaja abierta");
    }
    else
    {
        printf("\nCaja cerrada");
    }
    printf("\nFILA DE GENTE:\n\n");
    mostrarFila(&Cajasuper[pos].filita);
    printf("****************************************************************************************************\n\n\n\n\n\n");
}

void mostrarcajasabiertas(caja Cajasuper[])
{
    int a=0;
    while(a<12)
    {
        MostrarCaja(Cajasuper,a);
        a++;
    }
}

void ReiniciarFilas(caja cajin[])
{
    int i = 0;

    while (i<validos)
    {
        InicFila(&cajin[i].filita);
        i++;
    }
}

int contarClientes(caja cajin[], int pos)
{
    int cant=0;

    Fila aux = cajin[pos].filita;
    nodo * auxiliar = aux.inicio;

    while(auxiliar != NULL)
    {
        cant++;
        auxiliar = auxiliar->sig;
    }
    return cant;
}
int busquedaCaja (caja cajin[], int tipo_de_pago)
{
    int pos=0;
    int i = validos;
    int cant=0;
    int cant2=0;
    int flag = 0;

    while (i > -1)                      /// Mientras que no se termine de recorrer el arreglo
    {
        if(cajin[i].abiertaOcerrada==0)         /// Si la caja está abierta
        {
            if ((cajin[i].tipo_pago == tipo_de_pago) || (cajin[i].tipo_pago == 3))      /// Si el tipo de pago del cliente coincide con el de la caja, o si la caja abarca Todos
            {
                if (flag == 0)
                {
                    cant = contarClientes(cajin,i);     /// Cuenta los clientes de la caja A
                    flag = 1;
                }

                cant2=contarClientes(cajin,i);          /// Cuenta los clientes de la caja B
                if(cant2<=cant)                         /// Compara ambas cajas (cantidades)
                {
                    cant=cant2;                         /// Si la A está mas vacia que la B convierte a esta última en la caja(posición) a retornar
                    pos=i;                              /// Cant toma la cantidad de la caja más vacía para su próxima comparación
                }
            }
        }

        i--;                /// Recorrer el arreglo
    }
    return pos;             /// Retorna la posición de la caja óptima
}

void agregar_FIFO(caja cajin[],int pos, nodo * nuevo)
{
    agregar(&(cajin[pos].filita),nuevo);
    nodo*ultimo=buscarUltimo(cajin[pos].filita.inicio);
    cajin[pos].filita.fin=ultimo;
    TiempoDeEspera(&cajin[pos].filita);
}

void agregar_SRTF (caja cajin[],int pos, nodo * nuevo)
{
    cajin[pos].filita.inicio=agregaOrdenadoPorCant((cajin[pos].filita.inicio),nuevo);
    nodo * ultimo = buscarUltimo(cajin[pos].filita.inicio);
    cajin[pos].filita.fin = ultimo;
    TiempoDeEspera(&cajin[pos].filita);
}

void agregar_SJF (caja cajin[],int pos, nodo * nuevo)
{
    cajin[pos].filita.inicio=agregaOrdenadoPorCant((cajin[pos].filita.inicio),nuevo);
    nodo * ultimo = buscarUltimo(cajin[pos].filita.inicio);
    cajin[pos].filita.fin = ultimo;
    TiempoDeEspera(&cajin[pos].filita);
}

void agregar_PRIOR(caja cajin[],int pos, nodo * nuevo)
{
    cajin[pos].filita.inicio=agregaOrdenadoPorTipo((cajin[pos].filita.inicio),nuevo);
    nodo * ultimo = buscarUltimo(cajin[pos].filita.inicio);
    cajin[pos].filita.fin = ultimo;
    TiempoDeEspera(&cajin[pos].filita);
}

void agregar_RR (caja cajin[],int pos, nodo * nuevo)
{
    agregar((&cajin[pos].filita),nuevo);
   nodo * ultimo = buscarUltimo(cajin[pos].filita.inicio);
    cajin[pos].filita.fin = ultimo;
    TiempoDeEsperaRoundRobin(&cajin[pos].filita);

}
void AgregarCliente(nodoArbol * arbol, caja cajin[])
{
    persona p = arbol->p;
    nodo * aux = crearNodoDoble(p);
    int pos = busquedaCaja(cajin,p.medioPago);


    if(cajin[pos].abiertaOcerrada==0)
    {
        if (strcmp(cajin[pos].algoritmoPlanificacion,"FIFO")==0)
        {
            agregar_FIFO(cajin,pos,aux);
        }
        if (strcmp(cajin[pos].algoritmoPlanificacion,"SRTF")==0)
        {
            agregar_SRTF(cajin,pos,aux);
        }
        if (strcmp(cajin[pos].algoritmoPlanificacion,"Prioridades Apropiativo")==0)
        {
            agregar_PRIOR(cajin,pos,aux);
        }
        if (strcmp(cajin[pos].algoritmoPlanificacion,"RR")==0)
        {
            agregar_RR(cajin,pos,aux);
        }
        if (strcmp(cajin[pos].algoritmoPlanificacion,"SJF no Apropiativo")==0)
        {
            agregar_SJF(cajin,pos,aux);
        }
        if (strcmp(cajin[pos].algoritmoPlanificacion,"Prioridades no Apropiativo")==0)
        {
            agregar_PRIOR(cajin,pos,aux);
        }
    }
}

void InsertarCliente (caja cajin[], nodo * nuevo, int tiempo)
{
    int pos=0;
    //int pos = busquedaCaja(cajin,nuevo->cliente.medioPago);
    printf("\n\tCAJAS DEL SUPERMERCADO:\n\t");
    printf("1: FIFO(Efectivo), 2: SJF(Credito), 3: SRTF(Todos), 4: PA(Credito), 5: PNP(Efectivo), 6: RR(Todos)");
    printf("\n        7: RR(Todos), 8: PA(Credito), 9: FIFO(Efectivo), 10: PNP(Efectivo), 11: SJF(Credito), 12: SRTF(Todos)");
    printf("\n\n");
    printf("Ingrese la caja a cargar: ");
    fflush(stdin);
    scanf("%d",&pos);
    pos--;
    system("cls");



    if(cajin[pos].abiertaOcerrada==0)
    {
        if ((cajin[pos].tipo_pago == nuevo->cliente.medioPago) || (cajin[pos].tipo_pago == 3) || (nuevo->cliente.medioPago== 3))
        {
            printf("\n\t\t ** CLIENTE AUN NO AGREGADO **\n");
            MostrarCaja(cajin,pos);
            system("pause");
            if (strcmp(cajin[pos].algoritmoPlanificacion,"FIFO")==0)
            {
                InsertarFIFO(cajin,pos,nuevo,tiempo);
                system("cls");
                printf("\n\t\t ** CLIENTE AGREGADO **\n");
                MostrarCaja(cajin,pos);
                system("pause>null");
            }
            if (strcmp(cajin[pos].algoritmoPlanificacion,"SRTF")==0)
            {
                InsertarSRTF(cajin,pos,nuevo,tiempo);
                system("cls");
                printf("\n\t\t ** CLIENTE AGREGADO **\n");
                MostrarCaja(cajin,pos);
                system("pause>null");
            }
            if (strcmp(cajin[pos].algoritmoPlanificacion,"Prioridades no Apropiativo")==0)
            {
                InsertarPrioridadesNoApropiativo(cajin,pos,nuevo,tiempo);
                system("cls");
                printf("\n\t\t ** CLIENTE AGREGADO **\n");
                MostrarCaja(cajin,pos);
                system("pause>null");
            }
            if (strcmp(cajin[pos].algoritmoPlanificacion,"RR")==0)
            {
                InsertarRR(cajin,pos,nuevo,tiempo);
                system("cls");
                printf("\n\t\t ** CLIENTE AGREGADO **\n");
                MostrarCaja(cajin,pos);
                system("pause>null");
            }
            if(strcmp(cajin[pos].algoritmoPlanificacion,"SJF no Apropiativo")==0)
            {
                InsertarSJF(cajin,pos,nuevo,tiempo);
                system("cls");
                printf("\n\t\t ** CLIENTE AGREGADO **\n");
                MostrarCaja(cajin,pos);
                system("pause>null");
            }
            if(strcmp(cajin[pos].algoritmoPlanificacion,"Prioridades Apropiativo")==0)
            {
                InsertarPrioridadesApropiativo(cajin,pos,nuevo,tiempo);
                system("cls");
                printf("\n\t\t ** CLIENTE AGREGADO **\n");
                MostrarCaja(cajin,pos);
                system("pause>null");
            }
        }
        else
        {
            printf("\n\n\t*****LA CAJA (%d) NO COINCIDE CON EL MEDIO DE PAGO DEL CLIENTE*****\t\n\n",pos+1);
            printf("\n\n   SELECCIONE OTRA CAJA A CONTINUACION:\n\n");
            InsertarCliente(cajin,nuevo,tiempo);
        }
    }
    else
    {
        printf("\n\n\t*****LA CAJA (%d) ESTA CERRADA*****\t\n\n",pos+1);
        printf("\n\n  SELECCIONE OTRA CAJA A CONTINUACION:\n\n");
        InsertarCliente(cajin,nuevo,tiempo);
    }

}

void TiempoDeEspera (Fila * fila)
{
    nodo * aux = fila->inicio;
    int tiempo=0;

    while (aux->sig != NULL)
    {
        tiempo = aux->cliente.cantArticulos + tiempo;
        nodo * seg = aux->sig;
        seg->cliente.tiempoEspera = tiempo ;
        aux = aux->sig;
    }
}

void TiempoDeEsperaRoundRobin (Fila * fila)
{
    nodo * aux = fila->inicio;
    int tiempo = 0;
    int quantum = 4;

    aux->cliente.tiempoEspera = 0;

    while (aux->sig != NULL)
    {

        if (aux->cliente.cantArticulos < 4 && aux->cliente.cantArticulos >= 0)
        {
            tiempo = aux->cliente.cantArticulos + tiempo;
        }
        else
        {
            tiempo = quantum + tiempo;
        }

        nodo * seg = aux->sig;
        seg->cliente.tiempoEspera = tiempo;
        aux = aux-> sig;
    }
}

void TiempoDeEjecucion (Fila * fila)
{
    nodo * aux = fila->inicio;
    while (aux != NULL)
    {
        if(aux->cliente.cantArticulos > 0)
        {
            aux->cliente.tiempoProcesado = aux->cliente.tiempoProcesado + aux->cliente.cantArticulos;
        }
        aux->cliente.cantArticulos = 0;
        aux = aux->sig;
    }
}

void TiemposDeEjecucionEnTodas(caja cajin[])
{
    int i = 0;
    while (i<12)
    {
        TiempoDeEjecucion(&cajin[i].filita);
        i++;
    }
}

int SumaTiempoDeEjecucion (Fila * fila)
{
    int suma = 0;
    nodo * aux = fila->inicio;
    while (aux != NULL)
    {
        suma = suma + aux->cliente.tiempoProcesado;
        aux = aux->sig;
    }
    return suma;
}

int SumaTiempoDeEspera(Fila * fila)
{
    int suma = 0;
    nodo * aux=fila->inicio;
    while(aux!=NULL)
    {
        suma = suma + aux->cliente.tiempoEspera;
        aux = aux->sig;
    }
    return suma;
}

float PromedioDeEspera (Fila * fila)
{
    int suma = SumaTiempoDeEspera (fila);
    int cant=0;
    float promedio = 0;
    nodo * aux = fila->inicio;

    while(aux != NULL)
    {
        aux = aux->sig;
        cant++;
    }

    promedio = (float)suma / (float)cant;
    return promedio;
}

float PromedioDeEjecucion (Fila * fila)
{
    int suma = SumaTiempoDeEjecucion (fila);
    int cant=1;
    float promedio = 0;
    nodo * aux = fila->inicio;

    while(aux->sig != NULL)
    {
        aux = aux->sig;
        cant++;
    }

    promedio = (float)suma / (float)cant;
    return promedio;
}

void atender(caja cajin[],int pos)
{
    if(cajin[pos].abiertaOcerrada==0)
    {
        float promedioEjecucion = PromedioDeEjecucion(&cajin[pos].filita);
        float PromedioEspera = PromedioDeEspera(&cajin[pos].filita);
        printf("\n\tPromedio Ejecucion: %.2f\n",promedioEjecucion);
        printf("\n\tPromedio Espera: %.2f\n",PromedioEspera);
    }
    else
    {
        printf("\n\n");
        printf("\t***CAJA CERRADA***\t");
        printf("\n\n");
    }

}


void Procesar (caja cajin[])
{
    int poscaja = 0;
    int i,x,y;
    printf("\n\n Que caja desea procesar? ");
    fflush(stdin);
    scanf("%d",&poscaja);

    if (poscaja <= 0 || poscaja >= 13)
    {
        printf("\nERROR! La caja ingresada no existe\n");
        system("pause");
    }
    if (poscaja<=5 || poscaja>=8)
    {
        gotoxy(50,20);
        printf("CALCULANDO PROMEDIO");
        for(i=1; i<120; i++)
        {
            gotoxy(i,13);
            printf("%c",177);

            for(x=50; x<70; x++)
            {
                for(y=1; y<70; y++)
                {
                    gotoxy(y,24);
                }
            }
        }
        system("cls");
        MostrarCaja(cajin,poscaja-1);
        printf("**************** CAJA N%c : %d ATENDIDA***********************************\n",248,cajin[poscaja-1].nro_de_caja);
        TiempoDeEjecucion(&cajin[poscaja-1].filita);
        atender(cajin,poscaja-1);
        MostrarCaja(cajin,poscaja-1);
        printf("******************************************************************\n");
        system("pause");
    }
    if(poscaja == 7 || poscaja == 6)
    {
        ProcesarRR(cajin,poscaja-1);
    }
}

void ProcesarRR (caja cajin[],int pos)
{
    int i,x,y;
    float promedioEspera = PromedioDeEspera (&cajin[pos].filita);
    nodo * primero = cajin[pos].filita.inicio;
    int cant = SumaArticulos(cajin[pos].filita.inicio);
    persona aBorrar;
    int quantum = 4;
    MostrarCaja(cajin,pos);
    system("pause");
    system("cls");

    while (cant > 0) //mientras que tenga articulos
    {
        if (primero->cliente.cantArticulos > 0) //Si tiene articulos para procesar
        {
            while (primero->cliente.cantArticulos > 0)
            {
                if (primero->cliente.cantArticulos >= quantum) //si la cant de art es mayor o igual al quantum (4)
                {
                    primero->cliente.tiempoProcesado = primero->cliente.tiempoProcesado + quantum; //el tiempoProcesado es el quantum en la primera pasada,voy sumando de a 4
                    primero->cliente.cantArticulos = primero->cliente.cantArticulos - quantum; //la cant de art se vuelve, cantidad art menos 4, primera pasada le resto 4
                    cant = cant - quantum; //a la suma de sus articulos le resto 4 por cada pasada
                }
                else // si la cant de art es menor al quantum
                {
                    cant = cant - primero->cliente.cantArticulos; // la suma de sus art le resto la cant de art del primer cliente
                    primero->cliente.tiempoProcesado = primero->cliente.tiempoProcesado + primero->cliente.cantArticulos; //el tiempo de procesado es la cant de articulos
                    primero->cliente.cantArticulos = 0; // no tiene mas articulos, le seteo un 0 (para que si por ej: tengo 3 art, no le ponga -1)
                }
                aBorrar = sacarDeFila(&cajin[pos].filita); // lo saco de la final
                agregar((&cajin[pos].filita),crearNodoDoble(aBorrar)); // y lo agrego al final de la misma
                primero = cajin[pos].filita.inicio; // hago el enlace con el primero again
                TiempoDeEsperaRoundRobin(&cajin[pos].filita); // calculo el tiempo de espera RR
                if (cant > 0) // si hay art por procesar muestro la caja y presiono enter para una nueva pasada
                {
                    MostrarCaja(cajin,pos);
                    system("pause");
                    system("cls");
                }
            }
        }
        else // si no tiene articulos para procesar, lo manda al final de la fila directamente
        {
            aBorrar = sacarDeFila(&cajin[pos].filita);
            agregar(&cajin[pos].filita,crearNodoDoble(aBorrar));
            primero = cajin[pos].filita.inicio;
        }
    }
    system("pause");
    system("cls");
    gotoxy(50,20);
    printf("CALCULANDO PROMEDIO");
    for(i=1; i<120; i++)
    {
        gotoxy(i,13);
        printf("%c",177);

        for(x=50; x<70; x++)
        {
            for(y=1; y<70; y++)
            {
                gotoxy(y,24);
            }
        }
    }//calcula el promedio una vez que proceso todos los articulos-clientes
    system("cls");
    float promedioEjecucion = PromedioDeEjecucion(&cajin[pos].filita);
    printf("**************** CAJA N%c : %d ***********************************\n",248,cajin[pos].nro_de_caja);
    printf("\n\tNumero de Caja: %d\n",cajin[pos].nro_de_caja);
    printf("\n\tPromedio Ejecucion: %.2f\n",promedioEjecucion);
    printf("\n\tPromedio Espera: %.2f\n",promedioEspera);
    printf("******************************************************************\n");
    system("pause");

}
persona subProgramaAgregarPersona()
{
    persona p;
    printf(" Ingrese Nombre: ");
    fflush(stdin);
    scanf("%s", p.nombres);
    printf(" Ingrese Apellido: ");
    fflush(stdin);
    scanf("%s", p.apellido);
    printf(" Ingrese Cantidad de articulos: ");
    fflush(stdin);
    scanf("%d", &p.cantArticulos);
    printf(" Ingrese Tipo de Cliente (1.Embarazada/2.Jubilado/3.Comun): ");
    fflush(stdin);
    scanf("%d", &p.tipoCliente);
    printf(" Ingrese Tipo de Pago (1.Efectivo/2.Credito o Debito/3.Todos): ");
    fflush(stdin);
    scanf("%d",&p.medioPago);
    p.tiempoEspera = 0;
    p.tiempoProcesado = 0;
    return p;
}

void CargarClienteNuevo (caja cajin[])
{
    char control = 's';
    persona p;
    int tiempo = 0;

    printf("\t\nDesea Ingresar un cliente? (s/n): ");
    fflush(stdin);
    scanf("%c", &control);

    if (control == 's')
    {
        system("cls");
        printf("\n");
        p = subProgramaAgregarPersona();
        nodo * nuevo = crearNodoDoble(p);
        printf("\n\n");
        printf("     ***CLIENTE A INGRESAR***");
        printf("\n\n");
        mostrarListaDoble(nuevo);
        printf("\n");
        printf(" Ingrese el tiempo en el quiere insertar al cliente: ");
        fflush(stdin);
        scanf("%d", &tiempo);
        InsertarCliente (cajin,nuevo,tiempo);
    }
}

void InsertarFIFO (caja cajin[], int pos, nodo * nuevo, int tiempo)
{
    nodo * aux = cajin[pos].filita.inicio; // enlace al inicio de la caja
    nodo * ultimo = cajin[pos].filita.fin; // enlace al final de la caja

    while (aux != NULL) //mientras tenga caja
    {
        if (aux->cliente.cantArticulos < tiempo) //si la cant de art del cliente es menor al tiempo
        {
            aux->cliente.tiempoProcesado = aux->cliente.cantArticulos; //la cant de art es el tiempo procesado
            tiempo = tiempo - aux->cliente.cantArticulos;//el tiempo es la cant de articulos menos el tiempo
            aux->cliente.cantArticulos = 0;//y la cant de art es 0, osea q ya proceso
        }
        else // si la cant de art es mayor al tiempo
        {
            aux->cliente.cantArticulos = aux->cliente.cantArticulos - tiempo; // le resto el tiempo a la cant de art. Si tengo tiempo 10 y 20 art= los art restantes seran 10
            aux->cliente.tiempoProcesado = tiempo; // y el tiempo de procesado es
            tiempo = 0;
        }
        aux = aux->sig;
    }
    agregar_FIFO(cajin,pos,nuevo);
}

void InsertarSRTF (caja cajin[], int pos, nodo * nuevo, int tiempo)
{
    nodo * ultimo = cajin[pos].filita.fin;
    nodo * aux = cajin[pos].filita.inicio;

    if (nuevo->cliente.cantArticulos > ultimo->cliente.cantArticulos)
    {
        ultimo->sig = nuevo;
        cajin[pos].filita.fin = nuevo;
    }
    else
    {
        while (aux != NULL)
        {
            if (aux->cliente.cantArticulos < tiempo)
            {
                aux->cliente.tiempoProcesado = aux->cliente.cantArticulos;
                tiempo = tiempo - aux->cliente.cantArticulos;
                aux->cliente.cantArticulos = 0;
            }
            else
            {
                aux->cliente.cantArticulos = aux->cliente.cantArticulos - tiempo;
                aux->cliente.tiempoProcesado = tiempo;
                tiempo = 0;
            }
            aux = aux->sig;
        }
        cajin[pos].filita.inicio = agregaOrdenadoPorCant(cajin[pos].filita.inicio,nuevo);

    }
    TiempoDeEspera(&cajin[pos].filita);
}

void InsertarPrioridadesApropiativo (caja cajin[],int pos,nodo * nuevo,int tiempo)
{
    nodo * ultimo = cajin[pos].filita.fin;                                     /// Asigna el primer y ultimo nodo de la fila
    nodo * aux = cajin[pos].filita.inicio;

    if (nuevo->cliente.tipoCliente >= ultimo->cliente.tipoCliente)      /// Si el tipo de cliente nuevo es mayor o igual que el ultimo
    {
        while (tiempo != 0)
        {
            if (aux->cliente.cantArticulos < tiempo)            ///Si la cantidad de articulos es menor que el tiempo a ingresar
            {
                aux->cliente.tiempoProcesado = aux->cliente.cantArticulos;
                tiempo = tiempo - aux->cliente.cantArticulos;               /// Procesar al primer cliente de la fila y al tiempo
                                                                            /// se le resta la cantidad de articulos
                aux->cliente.cantArticulos = 0;
            }
            else
            {
                aux->cliente.cantArticulos = aux->cliente.cantArticulos - tiempo;   /// Si el tiempo es menor, se le resta a la cantidad
                                                                                    /// de articulos y se aplica el tiempo procesado
                aux->cliente.tiempoProcesado = tiempo;
                tiempo = 0;
            }

            if(tiempo != 0)
            {
                aux = aux->sig;     ///Pasa el puntero al segundo de la fila si el primero agotó sus articulos
            }


            ultimo->sig = nuevo;
            cajin[pos].filita.fin = nuevo;      ///Inserta el cliente nuevo al final
        }
    }



    else
    {
        while (tiempo != 0)
        {
            if (aux->cliente.cantArticulos < tiempo)
            {
                aux->cliente.tiempoProcesado = aux->cliente.cantArticulos;
                tiempo = tiempo - aux->cliente.cantArticulos;
                aux->cliente.cantArticulos = 0;
            }
            else
            {
                aux->cliente.cantArticulos = aux->cliente.cantArticulos - tiempo;
                aux->cliente.tiempoProcesado = tiempo;
                tiempo = 0;
            }

            if(tiempo != 0)
            {
                aux = aux->sig;
            }
        }

    cajin[pos].filita.inicio = agregaOrdenadoPorTipoPRIORIDADES(cajin[pos].filita.inicio,nuevo);
    }
    TiempoDeEspera(&cajin[pos].filita);
}
void InsertarPrioridadesNoApropiativo(caja cajin[],int pos,nodo * nuevo,int tiempo)
{
    nodo * ultimo = cajin[pos].filita.fin;                                     /// Asigna el primer y ultimo nodo de la fila
    nodo * aux = cajin[pos].filita.inicio;

    if (nuevo->cliente.tipoCliente >= ultimo->cliente.tipoCliente)      /// Si el tipo de cliente nuevo es mayor o igual que el ultimo (No apropiativo)
    {
        while (tiempo != 0)
        {
            if (aux->cliente.cantArticulos < tiempo)            ///Si la cantidad de articulos es menor que el tiempo a ingresar
            {
                aux->cliente.tiempoProcesado = aux->cliente.cantArticulos;
                tiempo = tiempo - aux->cliente.cantArticulos;               /// Procesar al primer cliente de la fila y al tiempo se le resta la cantidad de articulos
                aux->cliente.cantArticulos = 0;
            }
            else
            {
                aux->cliente.cantArticulos = aux->cliente.cantArticulos - tiempo;   /// Si el tiempo es menor, se le resta a la cantidad de articulos y se aplica el tiempo procesado
                aux->cliente.tiempoProcesado = tiempo;
                tiempo = 0;
            }

            if(tiempo != 0)
            {
                aux = aux->sig;     ///Pasa el puntero al segundo de la fila si el primero agotó sus articulos
            }


            ultimo->sig = nuevo;
            cajin[pos].filita.fin = nuevo;      ///Inserta el cliente nuevo al final
        }
    }



    else
    {
        while (tiempo != 0)
        {
            if (aux->cliente.cantArticulos < tiempo)
            {
                aux->cliente.tiempoProcesado = aux->cliente.cantArticulos;
                tiempo = tiempo - aux->cliente.cantArticulos;
                aux->cliente.cantArticulos = 0;
            }
            else
            {
                aux->cliente.cantArticulos = aux->cliente.cantArticulos - tiempo;
                aux->cliente.tiempoProcesado = tiempo;
                tiempo = 0;
            }

            if(tiempo != 0)
            {
                aux = aux->sig;
            }
        }

        /*  aux->sig = agregaOrdenadoPorTipo(aux->sig,nuevo);       /// Agrega por tipo en el nodo siguiente al ultimo procesado
           nodo * aux2 = cajin[pos].filita.inicio;                                                   /// Asigno un nodo al inicio de la fila
           aux2->sig = aux->sig;                                                            /// Asigna el segundo lugar al nuevo cliente
           cajin[pos].filita.fin = aux2;*/
        nodo *aux2=cajin[pos].filita.inicio;
        aux2->sig=agregaOrdenadoPorTipoPRIORIDADES(aux2->sig,nuevo);        /// Mismo proceso que el no apropiativo pero no interrumpe el proceso en ejecucion

    }
    TiempoDeEspera(&cajin[pos].filita);
}

void InsertarRR (caja cajin[],int pos,nodo * nuevo,int tiempo)
{
    int quantum = 4;
    persona AlUltimo;

    while (tiempo > 0)              /// Mientras que el tiempo no se agote
    {
        nodo * aux = cajin[pos].filita.inicio;

        if (aux->cliente.cantArticulos >= quantum)      /// Y mientras que el quantum sea mayor que la cantidad
        {                                               /// de articulos del primer cliente
            if (tiempo > quantum)                       /// Y mientras el tiempo ingresado no llegue a agotarse
            {                                           /// por el quantum
                tiempo = tiempo - quantum;
                aux->cliente.tiempoProcesado = aux->cliente.tiempoProcesado + quantum;
                aux->cliente.cantArticulos = aux->cliente.cantArticulos - quantum;      /// Proceso al primer cliente, lo saco y
                AlUltimo = sacarDeFila(&cajin[pos].filita);                             /// lo agrego al final
                agregar(&cajin[pos].filita,crearNodoDoble(AlUltimo));
            }
            else
            {
                aux->cliente.tiempoProcesado = aux->cliente.tiempoProcesado + tiempo;   /// Si el tiempo es menor que el quantum
                aux->cliente.cantArticulos = aux->cliente.cantArticulos - tiempo;       /// proceso al cliente y agoto el tiempo
                tiempo = 0;

            }
            TiempoDeEsperaRoundRobin(&cajin[pos].filita);
            MostrarCaja(cajin,pos);
            system("pause:null");
            system("cls");

        }
        else            /// Si el cliente tiene menos articulos que el quantum
        {
            if (tiempo > aux->cliente.cantArticulos)    /// Y si el tiempo no es agotado por la cantidad de articulos
            {
                aux->cliente.tiempoProcesado = aux->cliente.cantArticulos;
                tiempo = tiempo - aux->cliente.cantArticulos;
                aux->cliente.cantArticulos = 0;             /// Proceso al cliente, lo saco de la fila y lo agrego al final, con su total atendido
                AlUltimo = sacarDeFila(&cajin[pos].filita);
                agregar(&cajin[pos].filita,crearNodoDoble(AlUltimo));
            }
            TiempoDeEsperaRoundRobin(&cajin[pos].filita);
            MostrarCaja(cajin,pos);
            system("pause:null");
            system("cls");
        }
    }

    AlUltimo = sacarDeFila(&cajin[pos].filita);
    agregar(&cajin[pos].filita,crearNodoDoble(AlUltimo));
    cajin[pos].filita.inicio = agregarP(cajin[pos].filita.inicio,nuevo);
    TiempoDeEsperaRoundRobin(&cajin[pos].filita);

}

void InsertarSJF(caja cajin[],int pos,nodo *nuevo,int tiempo) /// NO APROPIATIVO
{
    nodo * ultimo = cajin[pos].filita.fin;
    nodo * aux = cajin[pos].filita.inicio;

    if (nuevo->cliente.cantArticulos > ultimo->cliente.cantArticulos)
    {
        ultimo->sig = nuevo;
        cajin[pos].filita.fin = nuevo;

        if (aux->cliente.cantArticulos < tiempo)
        {
            aux->cliente.tiempoProcesado = aux->cliente.cantArticulos;
            tiempo = tiempo - aux->cliente.cantArticulos;
            aux->cliente.cantArticulos = 0;
        }
        else
        {
            aux->cliente.cantArticulos = aux->cliente.cantArticulos - tiempo;
            aux->cliente.tiempoProcesado = tiempo;
            tiempo = 0;

        }
    }
    else
    {
        while (aux != NULL)
        {
            if (aux->cliente.cantArticulos < tiempo)
            {
                aux->cliente.tiempoProcesado = aux->cliente.cantArticulos;
                tiempo = tiempo - aux->cliente.cantArticulos;
                aux->cliente.cantArticulos = 0;
            }
            else
            {
                aux->cliente.cantArticulos = aux->cliente.cantArticulos - tiempo;
                aux->cliente.tiempoProcesado = tiempo;
                tiempo = 0;

            }
            aux = aux->sig;
        }
        nodo *aux2=cajin[pos].filita.inicio;
        aux2->sig=agregaOrdenadoPorCant(aux2->sig,nuevo);

    }

    TiempoDeEspera(&cajin[pos].filita);
}
