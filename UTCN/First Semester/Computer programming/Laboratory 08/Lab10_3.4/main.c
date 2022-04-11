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
void concat(FILE*pr,const char*nume){
FILE *pf=deschide(nume,"r");
float nr;
while(fscanf(pf,"%f",&nr)==1)
    fprintf(pr,"%f ",nr);
fprintf(pr,"\n");
fclose(pf);
}
void afiseazaFis(FILE*pr){
float nr;
while(fscanf(pr,"%f",&nr)==1)
    printf("%2f ",nr);
}
int main()
{
    FILE *pr=deschide("rez.txt","w+");
    char nume[20];
    int n,i;
    printf("nr de fisiere de concatenat:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
     sprintf(nume,"fis%d.txt",i);
     concat(pr,nume);
    }
    rewind(pr);
    afiseazaFis(pr);
    fclose(pr);
    return 0;
}
