#include <stdio.h>
#include <stdlib.h>
#define Nmax 20
void zero(float v[])
{
    int i;
    for(i=0;i<=Nmax;i++)
        v[i]=0;
}
int citire_polinom(float c[Nmax])
{
    int gr,i;
    printf("dati gradul polinomului: ");
    scanf("%d",&gr);
    printf("Dati coeficientii polinomului(incepand cu cel mai mare grad) ");
    for(i=gr;i>=0;i--)
    {
        printf("c[%d]= ",i);
        scanf("%f",&c[i]);
    }
    return gr;
}
void afisare_polinom(float c[],int maxx)
{
    int i;
    for(i=maxx;i>=0;i--)
        printf("%.2f ",c[i]);
    printf("\n");
}
void adunare(float cA[Nmax],float cB[Nmax],int maxx,float rezAD[Nmax])
{
    int i;
    for(i=maxx;i>=0;i--)
        rezAD[i]=cA[i]+cB[i];
}
void scadere(float cA[],float cB[],int maxx,float rezSC[])
{
    int i;
    for(i=maxx;i>=0;i--)
        rezSC[i]=cA[i]-cB[i];
}
void inmultire(float cA[],float cB[],int grA,int grB,float rezInm[])
{
    int i,j;
    for(i=grA;i>=0;i--)
        for(j=grB;j>=0;j--)
            rezInm[i+j]=rezInm[i+j]+(cA[i]*cB[j]);
}
void inmultire_cu_un_nr(float nr,float v[],int grv,float intermediar[],int grCat)
{
    int i;
    for(i=grv;i>=0;i--)
        intermediar[i]=v[i-grCat]*nr;
}
int impartire(float cA[],int grA,float cB[],int grB,float cat[],int grCat,int coef)
{
    float intermediar[Nmax];
    if(grA<grCat-1)
        return grCat;
    else {
            cat[coef]=cA[grA]/cB[grB];
            inmultire_cu_un_nr(cat[coef],cB,grA,intermediar,coef);
            scadere(cA,intermediar,grA,cA);
            return impartire(cA,grA-1,cB,grB,cat,grCat,coef-1);
    }
}
int main()
{
    int grA,grB,maxx,g,grcat;
    float cA[Nmax],cB[Nmax],rezAD[Nmax],rezSC[Nmax],rezInm[Nmax+Nmax+1],cat[Nmax];
    zero(cA); zero(cB); zero(rezAD); zero(rezSC); zero(rezInm); zero(cat);
    grA=citire_polinom(cA);
    grB=citire_polinom(cB);
    if(grA>grB)
        maxx=grA;
    else maxx=grB;
    adunare(cA,cB,maxx,rezAD);
    printf("Rezultatul ADUNARII este : gradul %d cu coeficientii ",maxx);
    afisare_polinom(rezAD,maxx);
    scadere(cA,cB,maxx,rezSC);
    printf("Rezultatul SCADERII este : gradul %d cu coeficientii ",maxx);
    afisare_polinom(rezSC,maxx);
    maxx=grA+grB;
    inmultire(cA,cB,grA,grB,rezInm);
    printf("Rezultatul INMULTIRII este : gradul %d cu coeficientii ",maxx);
    afisare_polinom(rezInm,maxx);
    if(grA>=grB){
        g=grA-grB;
        grcat=impartire(cA,grA,cB,grB,cat,g,g);
        printf("Rezultatul IMPARTIRII este : gradul %d cu coeficientii ",grcat);
        afisare_polinom(cat,grcat);
        printf("\n cu restul de coeficienti: ");
        afisare_polinom(cA,g-1);
    }
    else printf("Impartirea polinoamelor nu este posibila!(gradul polinomului A este mai mic decat gradul polinomului B)");
    return 0;
}
