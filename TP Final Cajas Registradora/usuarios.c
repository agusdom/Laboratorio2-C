#include "Estructuras.h"

int cuenta_usuario(char nombre[50])
{
    FILE*archi=fopen(nombre,"rb");
    usuario aux;
    int cant;

    if(!feof(archi))
    {
        fseek(archi,0,SEEK_END);
        int l=ftell(archi);

        cant=l/sizeof(usuario);

    }
    return cant;
    fclose(archi);
}

int existente(char nombre_archivo[],char usu[])
{
    FILE *archi=fopen(nombre_archivo,"rb");
    int rta=0;
    usuario a;
    if(archi!=NULL)
    {
        while(fread(&a,sizeof(usuario),1,archi)>0)
        {
            if(strcmp(a.usuario,usu)==0)
            {
                rta=1;
            }
        }
        fclose(archi);
        return rta;

    }
}

int entry(char nombre_archivo[])
{
    FILE *archi=fopen(nombre_archivo, "rb");
    usuario a;
    int rta=0;
    char aux[11];
    char user_default []= {"admin"};
    char pass_default []= {"admin"};
    char userx[20], passx[31];

    gotoxy(5,3);
    printf("Introduce Usuario:");
    fflush(stdin);
    scanf("%s", &userx);
    gotoxy(5,4);
    printf("Introduce Pass:");
    fflush(stdin);
    scanf("%s", &passx);
    if(archi!=NULL)
    {
        while(fread(&a,sizeof(usuario),1,archi)>0)
        {
            fDecrypting(aux,a.pass);
            if((strcmp(a.usuario,userx)==0)&&strcmp(aux,passx)==0 )
            {
                rta=1;
            }
            else if((strcmp(user_default,userx)==0)&&strcmp(pass_default,passx)==0 ) /// Al tener problema con la pass(de que agrega un caracter random si pongo pass impares), no se puede cargar el usuario ADMIN ADMIN, entonces lo cargamos con char, PREGUNTAR.
            {
                rta=1;
            }
        }
        fclose(archi);
        return rta;

    }
}
void AltaUsuarios(char nombre_archivo[])
{
    FILE *archi;
    usuario a;
    char passs[11];
    int cu=cuenta_usuario(nombre_archivo);

    archi=fopen(nombre_archivo,"ab");
    if(archi==NULL)
    {
        archi=fopen(nombre_archivo,"w+b");
    }

    if(archi!=NULL)
    {
        archi = fopen("usuarios.dat","ab");
        puts("\n----------------------------------");
        printf("\n Ingrese Nombre: ");
        fflush(stdin);
        gets(a.nombre);

        printf("\n Ingrese Apellido: ");
        fflush(stdin);
        gets(a.apellido);

        printf("\n Ingrese Usuario: ");
        fflush(stdin);
        gets(a.usuario);

        int user_repetido=existente(nombre_archivo,a.usuario);
        while(user_repetido==1)
        {

            puts("ERROR: Usuario repetido, ingrese nuevamente");
            printf("\n Ingrese Usuario: ");
            fflush(stdin);
            gets(a.usuario);
            user_repetido=existente(nombre_archivo,a.usuario);
        }

        int matrizascii[2][5];//guadro contraseña en ascii.
        int passEncrip[2][5];//contraseña encriptada.
        int dim;//dimension.
        char passDesenc[11];//contraseña desencriptada.
        printf("\n Ingrese Password: ");
        fflush(stdin);
        scanf("%s",passs);
        dim=fPass2Matrix(passs,matrizascii);
        fMatrizEncrypting(matrizascii,a.pass,dim);
        //fDecrypting(passDesenc,a.pass);

        a.id=cu+1;


        a.eliminado=0;

        fwrite(&a,sizeof(usuario),1,archi);
        fclose(archi);
        //system("clear");
        //menu();
    }
}

void modificacion_usuarios(char nom[],int id)
{
    int matrizascii[2][5];//guadro contraseña en ascii.
    int passEncrip[2][5];//contraseña encriptada.
    int dim;//dimension.
    char passDesenc[11];//contraseña desencriptada.
    char pw[11];
    int opc;
    usuario p;
    FILE*archi=fopen(nom,"r+b");
    int existe=0;
    //fseek (archi, 0L, SEEK_SET);
    if(archi)
    {
        while(!feof(archi) && existe==0)
        {
            fread(&p,sizeof(usuario),1,archi);
            if(!feof(archi))
            {
                if(id==p.id)
                {
                    existe=1;
                }

                if(existe==1)
                {
                    printf("\nHola %s %s", p.nombre, p.apellido);
                    printf("\nQue desea cambiar?, Seleccione una opcion");
                    printf("\n\n1.-Nombre");
                    printf("\n\n2.-Apellido");
                    printf("\n\n3.-Usuario");
                    printf("\n\n4.-Password");
                    printf("\n\nIntroduzca opcion: ");
                    scanf("%d",&opc);
                    switch(opc)
                    {
                    case 1:
                        printf("\n Ingrese Nombre: ");
                        scanf("%s",p.nombre);
                        fseek(archi,sizeof(usuario)*-1,SEEK_CUR);
                        fwrite(&p,sizeof(usuario),1,archi);
                        break;
                    case 2:
                        printf("\n Ingrese Apellido: ");
                        scanf("%s",p.apellido);
                        fseek(archi,sizeof(usuario)*-1,SEEK_CUR);
                        fwrite(&p,sizeof(usuario),1,archi);
                        break;
                    case 3:
                        printf("\n Ingrese Usuario : ");
                        scanf("%s", &p.usuario);
                        fseek(archi,sizeof(usuario)*-1,SEEK_CUR);
                        fwrite(&p,sizeof(usuario),1,archi);
                        break;
                    case 4:
                        printf("\n Ingrese Password: ");
                        fflush(stdin);
                        scanf("%s",pw);
                        dim=fPass2Matrix(pw,matrizascii);
                        fMatrizEncrypting(matrizascii,p.pass,dim);
                        fDecrypting(passDesenc,p.pass);
                        fseek(archi,sizeof(usuario)*-1,SEEK_CUR);
                        fwrite(&p,sizeof(usuario),1,archi);
                        break;
                    default:
                        printf("\Error, opcion inexistente");
                        break;
                    }
                }
            }

        }
        fclose(archi);
    }
}

void revivir_usuario (char nom[],int id)
{
        int opcion;
        usuario r;
        FILE*archi=fopen(nom,"r+b");
        int existe=0;
        if(archi)
        {
            while(!feof(archi) && existe==0)
            {
                fread(&r,sizeof(usuario),1,archi);
                if(!feof(archi))
                {
                    if(id==r.id)
                    {
                        existe=1;
                    }

                    if(existe==1)
                    {
                        printf("\nHola %s %s", r.nombre, r.apellido);
                        printf("\nSu usuario se encuentra inactivo, desea activarlo?");
                        printf("\n\n1.-Si");
                        printf("\n\n2.-No");
                        printf("\n\n0.-Salir");
                        printf("\n\nElegir opcion: ");
                        scanf("%d",&opcion);
                        switch(opcion)
                        {
                        case 1:
                            r.eliminado=0;
                            fseek(archi,sizeof(usuario)*-1,SEEK_CUR);
                            fwrite(&r,sizeof(usuario),1,archi);
                            break;
                        case 2:
                            break;
                        case 0:
                            printf("\n\nVolviendo al menu de personas\n");
                            break;
                        default:
                            printf("Error, opcion inexistente");
                            break;
                        }
                    }
                }
            }
        }
        fclose(archi);
}

void Baja_usuarios(char nom[],int id)
{
    int opc;
    usuario p;
    FILE*archi=fopen(nom,"r+b");
    int existe=0;
    //fseek (archi, 0L, SEEK_SET);
    if(archi)
    {
        while(!feof(archi) && existe==0)
            {
                fread(&p,sizeof(usuario),1,archi);
                if(!feof(archi))
                {
                    if(p.eliminado==0 && id==p.id)
                    {
                        existe=1;
                    }
                    if(existe==1)
                    {
                        printf("\nHola %s %s", p.nombre, p.apellido);
                        printf("\nEsta seguro que desea eliminar el usuario?");
                        printf("\n\n1.-Si");
                        printf("\n\n2.-No");
                        printf("\n\n0.-Salir");
                        printf("\n\nElegir opcion: ");
                        scanf("%d",&opc);
                        switch(opc)
                        {
                        case 1:
                            p.eliminado=1;
                            fseek(archi,sizeof(usuario)*-1,SEEK_CUR);
                            fwrite(&p,sizeof(usuario),1,archi);
                            break;
                        case 2:
                            break;
                        case 0:
                            printf("\n\nVolviendo al menu de personas\n");
                            break;
                        default:
                            printf("Error, opcion inexistente");
                            break;
                        }
                    }
                    }
                    else
                    {
                        revivir_usuario(nom,id);

                    }


                    }
                }
                fclose(archi);
}

void muestraauxlistadousuarios (usuario a)
{
    int matrizascii[2][5];//guadro contraseña en ascii.
    int passEncrip[2][5];//contraseña encriptada.
    int dim;//dimension.
    char passDesenc[10];//contraseña desencriptada.
    char pw[11];
    if(a.eliminado==1)
    {
        fDecrypting(pw,a.pass);
        printf("Estado del cliente:Eliminado (% d) ; Nombre:%s ; Apellido:%s ; Usuario:%s ; ID:%d ; Password:%s\n",a.eliminado,a.nombre,a.apellido,a.usuario,a.id,pw);
    }
    else if(a.eliminado==0){
        fDecrypting(pw,a.pass);
        printf("Estado del cliente:Activo (% d) ; Nombre:%s ; Apellido:%s ; Usuario:%s ; ID:%d ; Password:%s\n",a.eliminado,a.nombre,a.apellido,a.usuario,a.id,pw);}
}
void ListadoUsuarios()
{

    FILE *archi;
    usuario a;
    archi = fopen("usuarios.dat","rb");
    fread(&a,sizeof(usuario),1,archi);
    while(!feof(archi))
    {
        muestraauxlistadousuarios (a);
        fread(&a,sizeof(usuario),1,archi);
    }
    fclose(archi);
}


void muestrauxusuarios(usuario a)
{
    if(a.eliminado==0)
    {
        puts("\n---------------------------------------");
        printf("Nombre:%s\n",a.nombre);
        printf("Apellido:%s\n",a.apellido);
        printf("Usuario:%s\n",a.usuario);
        printf("ID:%d\n",a.id);
        puts("Estado del cliente : Activo");
        char aux[11];
        fDecrypting(aux,a.pass);
        printf("Password: %s\n",aux);
    }
}

void MostrarUsuarios(char nom[])
{
    FILE*archi=fopen(nom,"rb");
    usuario a;
    if(archi!=NULL)
    {
        while(fread(&a,sizeof(usuario),1,archi)>0)
        {
            muestrauxusuarios(a);
        }
    }
    fclose(archi);
}

void mostrarMatriz (int M[2][5])
{
    int f=0;
    int c=0;

    printf("\nContenido de la matriz: \n");
    for(f=0; f<2; f++)
    {
        for(c=0; c<5; c++)
        {
            switch(M[f][c])
            {
            case 0 ... 9:
                printf("   ");
                break;
            case 10 ... 99:
                printf("  ");
                break;
            case 100 ... 999:
                printf(" ");
            }
            printf("| %d |",M[f][c]);
        }
        printf("\n");
    }
}





void color(int x)                                                               /// Cambia la combinacion de color de fondo y frente
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}

void gotoxy(int X,int Y)                                                        /// Cambia las coordenadas del cursor
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=X;
    dwPos.Y=Y;
    SetConsoleCursorPosition(hcon,dwPos);
}

int whereX()                                                                      /// Devuelve la posicion de X
{
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.X;
}

int whereY()                                                                    /// Devuelve la posicion de Y
{
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.Y;
}

void hidecursor(int ver)                                                        /// funcion para mostrar o esconder el cursor
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 1;
    info.bVisible = ver;
    SetConsoleCursorInfo(consoleHandle, &info);
}
