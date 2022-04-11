#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void subsir(char *d,const char *s,int poz,int nr)
{
    if(poz>=strlen(s))
        d[0]='\0'; //nr vid
    else {
        strncpy(d,s+poz,nr);
        d[nr]='\0';
    }
}
void afisare(char d[255]){
int i,n;
n=strlen(d);
printf("subsirul este: ");
for(i=0;i<n;i++)
    printf("%c",d[i]);
printf("\n");
}
int main()
{
    char s[255],d[255];
    int poz,nr;
    printf("dati un sir de caractere: ");
    fgets(s,255,stdin);
    printf("dati pozitia de la care incepe copierea: ");
    scanf("%d",&poz);
    printf("dati nr de caractere ce trebuie copiate: ");
    scanf("%d",&nr);
    subsir(d,s,poz,nr);
    afisare(d);
return 0;
}
