#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int menu_principal()
{
    system("color 1F");
    int input;
    system("cls");
    gotoxy(50,0);
    printf("Trabajo Practico Final");
    int x=whereX();
    int y=whereY();
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);

    char output[128];
    int i;
    for(i=1; i<120; i++)
    {
        gotoxy(i,0);
        printf("%c",177);
        gotoxy(i,25);
        printf("%c",177);
    }
    for(i=1; i<25; i++)
    {
        gotoxy(0,i);
        printf("%c",178);
        gotoxy(119,i);
        printf("%c",178);
    }

    strftime(output, 128, "%d/%m/%y %H:%M:%S", tlocal);
    gotoxy(2,2);
    printf("Fecha y Hora: %s",output);
    gotoxy(2,4);
    printf("Agustin Dominguez");
    gotoxy(2,5);
    printf("Jose Giles");
    gotoxy(2,6);
    printf("Agustin Caceres");
    gotoxy(40,10);
    printf("***********************************");
    gotoxy(40,11);
    printf("*	                          *");
    gotoxy(40,12);
    printf("*     1....USUARIOS               *");
    gotoxy(40,13);
    printf("*     2....CLIENTES               *");
    gotoxy(40,14);
    printf("*     3....ARBOL                  *");
    gotoxy(40,15);
    printf("*     4....SUPERMERCADO           *");
    gotoxy(40,16);
    printf("*     0....SALIR                  *");
    gotoxy(40,17);
    printf("***********************************");
    gotoxy(40,18);
    printf("Elegi tu opcion: ");
    scanf("%d",&input);
    return input;
}

int ABMusuarios()
{
    system("color 1F");
    int menusuarios;
    system("cls");
    printf("\n \rMenu de Opciones Usuarios: ");
    printf("\n1-Crear usuario");
    printf("\n2-Alta-Baja usuario");
    printf("\n3-Modificacion usuario");
    printf("\n4-Mostrar usuarios activos");
    printf("\n5-Listado Usuarios");
    printf("\n0-Volver");
    printf("\n\nElija su opcion..... ");
    scanf("%d",&menusuarios);
    return menusuarios;
}

int ABMpersonas()
{
    system("color 1F");
    int menupersonas;
    system("cls");
    printf("\n \rMenu de Opciones Usuarios: ");
    printf("\n1-Crear cliente");
    printf("\n2-Alta/Baja clientes");
    printf("\n3-Modificar clientes");
    printf("\n4-Mostrar clientes activos");
    printf("\n5-Listado clientes");
    printf("\n0-Volver");
    printf("\n\nElija su opcion..... ");
    scanf("%d",&menupersonas);
    return menupersonas;
}

int MenuArbol()
{
    system("color 1F");
    int menuarbol;
    system("cls");
    printf("\n \rMenu de Opciones Arbol: ");
    printf("\n1-Iniciar Arbol( Archivo to arbol ) ");
    printf("\n2-Mostrar Arbol ( PreOrder-InOrder-PostOrder ) ");
    printf("\n3-Borrar Nodo ");
    printf("\n0-Volver");
    printf("\n\nElija su opcion..... ");
    scanf("%d",&menuarbol);
    return menuarbol;
}

int MenuAlgoritmos()
{
    int menu_algo;
    system("cls");
    printf("\n \rMenu Algoritmos: ");
    printf("\n1-FIFO");
    printf("\n2-SJF");
    printf("\n3-PRIORIDADES");
    printf("\n0-Volver");
    printf("\n\nElegi tu opcion: ");
    scanf("%d",&menu_algo);
    return menu_algo;

}


int MenuSuperMarket()
{
    int menu_market;
    system("cls");
    printf("\n \rMenu Supermercado: ");
    printf("\n1-Ver Cajas");
    printf("\n2-Abrir Caja (especifica o todas)");
    printf("\n3-Pasar de Arbol a Cajas (PreOrder,Inorder,Postorder) ");
    printf("\n4-Cerrar Caja (especifica o todas)");
    printf("\n5-Reiniciar Cajas");
    printf("\n6-Procesar Caja");
    printf("\n7-Insertar Cliente");
    printf("\n0-Volver");
    printf("\n\nElegi tu opcion: ");
    scanf("%d",&menu_market);
    return menu_market;

}
