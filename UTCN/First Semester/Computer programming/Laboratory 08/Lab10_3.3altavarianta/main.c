#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
float im,re;
double mod,arg;
}complex;
FILE* deschide(const char *nume,const char *mod){
 FILE *pf=fopen(nume, mod);
 if (pf==NULL){
    perror(nume);
    exit(1);
 }
 return pf;
 }
void modif(const char *nume){
 FILE*pf=deschide(nume,"rb+");
 int i;
 printf("al catelea nr il modific : ");
 scanf("%d",&i);
 if(fseek(pf,i*sizeof(complex),SEEK_SET)==0){
    complex c;
    printf("noul numar: ");
    scanf("%f%f",&c.re,&c.im);
    c.mod=sqrt(c.re*c.re+c.im*c.im);
    c.arg=atan2(c.im,c.re);
    fwrite(&c,sizeof(complex),1,pf);
 }
    fclose(pf);
 }
void creeazaFis(const char *nume){
FILE*pf =deschide(nume,"wb");
complex c;
int n,i;
printf("nr de numere complexe: ");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("[%d]:",i);
    scanf("%f%f",&c.re,&c.im);
    c.mod=sqrt(c.re*c.re+c.im*c.im);
    c.arg=atan2(c.im,c.re);
    fwrite(&c,sizeof(complex),1,pf);
}
fclose(pf);
}
void afiseazaFis(const char *nume){
FILE*pf=deschide(nume,"rb");
complex c;
while(fread(&c,sizeof(complex),1,pf)==1){
    printf("%2f+i*%2f ",c.re,c.im);
    printf("modul:%.8f,arg:%.8f grade \n",c.mod,c.arg/M_PI*180);
}
fclose(pf);
}
int main()
{
    char nume[]="fis.txt";
    //creeazaFis(nume);
    modif(nume);
    afiseazaFis(nume);
    return 0;
}
