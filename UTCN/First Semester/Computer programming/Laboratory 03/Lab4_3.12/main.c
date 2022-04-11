#include <stdio.h>
#include <stdlib.h>

int main()
{
    //cautare binara
    int n,a[100],p,u,m,x,i,ok=0;
    printf("dati numarul de elemente  ");
    scanf("%d",&n);
    printf("dati elementele ordonate crescator: ");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("dati numarul cautat  ");
    scanf("%d",&x);
    p=1;u=n;
    while(p<=u){
        m=(p+u)/2;
        if(a[m]==x)
               {
                   printf("pozitia este %d",m);
                   ok=1;
                   p=u+1;
               }
        else {
                if(x<a[m])
                    u=m-1;
                else p=m+1;
        }
    }
    if(ok==0)
        printf("elementul %d nu se gaseste in sir");
    return 0;
}
