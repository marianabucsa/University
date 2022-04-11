#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 255
void inserare(char *d,const char *s,int poz);
void afisare(char d[255]){
int i,n;
n=strlen(d);
printf("subsirul este: ");
for(i=0;i<n;i++)
    printf("%c",d[i]);
printf("\n");
}
void eliminaLF(char *s){
int n=strlen(s);
if(s[n-1]=='\n')
    s[n-1]='\0';
}
int main()
{
    char s[255],d[255];
    int poz;
    printf("dati sirul de caractere sursa: ");
    fgets(s,255,stdin);
    eliminaLF(s);
    printf("dati siurl de caractere destinatie: ");
    fgets(d,N,stdin);
    printf("dati pozitia de la care se insereaza ");
    scanf("%d",&poz);
    inserare(d,s,poz);
    afisare(d);
return 0;
}
/*void inserare(char *d,const char *s,int poz){
if(poz>strlen(s))
    return;
char aux[N];
strcpy(aux,d+poz);
strcpy(d+poz,s);
strcat(d,aux);
}*/
// alta varianta
void inserare(char *d,const char *s,int poz){
if(poz>strlen(s))
    return;
memmove(d+poz+strlen(s),d+poz,strlen(d+poz)+1);
strncpy(d+poz,s,strlen(s));
}
