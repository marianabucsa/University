#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
FILE* deschide(const char *nume,const char *mod){
 FILE *pf=fopen(nume, mod);
 if (pf==NULL){
    perror(nume);
    exit(1);
 }
 return pf;
 }
 void creeazaFis(const char *nume){
 FILE*pf=deschide(nume,"w");
 char s[N];
 printf("dati linii de text ,la sfarsit ctrl+e si enter \n");
 while(fgets(s,N,stdin)!=NULL)
    fputs(s,pf);
 fclose(pf);
 }
 void afiseazaFis(const char *nume){
 FILE* pf=deschide(nume,"r");
 char s[N];
 int nrLinie=1;
 printf("1. ");
 while(fgets(s,N,pf)!=NULL){
    printf("%s",s);
    if(s[strlen(s)-1]=='\n')
        printf("%d.  ",++nrLinie);
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
