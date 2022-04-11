#include <stdio.h>
#include <stdlib.h>
FILE* deschide(const char *nume,const char *mod){
 FILE *pf=fopen(nume, mod);
 if (pf==NULL){
    perror(nume);
    exit(1);
 }
 return pf;
 }
void inverseaza(int n,const char *nume1,){
if(n==0)
    return;
char cuv[31];
fgets(cuv,30,pf1);
inverseaza(n-1);
fprintf(,cuv,)
}
int main()
{
    char nume1[]="fis1.txt";
    char nume2[]="fis2.txt";
    FILE* pf1=deschide(nume1,"r");
    FILE* pf2=deschide(nume2,"w");
    fscanf(nume1,&n);
    //printf("n=");
    //scanf("%d",&n);
    inverseaza(n);
    return 0;
} //problema 10 mai ramane
