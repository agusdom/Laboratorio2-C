#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[30];
    char sexo;
    int edad;
} persona;

int cargar(persona P[])
{
    int a=0;
    char letra='s';
    while(letra=='s')
    {
        printf("ingrese nombre:");
        fflush(stdin);
        scanf("%s",&P[a].nombre);
        printf("ingrese edad:");
        fflush(stdin);
        scanf("%d",&P[a].edad);
        printf("ingrese sexo:");
        fflush(stdin);
        scanf("%c",&P[a].sexo);
        a++;
        printf("Desea continuar: s/n");
        fflush(stdin);
        scanf("%c",&letra);
    }
    return a;
}

int cant_d_varones(persona P[],int cant)
{
    int b=0;
    int cont=0;
    while(b<cant)
    {
        if(P[b].sexo=='v')
        {
            cont++;
            b++;
        }
        else
        {
            b++;
        }
    }
    return cont;
}

void copiar(persona P[],int validos, persona arr[])
{
    int t=cant_d_varones(P,validos);
    int c;
    int d;
    arr=malloc(t*sizeof(persona));
    while(c<validos)
    {
        if(P[d].sexo=='v')
        {
            arr[d]=P[c];
            d++;
            c++;
        }
        c++;

    }

}

persona menor(persona P[],int pos,int validos)
{
    persona meno=P[pos];
    int posmenor=pos;
    int index=pos+1;
    persona aux;
    while(index<validos)
    {
        if(P[posmenor].edad>P[index].edad)
        {
            aux=P[posmenor];
            P[posmenor]=P[index];
            P[index]=aux;
        }
        index++;
    }
}

void metodo_seleccion(persona P[],int validos)
{
    persona p_menor;
    int w=0;
    while(w<validos)
    {
        menor(P,w,validos);

        P[w]=p_menor;
        w++;
    }
}

void intercalar(Pila*pilita,Pila*Pilon,Pila*pil)
{
    Pila aux;
    Pila aux2;
    Pila aux3;
    inicPila(&aux);
    inicPila(&aux2);
    inicPila(&aux3);
    leer(pilita);
    leer(pilita);
    leer(pilita);
    leer(pilon);
    leer(pilon);
    leer(pilon);
    apilar(&aux,desapilar(pilita));
    while(!pilavacia(pilita)&&!pilavacia(pilon))
    {
        if(tope(&aux)<tope(pilita))
        {
            apilar(&aux2,desapilar(pilita));
        }
        else
        {
            apilar(&aux2,desapilar(&aux));
            apilar(&aux,desapilar(pilita));

        }

        if(tope(&aux)<tope(pilon))
        {
            apilar(&aux3,desapilar(pilon));
        }
        else
        {
            apilar(&aux3,desapilar(&aux));
            apilar(&aux,desapilar(pilon));

        }

        while(!pilavacia(pilon)&&!pilavacia(&aux2))
        {
            apilar(pilita,desapilar(&aux2));
            apilar(pilon,desapilar(&aux2));
        }

        if(!pilavacia(&aux))
        {
            apilar(pil,desapilar(&aux));
        }

        if(!pilavacia(&aux3))
        {
            apilar(pil,desapilar(&aux3));
        }
    }

}

void insertar(int arr[],int u,int dato)
{
    int g=u;
    while(g>=0 && arr[g]>dato)
    {
        arr[g+1]=arr[g];
        g++;
    }
    arr[g+1]=dato;
}

void met_inserccion(int arr[],int cant)
{
    int o=0;
    while(o<cant)
    {
        insertar(arr,o,arr[o]);
        o++;
    }
}

void elimiar(int arr[],int cant,int dato)
{
    int l;
    while(l<cant)
    {
        if(arr[l]==dato)
        {
            arr[l]=arr[l+1];
            q++;
        }
        t=cant-1;
    }
}

typedef struct
{
    int matricula;
    char nombre[30];
} Alumno;

typedef struct
{
    int codigo;
    char nombreMat[20];
} Materia;

typedef struct
{
    int matricula;
    int codigo;
    int nota;
} Nota;

void cargamateria(Materia mat[])
{

    int x=0;
    char letra='s';
    while(letra=='s')
    {
        printf("ingrese materia:");
        fflush(stdin);
        scanf("%s",&mat[x].nombreMat);
        printf("ingrese codigo:");
        fflush(stdin);
        scanf("%d",&mat[x].codigo);
        x++;
        printf("Desea continuar: s/n");
        fflush(stdin);
        scanf("%c",&letra);

    }
    return x;
}
void cargaalmno(Alumno alu[])
{

    int z=0;
    char letra='s';
    while(letra=='s')
    {
        printf("ingrese nombre:");
        fflush(stdin);
        scanf("%s",&alu[z].nombre);
        printf("ingrese matricula:");
        fflush(stdin);
        scanf("%d",&alu[z].matricula);
        z++;
        printf("Desea continuar: s/n");
        fflush(stdin);
        scanf("%c",&letra);

    }
    return z;
}

int buscarcod(Materia mat[],int cant,int cod)
{
    int c=0;
    int flag=-1;
    while((c<cant)&&(flag==-1))
    {
        if(mat[c].codigo==cod)
        {
            flag=c;
        }
        c++;
    }
    return flag;
}

int buscarmatr(Alumno alu[],int cant,int mat)
{
    int d=0;
    int flag=-1;
    while((d<cant)&&(flag==-1))
    {
        if(alu[d].matricula==mat)
        {
            flag=c;
        }
        c++;
    }
    return flag;
}

int agregarnota(Nota not[],Alumno alu[],Materia mat[])
{
    int matr=buscarmatr(alu,cant,alu[matr].matricula);
    int cod=buscarcod(mat,cant,mat[cod].codigo);
    if(matr==1 && cod==1)
    {
        int y=0;
        char letra='s';
        while(letra=='s')
        {

            printf("ingrese nota:");
            fflush(stdin);
            scanf("%d",&not[y].nota);
            y++;
            printf("Desea continuar: s/n");
            fflush(stdin);
            scanf("%c",&letra);

        }

    }
    else
    {

        printf("\nLa matricula y el codigo no se encuentran\n");
    }
}
return y;
}

void mostaralumno(Nota not[],Alumno alu[],Materia mat[],int cant)
{
    int matr=buscarmatr(alu,cant,alu[matr].matricula);
    if(mat==1)
    {
        int w=0;
        while(w<cant)
        {
            printf("Nombre:%s",alu[w].nombre);
            printf("Materia:%s",mat[w].nombreMat);
            printf("Nota:%d",not[w].nota);
            w++;
        }
    }
    else
    {

        printf("\nLa matricula no se encuentra\n");
    }
}

int main()
{
    persona per[30];
    int a=cargar(per);
    int v=cant_d_varones(per,a);
    printf("Varones:%d",v);
    persona arr[30];
    copiar(per,a,arr);
    Pila dada;
    Pila dede;
    Pila ord;
    inicPila(&dada);
    inicPila(&dede);
    inicPila(&ord);
    intercalar(&dada,&dede,&ord);
    met_inserccion(arr,30);
    int dato;
    printf("ingrese dato a eliminar:");
    fflush(stdin);
    scanf("%d",dato);
    elimiar(arr,30,dato);
    Alumno Alu[20];
    Materia mat[5];
    Nota not[100];
    int a=cargamateria(mat);
    int b=cargaalmno(Alu);
    agregarnota(not,alu,mat);
    mostaralumno(not,alu,mat,b);


}
