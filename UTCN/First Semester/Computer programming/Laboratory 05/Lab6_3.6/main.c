#include <stdio.h>
#include <stdlib.h>
float *citire(int *n)
{
    printf("nr elemente : ");
    scanf("%d",n);
    float *a=(float *)calloc(*n,sizeof(float));//aloca un bloc de dimensiunea n returneaza adresa la care incepe alocarea
    if(a==NULL)
      {
        printf("Memorie insuficienta");
        exit(1);
      }
    int i;
    for(i=0;i<*n;i++){
        printf("[%d]=",i);
        scanf("%f",&a[i]);//a+i
    }
    return a;
}
int cautare(int *a,int na,int *b,int nb)
{
    int i,j;
    i=0;
    while(i<=na-nb){
        for(j=0;j<nb;j++)
            if(b[j]!=a[i+j])
                break;
        if(j==nb)
            return i;
        else i++;
    }
    return -1;
}
int main()
{
    int *a,*b,m,n;
    printf("tabloul in care cauta(a):\n");
    a=citire(&m);
    printf("tabloul cautat (b):\n");
    b=citire(&n);
    printf("b apare in a pe pozitiile: ");
    int nrAp=0,poz,ind=0;
    while(ind<m && (poz=cautare(a+ind,m-ind,b,n))>=0){
        nrAp++; ind+=poz;
        printf("%d ",ind);
        ind++;
    }
    if(nrAp==0)
        printf("b nu apare in a.");
    return 0;
}
