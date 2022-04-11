#include <stdio.h>
#include <stdlib.h>
void afisare(int lista[100],int q){
    int i;
    for(i=1;i<=q;i++)
        printf("%d ",lista[i]);
    printf("\n");
}
int determinare(float x[],int n,int q,float a,float b,int j){
 float punct=0;
 int k=0,lista[q],i,ok=0;
    for(i=j;i<=n;i++)
    {
        if(punct>=a && punct<=b && k==q)
        {
            printf("solutia este :");
            afisare(lista,q);
            ok=1;
            k--; punct=punct-x[i];
        }

    else {
            if(punct>b)
            {
                k--;
                punct=punct-x[i];
            }
            else{
            punct=punct+x[i];
            k++;
            lista[k]=i;
            }
    }
    }
    if(j+1<=n)
        return determinare(x,n,q,a,b,j+1);
    else{
        if(ok==1)
            return 1;
        else return 0;
    }
}
int main()
{
    int n,i,q;
    float x[100],a,b;
    printf("dati nr de intrebari ");
    scanf("%d",&n);
    printf("dati punctajul intrebarilor de la 1 la %d \n",n);
    for(i=1;i<=n;i++)
    {
        printf("%d. ",i);
        scanf("%f",&x[i]);
    }
    printf("dati nr de intrebari ce trebuie sa apara in chestionar ");
    scanf("%d",&q);
    printf("dati intervalul in care sa se afle punctajul ");
    scanf("%f %f",&a,&b);
    if(q==0 || q>n)
        exit(1);
   int p=determinare(x,n,q,a,b,1);
   if(p==0)
    printf("\n nu exista solutie");
    return 0;
}
