#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NMAX 10000
int prim (int a)
{
    int i,d;
    for(d=2;d*d<=a;d++)
        if(a%d==0)
            return 0;
    return 1;
}
int main()
{   //3.4
    //sirul lui eratostene
   /* char a[NMAX+1]={0}; //pe un octet
    int n,i,j;
    printf("n(<=%d)= ",NMAX);
    scanf("%d",&n);
    for(i=2;i<=sqrt(n);i++) //a=sqrt(n) sau i*i<=n
        if(a[i]==0)
            for(j=i*i;j<=n;j=j+i)
                a[j]=1;
    for(i=2;i<=n;i++)
        if(a[i]==0)
        printf("%d ",i);*/
    // 3.5 partea intreaga din radical din n la patrat
    int n,a;
    printf("n= ");
    scanf("%d",&n);
    /*a=abs(sqrt(n));
    printf("cel mai mare patrat perfect mai mic sau egal cu n: %d",a*a);*/
    int ok=0,i;
    i=n;
    while(ok==0)
    {
        if(prim(i)==1)
            ok=1;
        else i++;
    }
    printf("cel mai mic numar prim mai mare sau egal cu n: %d",i);
    return 0;
}
