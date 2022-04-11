#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int numarator,numitor;//numitor>0
}Rational;
int cmmdc(int a,int b){
while(a!=b)
{
    if(a>b)
        a=a-b;
    else b=b-a;
}
return a;
}
void simplifica(Rational *pf){
int c=cmmdc(abs(pf->numarator),abs(pf->numitor));//(*pf).numitor;
pf->numarator/=c;
pf->numitor/=c;
}
Rational aduna(Rational f1,Rational f2){
Rational r;
r.numarator=f1.numarator*f2.numitor+f1.numitor*f2.numarator;
r.numitor=f1.numitor*f2.numitor;
simplifica(&r);
return r;
}
Rational citestefractia(){
Rational f;
do{
    printf("p/q: ");
    fflush(stdin);
    }while( scanf("%d/%d",&f.numarator,&f.numitor)<2 || f.numitor==0);
    if(f.numitor<0){
        f.numarator=-f.numarator;
        f.numitor=-f.numitor;
    }
    simplifica(&f);
    return f;
}
void afiseaza(Rational f){
    printf("%d",f.numarator);
    if(f.numitor!=0 && f.numitor!=1)
        printf("/%d",f.numitor);
}
int main()
{
    Rational f1,f2,r;
    printf("prima fractie: \n");
    f1=citestefractia();
    printf("a doua fractie: \n");
    f2=citestefractia();
    r=aduna(f1,f2);
    afiseaza(f1);
    printf(" + ");
    afiseaza(f2);
    printf(" = ");
    afiseaza(r);
    return 0;
}
