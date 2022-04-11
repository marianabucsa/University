#include <stdio.h>
#include <stdlib.h>
float *citire(int *n)
{
    printf("nr elemente : ");
    scanf("%d",n);//adresa lui n
    float *a=(float *)calloc(*n,sizeof(float));//(float *) trebuie pus pentru a arata tipul valorilor din a
    //aici ne trebuie valoarea lui n //aloca un bloc de dimensiunea n returneaza adresa la care incepe alocarea
    if(a==NULL)
      {
        printf("Memorie insuficienta");
        exit(1);
      }
    int i;
    for(i=0;i<*n;i++){ //aici trebuie valoarea lui n
        printf("[%d]=",i);
        scanf("%f",&a[i]);//a+i
    }
    return a; //functia returneaza adresa de inceput
}
void afisare(float *a, int n)
{
    int i;
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%.2f ",a[i]);
    }
}
void schimba(float *p,float *q)
{
    float aux;
    aux=*p;
    *p=*q;
    *q=aux;
}
void bubble_sort(float a[],int n)//float *a
{
    int sortat=0,i;
    while(!sortat){
        sortat=1;
        for(i=1;i<n;i++)
            if(a[i-1]>a[i]){
                schimba(&a[i-1],&a[i]);
                sortat=0;
            }
        n--;
    }
}
int main()
{
    float *a;
    int n;
    a=citire(&n);
    bubble_sort(a,n);
    printf("tabloul sortat este: ");
    afisare(a,n);
    free(a);
    return 0;
}

