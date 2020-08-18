#include <stdio.h>
#include <stdlib.h>

int factorial(int a)
{
    int sum=0;
    if(a==0)
    {
        sum=1;
    }
    else
    {
        sum=a*factorial(a-1);
    }
    return sum;
}

int potenciacion(int b,int c)
{
    int sum=0;
    if(c==0)
    {
        sum=1;
    }
    else
    {
        sum=b*potenciacion(b,c-1);
    }
    return sum;
}

void mostrararreglo(int arr[],int cant,int d)
{
    if(d<cant)
    {
        printf("\nDatos:%d",arr[d]);
        mostrararreglo(arr,cant,d+1);

    }
}

void mostrararregloinv(int arr[],int cant,int e)
{
    if(e<cant)
    {

        mostrararregloinv(arr,cant,e+1);
        printf("\nDatos invertidos:%d",arr[e]);
    }
}

int capicua(int arr[],int cant,int f)
{
    int flag=1;
    if(f<cant)
    {
        if(arr[f]!=arr[cant-1])
        {
            flag=0;
        }
        else
        {
            flag=capicua(arr,cant-1,f+1);
        }
    }
    return flag;
}

int suma(int arr[],int cant,int g)
{
    int sum=0;
    if(g==cant)
    {
        sum=0;
    }
    else
    {
        sum=arr[g]+suma(arr,cant,g+1);
    }
    return sum;
}

int menor(int arr[],int cant,int h)
{
    int meno=0;
    if(h==cant)
    {
        meno=arr[h];
    }
    else
    {
        meno=menor(arr,cant,h+1);
        if(meno>arr[h])
        {
            meno=arr[h];
        }
    }
    return meno;
}

int busquedadeelemento(int arr[],int cant,int elem,int i)
{
    int flag=0;
    if(i<cant)
    {
        if(arr[i]==elem)
        {
            flag=1;
        }
        else
        {
            flag=busquedadeelemento(arr,cant,elem,i+1);
        }
    }
    return flag;
}

void inverso()
{
    char letra='*';
    printf("Ingrese letra:");
    fflush(stdin);
    scanf("%c",&letra);
    if(letra!='*')
    {
        inverso();
        printf("%c",letra);
    }
}

void cargar(char nom[])
{
    FILE*archi=fopen(nom,"ab");
    char letra='s';
    int dato=0;
    if(archi!=NULL)
    {
     while(letra=='s')
        {
            printf("ingrese dato:");
            fflush(stdin);
            scanf("%d",&dato);

            fwrite(&dato,sizeof(int),1,archi);

            printf("desea continuar: s/n");
            fflush(stdin);
            scanf("%c",&letra);
            }

    }
    fclose(archi);
}

int menoarchi(FILE*archi)
{
    int meno=0;
    int less=0;
    if(fread(&meno,sizeof(int),1,archi)==0)
    {
        fseek(archi,-1*sizeof(int),SEEK_END);
        fread(&meno,sizeof(int),1,archi);
    }
    else
    {
        less=menoarchi(archi);
        if(less<meno)
        {
            meno=less;
        }
    }
    return meno;
}

void menoarch(char nom[])
{
    FILE*archi=fopen(nom,"rb");
    int s=0;
    if(archi!=NULL)
    {
        s=menoarchi(archi);
        printf("\nEl menor elemento del archivo es:%d",s);
    }
    fclose(archi)
}

void mostrarinv(FILE*archi)
{
    int dat=0;
    if(fread(&dat,sizeof(int),1,archi)!=0)
    {
        mostrarinv(archi);
     printf("\nDatos:%d",dat);
    }
}

void mostrararchivoinv(char nom[])
{
    FILE*archi=fopen(nom,"rb");
    if(archi!=NULL)
    {
        printf("Archivo invertido:");
        mostrarinv(archi);
    }
    fclose(archi);
}

int main()
{
    /*int rta;
    printf("\ningrese numero para calcular factorial:");
    fflush(stdin);
    scanf("%d",&rta);
    int f=factorial(rta);
    printf("\nfactorial=%d",f);
    int b;
    printf("\ningrese base para calcular potencia:");
    fflush(stdin);
    scanf("%d",&b);
    int e;
    printf("\ningrese exponente para calcular potencia:");
    fflush(stdin);
    scanf("%d",&e);
    int p=potenciacion(b,e);
    printf("\npotencia=%d",p);*/
    int arr[5]= {1,2,0,4,5};
    //mostrararreglo(arr,5,0);
    //mostrararregloinv(arr,5,0);
    /*int c=capicua(arr,5,0);
    if(c==1)
    {
        printf("\nes capicua");
    }
    else
    {
        printf("\nno es capicua");
    }
    int s=suma(arr,5,0);
    printf("\nsuma=%d",s);
    int m=menor(arr,5,0);
    printf("\nmenor:%d",m);
    int e;
    printf("\ningrese elemento a buscar:");
    fflush(stdin);
    scanf("%d",&e);
    int b=busquedadeelemento(arr,5,e,0);
    if(b==1)
    {
        printf("\nel elemento se encuenta");
    }
    else
    {
        printf("\nel elemento no se encuenta");
    }
    inverso();
    */
    char nom[]="recusividad.dat";
    cargar(nom);
    /*menoarch(nom);
    mostrararchivoinv(nom);*/

    return 0;
}
