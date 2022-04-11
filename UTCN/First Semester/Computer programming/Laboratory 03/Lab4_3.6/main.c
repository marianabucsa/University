#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,p=0,cn;
    printf("Dati un numar natural:");
    scanf("%d",&n);
    cn=n;
    while(cn>0)
       {
           p=p*10+cn%10;
           cn/=10;
       }
    if(n==p)
        printf("Nr este palindrom");
    else printf("Nr nu este palindrom");
    return 0;
}
