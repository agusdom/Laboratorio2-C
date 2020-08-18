#include "Estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "string.h"
#include <windows.h>



//TERMINADO

/* ASCII
 97 = a
 98 = b
 99 = c
 100 = d
 101 = e
 102 = f
 103 = g
 104 = h
 105 = i
 106 = j
 107 = k
 108 = l
 109 = m
 110 = n
 111 = o
 112 = p
 113 = q
 114 = r
 115 = s
 116 = t
 117 = u
 118 = v
 119 = w
 120 = x
 121 = y
 122 = z*/

int main(int argc, char *argv[])
{
    // CAJAS
    caja caji[12];
    Cajastotales(caji);
    int num=0;
    Fila fili;
    int agregaracajas,menucerrar,menuabrir;
    int cerrarcajanum=0;
    int abrir = 0;
    int cerrar=0;
    // ARBOL
    nodoArbol*arbol;
    arbol=inicArbol();
    persona p;

    //AUX
    int selected,opcion2,opcion3,opcion4,opcion5,opcion6,aux,menumostrararbol;
    char borrarnombre[10];

    //ENCRIPTADO-DESENCRIPTADO
    char contra[10];// guardo contraseña del usurio.
    int matrizascii[2][5];//guadro contraseña en ascii.
    int passEncrip[2][5];//contraseña encriptada.
    int dim,idbaja,idmodif,idbajapersonas,idmodifpersonas;//dimension.
    char passDesenc[10];//contraseña desencriptada.

    //ARCHIVOS
    char archivoUsuarios[]= {"usuarios.dat"};
    char archivoPersonas[]= {"personas.dat"};


    // AUX-ENTRY PROGRAMA
    int rta;
    int intentos = 0;
    int i,x,y;
    do
    {
        gotoxy(2,2);
        rta=entry(archivoUsuarios);
        intentos++;
        if(rta==1 )
        {
            gotoxy(50,20);
            printf("CARGANDO USUARIO");

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
            printf("\n \n Carga Completa, puede salir presionando cualquier tecla \n");

            do
            {
                selected = menu_principal();
                switch(selected)
                {
                case 1:
                    do
                    {
                        opcion2=ABMusuarios();
                        switch(opcion2)
                        {
                        case 1: // Cargo usuario, pido contraseña, y llamo a las funciones de encriptado-desencriptado
                            AltaUsuarios(archivoUsuarios);
                            system("pause");
                            system("cls");
                            break;
                        case 2: //
                            printf("Ingrese ID a eliminar: ");
                            scanf("%d", &idbaja);
                            Baja_usuarios(archivoUsuarios,idbaja);
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            printf("Ingrese ID a modificar: ");
                            scanf("%d",&idmodif);
                            modificacion_usuarios(archivoUsuarios,idmodif);
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            MostrarUsuarios(archivoUsuarios);
                            puts("---------------------------------------\n");
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            ListadoUsuarios();
                            system("pause");
                            system("cls");
                            break;
                        case 0:
                            printf("\n\nVolviendo al menu principal...\n");

                            system("pause");
                            system("cls");
                            break;
                        }
                    }
                    while(opcion2!=0);
                case 9:
                    printf("\n\nFIN\n");

                    break;
                case 2:
                    do
                    {
                        opcion3=ABMpersonas();
                        switch(opcion3)
                        {
                        case 1: // Cargamos personas
                            printf("Carga personas: ");
                            AltaPersonas(archivoPersonas);
                            system("pause");
                            system("cls");
                            break;
                        case 2: // Baja de personas
                            printf("Ingrese ID a modificar: ");
                            scanf("%d",&idbajapersonas);
                            baja_personas(archivoPersonas,idbajapersonas);
                            system("pause");
                            system("cls");
                            break;
                        case 3: // Modificacion de personas con opciones
                            printf("Ingrese ID a modificar: ");
                            scanf("%d",&idmodifpersonas);
                            modificacion_personas(archivoPersonas,idmodifpersonas);
                            system("pause");
                            system("cls");
                            break;
                        case 4: // Muestro archivo personas
                            MostrarPersonas(archivoPersonas);
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            ListadoPersonas();
                            system("pause");
                            system("cls");
                            break;
                        case 0:
                            printf("\n\nVolviendo al menu principal...\n");

                            system("pause");
                            system("cls");
                            break;
                        }
                    }
                    while(opcion3!=0);
                case 8:
                    printf("\n\nFIN\n");

                    break;
                case 3:
                    do
                    {
                        opcion4=MenuArbol();
                        switch(opcion4)
                        {
                        case 1: // Iniciar arbol

                            arbol=PasarArchivoArbol(archivoPersonas,arbol);
                            if (arbol != NULL)
                            {
                                MessageBox(0,"El arbol fue cargado satisfactoriamente", "MenuArbol", MB_OK );
                            }
                            else
                            {
                                printf("\nERROR: No se encontraron datos en el archivo !\n");
                            }
                            system("pause");
                            system("cls");
                            break;
                        case 2: // Mostrar Arbol REVISAR
                            if (arbol == NULL)
                            {
                                printf("\nNo hay datos...\n");
                                system("pause");
                            }
                            else
                            {
                                menumostrararbol= 0;
                                while (menumostrararbol != 4)
                                {
                                    system("cls");
                                    gotoxy(40,10);
                                    printf("***********************************");
                                    gotoxy(40,11);
                                    printf("*	                          *");
                                    gotoxy(40,12);
                                    printf("*     1....INORDEN                *");
                                    gotoxy(40,13);
                                    printf("*     2....PREORDEN               *");
                                    gotoxy(40,14);
                                    printf("*     3....POSTORDEN              *");
                                    gotoxy(40,15);
                                    printf("*     4....SALIR                  *");
                                    gotoxy(40,16);
                                    printf("***********************************");
                                    gotoxy(40,17);
                                    printf("Elija su opcion: ");
                                    scanf("%d",&menumostrararbol);
                                    switch(menumostrararbol)
                                    {
                                    case 1:
                                        if (arbol == NULL)
                                        {
                                            printf("\nNo hay datos cargados...\n");
                                        }
                                        mostrarArbolPreorder(arbol);
                                        system("pause>null");
                                        break;

                                    case 2:
                                        if (arbol == NULL)
                                        {
                                            printf("\nNo hay datos cargados...\n");
                                        }
                                        mostrarArbolInOrder(arbol);
                                        system("pause>null");
                                        break;

                                    case 3:
                                        if (arbol== NULL)
                                        {
                                            printf("\nNo hay datos cargados...\n");
                                        }
                                        mostrarArbolPostorder(arbol);
                                        system("pause>null");
                                        break;
                                    }
                                }
                                break;
                            }
                            break;
                        case 3:
                            printf("Ingrese Cliente a Borrar: ");
                            fflush(stdin);
                            scanf("%s",&borrarnombre);
                            arbol = borrarNodoArbol(arbol,borrarnombre);
                            if(arbol == NULL)
                            {
                                printf("\nNo hay datos en el arbol...\n");
                            }
                            else
                            {
                                printf("\nEl Arbol:");
                                mostrarArbolInOrder(arbol);
                            }
                            system("pause");
                            break;
                        case 0:
                            printf("\n\nVolviendo al menu principal...\n");

                            system("pause");
                            system("cls");
                            break;
                        }
                    }
                    while(opcion4!=0);
                case 0:
                    printf("\n\nFIN\n");

                    break;
                case 4:
                    do
                    {
                        opcion5=MenuSuperMarket();
                        switch(opcion5)
                        {
                        case 1: // Ver cajas
                            system("cls");
                            mostrarcajasabiertas(caji);
                            system("pause");
                            system("cls");
                            break;
                        case 2: // Abrir cajas
                                menuabrir= 0;
                                while (menuabrir != 3)
                                {
                                    system("cls");
                                    gotoxy(40,10);
                                    printf("***********************************");
                                    gotoxy(40,11);
                                    printf("*	                          *");
                                    gotoxy(40,12);
                                    printf("*     1....CAJA ESPECIFICA        *");
                                    gotoxy(40,13);
                                    printf("*     2....TODAS                  *");
                                    gotoxy(40,14);
                                    printf("*     3....SALIR                  *");
                                    gotoxy(40,15);
                                    printf("***********************************");
                                    gotoxy(40,16);
                                    printf("Elija su opcion: ");
                                    scanf("%d",&menuabrir);
                                    switch(menuabrir)
                                    {
                                    case 1:
                                        printf("Que caja deseas abrir? ");
                                        fflush(stdin);
                                        scanf("%d",&abrir);
                                        int rta=abrircaja(caji,abrir);
                                        if(rta==-1)
                                        {
                                            printf("La caja ingresada no existe o ya se encuentra activa!");
                                        }
                                        system("pause");
                                        break;
                                    case 2:
                                        abrirAllCajas(caji);
                                        system("pause");
                                        break;
                                    case 3:
                                        system("pause");
                                        break;
                                    }
                                }
                                break;
                        case 3: // agregar a cajas pre-in-post
                            if (arbol == NULL)
                            {
                                printf("\nNo hay datos en el arbol, carguelos desde el menu correspondiente!\n");
                                system("pause");
                            }
                            else
                            {
                                agregaracajas= 0;
                                while (agregaracajas != 4)
                                {
                                    system("cls");
                                    gotoxy(40,10);
                                    printf("***********************************");
                                    gotoxy(40,11);
                                    printf("*	                          *");
                                    gotoxy(40,12);
                                    printf("*     1....PREORDEN               *");
                                    gotoxy(40,13);
                                    printf("*     2....INORDEN                *");
                                    gotoxy(40,14);
                                    printf("*     3....POSTORDEN              *");
                                    gotoxy(40,15);
                                    printf("*     4....SALIR                  *");
                                    gotoxy(40,16);
                                    printf("***********************************");
                                    gotoxy(40,17);
                                    printf("Elija su opcion: ");
                                    scanf("%d",&agregaracajas);
                                    switch(agregaracajas)
                                    {
                                    case 1:
                                        system("cls");
                                        if (arbol == NULL)
                                        {
                                            printf("\nNo hay datos...\n");
                                        }
                                        pasarDeArbolACajaPreorden(arbol,caji);
                                        system("cls");
                                        gotoxy(40,12);
                                        printf("**Personas cargadas!**\n");
                                        //ReiniciarFilas(caji); /// funcion aparte, en menu
                                        system("pause");
                                        break;

                                    case 2:
                                        system("cls");
                                        if (arbol == NULL)
                                        {
                                            printf("\nNo hay datos...\n");
                                        }
                                        pasarDeArbolACajaInorden(arbol,caji);
                                        //agregarClienteACajaInOrder (arbol,caji);
                                        system("cls");
                                        gotoxy(40,12);
                                        printf("**Personas cargadas!**\n");
                                        //ReiniciarFilas(caji);
                                        system("pause");
                                        break;

                                    case 3:
                                        system("cls");
                                        if (arbol== NULL)
                                        {
                                            printf("\nNo hay datos...\n");
                                        }
                                        pasarDeArbolACajaPosOrden(arbol,caji);
                                        system("cls");
                                        gotoxy(40,12);
                                        printf("**Personas cargadas!**\n");
                                        //ReiniciarFilas(caji);
                                        system("pause");
                                        break;
                                    }
                                }
                                break;
                            }
                            break;
                            system("pause");
                            system("cls");
                            break;
                        case 4: // cerrar cajas
                                menucerrar= 0;
                                while (menucerrar != 3)
                                {
                                    system("cls");
                                    gotoxy(40,10);
                                    printf("***********************************");
                                    gotoxy(40,11);
                                    printf("*	                          *");
                                    gotoxy(40,12);
                                    printf("*     1....CAJA ESPECIFICA        *");
                                    gotoxy(40,13);
                                    printf("*     2....TODAS                  *");
                                    gotoxy(40,14);
                                    printf("*     3....SALIR                  *");
                                    gotoxy(40,15);
                                    printf("***********************************");
                                    gotoxy(40,16);
                                    printf("Elija su opcion: ");
                                    scanf("%d",&menucerrar);
                                    switch(menucerrar)
                                    {
                                    case 1:
                                        printf("Que caja deseas cerrar? ");
                                        fflush(stdin);
                                        scanf("%d",&cerrar);
                                        cerrarcaja(caji,cerrar);
                                        system("pause");
                                        break;
                                    case 2:
                                        cerrarAllCajas(caji);
                                        system("pause");
                                        break;
                                    case 3:
                                        system("pause");
                                        break;
                                    }
                                }
                                break;
                        case 5: // Reiniciar cajas
                            ReiniciarFilas(caji);
                            system("pause");
                            system("cls");
                            break;
                        case 6: // Ver tiempos
                            Procesar(caji);
                            system("pause");
                            system("cls");
                            break;
                        case 7: // Ingresar personas
                            CargarClienteNuevo(caji);
                            system("pause");
                            system("cls");
                            break;
                        case 0:
                            printf("\n\nVolviendo al menu principal...\n");

                            system("pause");
                            system("cls");
                            break;
                        }
                    }
                    while(opcion5!=0);
                case 7:
                    break;
                }//switch selected
            }
            while(selected!=0); //do
            system("pause");
            return 0;

        }//if
        else
        {
            if(intentos<3)
            {
                gotoxy(5,5);
                printf("Los datos ingresados no son correctos, reescribi tus datos ! ! !");
                gotoxy(50,20);
                printf("\nIntento %d de 3\n", intentos+1);

            }
            else
            {
                system("color 4F");
                system("cls");
                gotoxy(40,12);
                MessageBox(0,"PROGRAMA BLOQUEADO", "ERROR", MB_OK );
            }
            continue;
        }
    }
    while (intentos<3 && rta==0);

    system("PAUSE");
    return 0;
}

/*
int main()
{
    char contra[11];// guardo contraseña del usurio.
    int matrizz[2][5];//guadro contraseña en ascii.
    int pass[2][5];//contraseña encriptada.
    int p;//dimension.
    char desc[11];//contraseña desencriptada.
    printf("ingrese pass: ");
    fflush(stdin);
    scanf("%s", &contra);
     puts("\nmatriz ascii");
    p=fPass2Matrix(contra,matrizz);
    mostrarMatriz(matrizz);

    puts("\nmatriz encriptada");
    fMatrizEncrypting(matrizz,pass,p);
    mostrarMatriz(pass);
    fDecrypting(desc,pass);
    printf("\ncontrasenia desencriptada:%s",desc);
    return 0;
}*/

