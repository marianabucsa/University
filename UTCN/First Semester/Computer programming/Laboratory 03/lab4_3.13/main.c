#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a[100],i,p,u,k,lm,cp,cu;
    printf("dati numarul de elemente ");
    scanf("%d",&n);
    printf("dati elementele ");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    cu=1; cp=1;
    k=1; lm=1;
    for(i=1;i<n;i++)
    {
        if(a[i]<=a[i+1])
        {
            cu=i+1;
            k++;
        }

        else {
            cu=i+1;
            cp=i+1;
            k=1;
        }
          if(lm<k)
            {
                lm=k;
                p=cp;
                u=cu;
            }
    }
    printf ("subsirul crescator : ");
    for(i=p;i<=u;i++)
        printf(" %d",a[i]);
    printf("  de lungime %d",lm);
    return 0;
}
