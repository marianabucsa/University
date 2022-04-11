#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define GRAD_MAX 20
int citirePOL(int a[]);
void afisareRAD(int grad,int a[]);
int valPOL(int x,int grad,int a[]);
int main()
{
    int grad,a[GRAD_MAX+1];
    printf("Polinomul \n");
    grad=citirePOL(a);
    printf("Radacinile intregi \n");
    afisareRAD(grad,a);
    return 0;
}
int citirePOL(int a[])
{
    int grad,i;
    printf("Gradul(<=%d)\n",GRAD_MAX);
    scanf("%d",&grad);
    printf("coeficienti :\n ");
    for(i=grad;i>=0;i--)
    {
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
    }
    return grad;
}
void afisareRAD(int grad,int a[])
{
    int nrRAD=0,d; //a0=0
    a[0]=abs(a[0]);
    for(d=1;d<=a[0];d++)
    {
        if(a[0]%d==0)
          {
            if(valPOL(d,grad,a)==0)
                nrRAD++,printf("%d ",d);
            if(valPOL(-d,grad,a)==0)
                nrRAD++,printf("%d ",d);
          }
    }
    if(nrRAD==0)
        printf("nu exista radacini intregi");
}
int valPOL(int x,int grad,int a[])
{
    int i,v=0;
    for(i=grad;i>=0;i--)
    {
        v=v*x+a[i];
    }
    return v;
}
