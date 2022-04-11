#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void citire(int *grad,int a[100])
{
    int i;
   printf("dati gradul polinomului: ");
    scanf("%d",grad);
    printf("dati coeficientii incepand cu gradul cel mai mare : ");
    for(i=*grad;i>=0;i--)
    {
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
    }
}
int radacina(int d,int a[100],int grad)
{
    int i,s=0;
    for(i=0;i<=grad;i++)
        s=s+a[i]*pow(d,i);
    if(s==0)
        return 1;
    else return 0;
}
void determinare(int grad,int a[100])
{
    int d,ok=0,c;
    c=abs(a[0]);
    for(d=1;d<=c;d++)
    {
        if(c%d==0)
        {
            if(radacina(d,a,grad)==1)
            {
                printf("%d ",d);
                ok=1;
            }
            if(radacina(-d,a,grad)==1)
            {
                printf("%d",-d);
                    ok=1;
            }
        }
    }
    if(ok==0)
        printf("nu are radacini intregi");
}
int main()
{
    int grad,a[100];
    citire(&grad,a);
    determinare(grad,a);
    return 0;
}
