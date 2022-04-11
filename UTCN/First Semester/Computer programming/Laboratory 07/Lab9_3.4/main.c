#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void stergere(char *d,int poz,int nr){
if(poz>=strlen(d))
    return ;
if(poz+nr>=strlen(d))
    d[poz]='\0';
else
    memmove(d+poz,d+poz+nr,strlen(d+poz+nr)+1);
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
    char d[255];
    int poz,nr;
    printf("dati un sir de caractere: ");
    fgets(d,255,stdin);
    printf("dati pozitia: ");
    scanf("%d",&poz);
    printf("dati nr de caractere: ");
    scanf("%d",&nr);
    stergere(d,poz,nr);
    afisare(d);
return 0;
}
