#include <stdio.h>
#include <stdlib.h>
void inicializar(int Arr[], int cant)
{
    int a=0;
    while(a<cant)
    {
        Arr[a]=-1;
    }
    a++;
}

int ingresar(int Arr[])
{
    int b=0;
    char letra='s';
    while(letra=='s')
    {
        printf("ingrese elemento:");
        fflush(stdin);
        scanf("%d",&Arr[b]);
        b++;
        printf("Desea continuar: s/n");
        fflush(stdin);
        scanf("%c",&letra);
    }
    return b;
}

void mostrar(int Arr[],int cant)
{
    int c=0;
    while(c<cant)
    {
        printf("\nElemento:%d",Arr[c]);
        c++;
    }
}
int sumar(int Arr[],int cant)
{
    int d=0;
    int sum=0;
    while(d<cant)
    {
        sum=Arr[d]+sum;
        d++;
    }
    return sum;
}

int contar(int Arr[],int cant)
{
    int e=0;
    int cont=0;
    while(e<cant)
    {
        cont++;
        e++;
    }
    return cont;
}

float promedio(int Arr[],int cant)
{
    int s=sumar(Arr,cant);
    int c=contar(Arr,cant);
    float prom=0;
    prom=(float)s/(float)c;
    return prom;
}


void invertir(int Arr[],int cant)
{
    int p;
    int u=cant-1;
    int aux=0;
    for(p=0; p<=u/2; p++)
    {
        aux=Arr[p];
        Arr[p]=Arr[u];
        Arr[u]=aux;
        u--;
    }
}

float decimal(int Arr[],int cant)
{
    float dec=0;;
    int o;
    while(o<cant)
    {
        dec=Arr[o]*0.1;
        o++;
    }
    return dec;
}

int valormaximo(int A[],int cant, int pos)
{
    int mayor=A[pos];
    int maximo=pos;
    int u=pos+1;
    while(u<cant)
    {
        if(mayor<A[u])
        {
            mayor=A[u];
            maximo=u;
        }
        u++;

    }
    return maximo;
}

int capicua(int A[],int cant)
{
    int z=0;
    int x=cant-1;
    int flag=1;
    for(z=0; z<=x/2; z++)
    {
        if(A[z]==A[x])
        {
            z++;
            x--;
        }
        else
        {
            flag=0;
        }
    }
    return flag;
}

void interc(int *a, int *b)
{
    int aux;
    aux=a;
    a=b;
    b=aux;
}

int intercalar(int A[],int B[],int C[],int validosA,int validosB)
{
    int posA=0;
    int i=0;
    int posB=0;
    int c2=0;
    while(posA<validosA && posB<validosB)
    {
        if(A[posA]<B[posB])
        {
            C[c2]=A[posA];
            posA++;
        }
        else
        {

            C[c2]=B[posB];
            posB++;
        }
        c2++;
    }

    while(posB<validosB)
    {
        C[c2]=B[posB];
        c2++;
        posB++;
    }
    while(posA<validosA)
    {
        C[c2]=A[posA];
        c2++;
        posA++;
    }

    for(i=0; i<c2; i++)
    {
        printf("-%d-",C[i]);
    }

    return c2;
}

int cargarnomb(char Nomb[])
{
    int a=0;
    char letra='s';
    while(letra=='s')
    {
        printf("ingrese nombre:");
        fflush(stdin);
        scanf("%s",&Nomb[a]);
        a++;
        printf("Desea continuar: s/n");
        fflush(stdin);
        scanf("%c",&letra);
    }
    return a;
}

int  cargareda(int eda[])
{
    int b=0;
    char letra='s';
    while(letra=='s')
    {
        printf("ingrese edad:");
        fflush(stdin);
        scanf("%d",&eda[b]);
        b++;
        printf("Desea continuar: s/n");
        fflush(stdin);
        scanf("%c",&letra);
    }
    return b;
}

int mayoredad(int edad[],int cant,char nomb[], int pos)
{
   int maximo=pos;
    int mayor=edad[pos];
    int u=pos+1;
    while(u<cant)
    {
        if(mayor<edad[u])
        {
            mayor=edad[u];
            maximo=u;
        }
        u++;

    }
       printf("el nombre del mayor es:%s",&nomb[maximo]);
       return maximo;

}

int mayor(int Arr[],int cant,int may)
{
    int t=0;
    may=Arr[t];

    while(t<cant)
    {
        if(may<Arr[t])
        {
            may=Arr[t];
        }
        t++;

    }
       return may;

}

int menor(int Arr[],int cant,int min)
{
    int r=0;
    min=Arr[r];

    while(r<cant)
    {
        if(min>Arr[r])
        {
            min=Arr[r];
        }
        r++;

    }
       return min;

}


float prom(int Arr[],float p,int cant)
{
    p=0;
    int sum=0;
    int may=mayor(Arr,cant,may);
    int men=menor(Arr,cant,men);
   if(may!=0 && men!=0)
    {
        sum=may+men;
        p=(float)sum/2;
    }
    return p;
}

int main()
{
    /*int ar[30];
    int cant=ingresar(ar);
    ostrar(ar,cant);
    int sum=sumar(ar,cant);
    printf("\nLa suma de los elementos es:%d",sum);
    int cont=contar(ar,cant);
    printf("\nLa cantidad de elementos es:%d",cont);
    float prom=promedio(ar,cant);
    printf("\nEl promedio es:%f",prom);*/
    int arr[30];
     int w=ingresar(arr);
    /*invertir(arr,w);
    mostrar(arr,w);
    float di=decimal(arr,w);
    printf("El decimal es:%f",di);
    int m=0;
    m=valormaximo(arr,w,m);
    printf("\nLa posicion del maximo es:%d",m);*/
    /*int c=0;
    c=capicua(arr,w);
    if(c==1)
    {
        printf("es capicua");
    }
    else
    {
        printf("no es capicua");
    }*/
    /*int a=10;
    int b=20;
    interc(a,b);
     printf("\nA:%d",a);
    printf("\nB:%d",b);
    int A[30];
    int B[30];
    int C[30];
    int a=ingresar(A);
    int b=ingresar(B);
    intercalar(A,B,C,a,b);
    char nombr[30];
    int eda[30];
    int t=cargarnomb(nombr);
    int y=cargareda(eda);
    int k=0;
   k=mayoredad(eda,t,nombr,k);*/
   int may=mayor(arr,w,may);
   printf("el mayor es:%d",may);
   int men=menor(arr,w,men);
   printf("el menor es:%d",men);
   float pro=prom(arr,pro,w);
   printf("el promedio es:%f",pro);
    return 0;
}
