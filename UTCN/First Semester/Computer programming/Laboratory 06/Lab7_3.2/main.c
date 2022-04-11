#include <stdio.h>
#include <stdlib.h>


typedef struct{
unsigned short zi,luna,an;
}Datacalend;
int bisect(unsigned short an){
    if((an%4==0 && an%100!=0) || an%400==0)
            return 1;
    return 0;
}
int nrzileluna(unsigned short luna,unsigned short an){
switch(luna){
    case 2:return 28+bisect(an);
    case 4:
    case 6:
    case 9:
    case 11: return 30;
}
return 31;
}
int acatazi(Datacalend d){
int nrzile=0,l;
for(l=1;l<d.luna;l++)
    nrzile+=nrzileluna(l,d.an);
return d.zi+nrzile;
}
int Valida(Datacalend d){
if(d.an<1600 || d.an>4900)
    return 0;
if(d.luna<1  || d.luna>12)
    return 0;
if(d.zi<1 || d.zi>nrzileluna(d.luna,d.an))
    return 0;
return 1;
}
Datacalend citesteData(){
Datacalend d;
do{
    printf("data(zz/ll/aaaa),");
    scanf("%2hu/%2hu/%4hu",&d.zi,&d.luna,&d.an);
    fflush(stdin);
}while(!Valida(d));
return d;
}
void aflarezi(Datacalend d,char x){
    int x,y;
    x=acatazi(d);
    d.an=2020;
    y=acatazi(d);
    printf("")

}///diferenta dintre nr de zile dintre ani modulo 7
int main()
{
    Datacalend d;
    d=citesteData();
    char x[10];
    gets(x);
    aflarezi(d,x);
    printf("te-ai nascut %c",ziua);
    return 0;
}

