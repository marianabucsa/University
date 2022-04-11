#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
float im,re;
}complex;
FILE* deschide(const char *nume,const char *mod){
 FILE *pf=fopen(nume, mod);
 if (pf==NULL){
    perror(nume);
    exit(1);
 }
 return pf;
 }
void creeazaFis(const char *nume){
FILE*pf =deschide(nume,"w");
complex c;
double mod,arg;
int n,i;
printf("nr de numere complexe: ");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("[%d]:",i);
    scanf("%f%f",&c.re,&c.im);
    mod=sqrt(c.re*c.re+c.im*c.im);
    arg=atan2(c.im,c.re);
    fprintf(pf, "%f %f %.8f %.8f\n",c.re,c.im,mod,arg);
}
fclose(pf);
}
void afiseazaFis(const char *nume){
FILE*pf=deschide(nume,"r");
complex c;
double mod,arg;
while(fscanf(pf,"%f%f%lf%lf",&c.re,&c.im,&mod,&arg)==4){
    printf("%2f+i*%2f ",c.re,c.im);
    printf("modul:%.8f,arg:%.8f grade \n",mod,arg/M_PI*180);
}
fclose(pf);
}
int main()
{
    char nume[]="fis.txt";
    creeazaFis(nume);
    afiseazaFis(nume);
    return 0;
}
