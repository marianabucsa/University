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
void afisare(float *a, int n)
{
    int i;
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%.2f ",a[i]);
    }
}
float *interclasare(float a[],int na,float b[],int nb,int *nc)
{
    *nc=na+nb;
    float*c=(float*)calloc(*nc,sizeof(float));
    if(c==NULL){
        printf("memorie insuficienta");
        exit(1);
    }
    int i,j,k;
    i=j=k=0;
    while(i<na && j<nb)
    {
        if(a[i]<=b[j])
            c[k++]=a[i++];//pune in i si dupa face ++ ;pune in k si dupa face ++ ;[++k] face ++ si dupa pune in k
        else
            c[k++]=b[j++];
    }
        while(i<na)c[k++]=a[i++];
        while(j<nb)c[k++]=b[j++];
    return c;
}
int main()
{
    float *a,*b,*c;
    int na,nb,nc;
    printf("primul vector ordonat crescator: \n");
    a=citire(&na);
    printf("al doilea vector ordonat crescator: \n");
    b=citire(&nb);
    c=interclasare(a,na,b,nb,&nc);
    free(a);
    free(b);//elibereaza spatiul
    printf("vectorul rezultat: \n");
    afisare(c,nc);
    free(c);
    return 0;
}
