#include <stdio.h>
#include <stdlib.h>
#define nmax 20
void citire_m(float a[][nmax+1],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {   printf("dati coeficientii ecuatiei urmati de rezultat: ");
        for(j=0;j<=n;j++)
            scanf("%f",&a[i][j]);
        printf("\n");
    }
}
void afisare_rez(float r[],int n)
{
    printf("\n");
    int i;
    for(i=0;i<n;i++)
        printf("%.2f ",r[i]);
}
void inmultire_cu_nr(float nr,float a[][nmax+1],int n,int linie)
{
    int i;
    for(i=0;i<=n;i++)
        a[linie][i]=a[linie][i]*nr;
}
void scadere_linie(float a[][nmax+1],int linie,int n,int pasi)
{
    int j;
    for(j=0;j<=n;j++)
        a[linie][j]=a[linie-pasi][j]-a[linie][j];
  //  printf("\n");
   // for(j=0;j<=n;j++)
    //    printf("%.2f ",a[linie][j]);
}
int linie_rez(float a[][nmax+1],int n,int linie,int pasi,int j)
{
    int c;
    if(pasi==0)
        return -1;
    else{
        c=a[linie-pasi][j]/a[linie][j];
        inmultire_cu_nr(c,a,n,linie);
        scadere_linie(a,linie,n,pasi);
        return linie_rez(a,n,linie,pasi-1,j+1);
    }
}
void formare_rez(float a[][nmax],float r[],int n)
{
    int k=0;
    for(i=n-1;i>=0;i--)
        for(j=0;j<n;j++)
    {
        if(a[i][j]!=0 && j<n)


    }
}
void rezolvare(float a[][nmax+1],int n,float r[])
{
    int i,ok,j,k;
    for(i=1;i<n;i++){
        ok=linie_rez(a,n,i,i,0);
        if(ok==-1)
        for(k=0;k<n;k++)
        {
            for(j=0;j<=n;j++)
                printf("%.2f ",a[k][j]);
            printf("\n");
        }
    }
    formare_rez(a,r,n);
}
int main()
{
    float a[nmax][nmax+1],r[nmax];
    int n;
    printf("dati nr de ecuatii liniare: ");
    scanf("%d",&n);
    citire_m(a,n);
    rezolvare(a,n,r);
    //afisare_rez(r,n);
    return 0;
}
