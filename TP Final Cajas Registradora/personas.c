#include "Estructuras.h"



//          PERSONAS          //
// Funcion para cargar las 40 personas
/*void cargaPersonas(char nombre_archivo[])
{
    int cont =0;
    persona p;
    FILE * archi;
    int c=cuenta_personas(nombre_archivo);

    archi=fopen(nombre_archivo,"ab");

    if(archi!=NULL)
    {
        printf("Ingreso de Personas: \n");
        while(cont<5)
        {
            printf("cant: %d", c);
            printf("Ingreso de Personas: \n");

            puts("\n----------------------------------");
            printf("persona %d de 10",cont+1);

            printf("\n Ingrese Nombre: ");
            fflush(stdin);
            gets(p.nombres);

            printf("\n Ingrese Apellido: ");
            fflush(stdin);
            gets(p.apellido);

            p.id=c+1;

            printf("\n Ingrese Tipo de cliente (1:embarazada, 2:jubilado y 3:cliente comun) : ");
            scanf("%d", &p.tipoCliente);

            printf("\n Ingrese Medio de pago (1:efectivo, 2:credito y 3:todos) : ");
            scanf("%d", &p.medioPago);

            printf("\n Ingrese Cantidad de articulos : ");
            scanf("%d", &p.cantArticulos);

            p.eliminado=0;
            puts("----------------------------------\n");

            fwrite(&p,sizeof(persona),1,archi);
            cont++;
        }
        fclose(archi);
    }
}*/
int cuenta_personas(char nombre[50])
{
    FILE*archi=fopen(nombre,"rb");
    persona aux;
    int cant;

    if(!feof(archi))
    {
        fseek(archi,0,SEEK_END);
        int l=ftell(archi);

        cant=l/sizeof(persona);

    }
    return cant;
    fclose(archi);
}

//Funcion para agregar 1 personas, darla de alta, sin contandor.
void AltaPersonas(char nombre_archivo[])
{
    FILE * archi;
    persona p;


    archi=fopen("personas.dat","ab");
    if(archi==NULL)
    {
        archi=fopen("personas.dat","w+b");
    }
    int cp=cuenta_personas(nombre_archivo);

    if(archi!=NULL)
    {
        printf("Ingreso de Personas: \n");

        puts("\n----------------------------------");

        printf("\n Ingrese Nombre: ");
        fflush(stdin);
        gets(p.nombres);

        printf("\n Ingrese Apellido: ");
        fflush(stdin);
        gets(p.apellido);

        p.tiempoEspera=0;
        p.tiempoProcesado = 0;

        printf("\n Ingrese Tipo de cliente (1:Embarazada / 2:Jubilado / 3:Cliente Comun) : ");
        scanf("%d", &p.tipoCliente);

        printf("\n Ingrese Medio de pago (1:Efectivo / 2:Credito / 3:Todos) : ");
        scanf("%d", &p.medioPago);

        printf("\n Ingrese Cantidad de articulos : ");
        scanf("%d", &p.cantArticulos);

        p.id=cp+1;

        p.eliminado=0;



        puts("----------------------------------\n");

        fwrite(&p,sizeof(persona),1,archi);
    }
    fclose(archi);
}
void modificacion_personas(char nom[],int id)
{
    int opc;
    persona p;
    FILE*archi=fopen(nom,"r+b");
    int existe=0;
    //fseek (archi, 0L, SEEK_SET);
    if(archi)
    {
        while(!feof(archi) && existe==0)
        {
            fread(&p,sizeof(persona),1,archi);
            if(!feof(archi))
            {
                if(id==p.id)
                {
                    existe=1;
                }

                if(existe==1)
                {
                    printf("\nHola %s %s", p.nombres, p.apellido);
                    printf("\nQue deseas cambiar?, Seleccione una opcion");
                    printf("\n\n1.-Nombre");
                    printf("\n\n2.-Apellido");
                    printf("\n\n3.-Tipo de cliente (1:Embarazada / 2:Jubilado / 3:Cliente Comun)");
                    printf("\n\n4.-Medio de pago (1:Efectivo / 2:Credito / 3:Todos)");
                    printf("\n\n5.-Cantidad de articulos");
                    printf("\n\n0.-Salir");
                    printf("\n\nIntroduzca opcion: ");
                    scanf("%d",&opc);
                    switch(opc)
                    {
                    case 1:
                        printf("\n Ingrese Nombre: ");
                        scanf("%s",p.nombres);
                        fseek(archi,sizeof(persona)*-1,SEEK_CUR);
                        fwrite(&p,sizeof(persona),1,archi);
                        break;
                    case 2:
                        printf("\n Ingrese Apellido: ");
                        scanf("%s",p.apellido);
                        fseek(archi,sizeof(persona)*-1,SEEK_CUR);
                        fwrite(&p,sizeof(persona),1,archi);
                        break;
                    case 3:
                        printf("\n Ingrese Tipo de cliente (1:Embarazada / 2:Jubilado / 3:Cliente Comun) : ");
                        scanf("%d", &p.tipoCliente);
                        fseek(archi,sizeof(persona)*-1,SEEK_CUR);
                        fwrite(&p,sizeof(persona),1,archi);
                        break;
                    case 4:
                        printf("\n Ingrese Medio de pago (1:Efectivo / 2:Credito / 3:Todos) : ");
                        scanf("%d", &p.medioPago);
                        fseek(archi,sizeof(persona)*-1,SEEK_CUR);
                        fwrite(&p,sizeof(persona),1,archi);
                        break;
                    case 5:
                        printf("\n Ingrese cantidad de articulos: ");
                        scanf("%d", &p.cantArticulos);
                        fseek(archi,sizeof(persona)*-1,SEEK_CUR);
                        fwrite(&p,sizeof(persona),1,archi);
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
        fclose(archi);
    }
}

void muestraauxlistadopersonas(persona a)
{
    if(a.eliminado==1)
    {
        printf("Estado del cliente:Eliminado (% d) ; Nombre:%s ; Apellido:%s ; ID:%d \n",a.eliminado,a.nombres,a.apellido,a.id);
    }
    else if(a.eliminado==0){
        printf("Estado del cliente:Activo (% d) ; Nombre:%s ; Apellido:%s ; ID:%d \n",a.eliminado,a.nombres,a.apellido,a.id);}
}

void ListadoPersonas()
{
    char pw[10];
    FILE *archi;
    persona a;
    if(archi==NULL)
    {
        printf("hola");
    }
    if(archi!=NULL)
    {
        archi = fopen("personas.dat","rb");
        fread(&a,sizeof(persona),1,archi);
        while(!feof(archi))
        {
            muestraauxlistadopersonas(a);
            fread(&a,sizeof(persona),1,archi);
        }
    }
    fclose(archi);
}

void baja_personas(char nom[],int id)
    {
        int opc;
        persona p;
        FILE*archi=fopen(nom,"r+b");
        int existe=0;
        //fseek (archi, 0L, SEEK_SET);
        if(archi)
        {
            while(!feof(archi) && existe==0)
            {
                fread(&p,sizeof(persona),1,archi);
                if(!feof(archi))
                {
                    if(p.eliminado==0 && id==p.id)
                    {
                        existe=1;
                    }
                    if(existe==1)
                    {
                        printf("\nHola %s %s", p.nombres, p.apellido);
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
                            fseek(archi,sizeof(persona)*-1,SEEK_CUR);
                            fwrite(&p,sizeof(persona),1,archi);
                            break;
                        case 2:
                            break;
                        case 0:
                            printf("\n\nVolviendo al menu de personas\n");
                            break;
                        default:
                            printf("\nError, opcion inexistente");
                            break;
                        }
                    }
                    }
                    else
                    {
                        revivir_persona(nom,id);

                    }


                    }
                }
                fclose(archi);
            }

void revivir_persona (char nom[],int id)
{
        int opcion;
        persona r;
        FILE*archi=fopen(nom,"r+b");
        int existe=0;
        if(archi)
        {
            while(!feof(archi) && existe==0)
            {
                fread(&r,sizeof(persona),1,archi);
                if(!feof(archi))
                {
                    if(id==r.id)
                    {
                        existe=1;
                    }

                    if(existe==1)
                    {
                        printf("\nHola %s %s", r.nombres, r.apellido);
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
                            fseek(archi,sizeof(persona)*-1,SEEK_CUR);
                            fwrite(&r,sizeof(persona),1,archi);
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

void MostrarPersonas(char nom[])
{
    FILE*archi=fopen(nom,"rb");
    persona p;
    if(archi!=NULL)
    {
        while(fread(&p,sizeof(persona),1,archi)>0)
        {
            muestrauxpersonas(p);
        }
    }
    fclose(archi);
}

void muestrauxpersonas(persona p)
{
    if(p.eliminado==0)
    {
        puts("\n---------------------------------------");
        printf("\nNombre:%s",p.nombres);
        printf("\nApellido:%s",p.apellido);
        printf("\nId del cliente:%d\n",p.id);

        if(p.tipoCliente==1)
        {
            puts("Tipo de cliente : Embarazada");
        }
        else if (p.tipoCliente==2)
        {
            puts("Tipo de cliente : Jubilado");
        }
        else
        {
            puts("Tipo de cliente : Cliente comun");
        }
        if(p.medioPago==1)
        {
            puts("Medio de pago: : Efectivo");
        }
        else if (p.medioPago==2)
        {
            puts("Medio de pago: : Credito ");
        }
        else
        {
            puts("Medio de pago: : Todos");
        }
        printf("Cantidad de articulos:%d\n",p.cantArticulos);
        puts("Estado del cliente : Activo");
        puts("\n---------------------------------------");
    }
}


