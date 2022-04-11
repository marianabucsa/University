#include <stdio.h>
#include <stdlib.h>
#define N 20
int citire_rel(int R[][2]);
int det_mult(int R[][2],int n,int M[]);
void afisare(int n,int a[]);
int reflexiva(int R[][2],int n,int M[],int m);
int simetrica (int R[][2],int n);
int tranzitiva (int R[][2],int n);
int exista(int val,int a[],int n);
int existainR(int x,int y,int R[][2],int n);
int main()
{
    //reflexiva xRx oricare ar fi x
    //simetrica xRy rezulta yRx oricare ar fi x,y
    //tranzitiva xRy ,yRz rezulta xRz oricare ar fi x,y,z
    /* (0,0) (1,1); (0,1); (0,0),(1,1),(0,1); (0,0)(0,1)(1,0)(1,1);*/
    int R[N][2],n,M[N*2],m;
    n=citire_rel(R);
    m=det_mult(R,n,M);
    afisare(m,M);
    int r=reflexiva(R,n,M,m);
    int s=simetrica(R,n);
    int t=tranzitiva(R,n);
    if(r==0) printf("reflexiva \n");
    if(s==0) printf("simetrica \n");
    if(t==0) printf("tranzitiva \n");
    if(r==0 && s==0 && t==0
       2222)
        printf("rel echivalenta");
    else printf("nu este rel echivalenta");
    return 0;
}
int citire_rel(int R[][2])
{
    int n,i;
    printf("nr perechi(<=%d)\n",N);
    scanf("%d",&n);
    printf("Perechile: \n");
    for(i=0;i<n;i++)
    {
        printf("[%d] ",i);
        scanf("%d%d",&R[i][0],&R[i][1]);
    }
    return n;
}
void afisare(int n,int a[])
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int det_mult(int R[][2],int n, int M[])
{
    int m=0,i,j;
    for(i=0;i<n;i++)
        for(j=0;j<2;j++)
        if(!exista(R[i][j],M,m))
            M[m++]=R[i][j];//pune in m si dupa creste m ; ++m creste m si dupa pune in m
    return m;
}
int exista(int val,int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]==val)
        return 1;
    return 0;
}
int reflexiva(int R[][2],int n,int M[],int m)
{
    int i;
    for(i=0;i<m;i++)
        if(!existainR(M[i],M[i],R,n))
        return 0;
    return 1;
}
int existainR(int x, int y,int R[][2],int n)
{
    int i;
    for(i=0;i<n;i++)
        if(R[i][0]==x && R[i][1]==y)
        return 0;
    return 1;
}
int simetrica(int R[][2],int n)
{
    int i;
    for(i=0;i<n;i++)
        if(!existainR(R[i][1],R[i][0],R,n))
        return 0;
    return 1;
}
int tranzitiva(int R[][2],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(R[i][1]==R[j][0])
                if(!existainR(R[i][0],R[j][1],R,n))
                    return 0;
    return 1;
}
