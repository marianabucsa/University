#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void elib(char **ts,int n){
    int i;
    for(i=0;i<n;i++)
        free(ts[i]);
    free(ts);
}
char** citsiruri(int *pn){
    printf("nr siruri: ");
    scanf("%d%*c",pn);
    char** ts=(char**)calloc(*pn,sizeof(char*));
    if(ts==NULL)
        exit(1);
    char s[200];
    int i;
    printf("sirurile de caractere :\n");
    for(i=0;i<*pn;i++){
        fgets(s,200,stdin);
        ts[i]=(char*)malloc(strlen(s)+1);
        if(ts[i]==NULL) exit(1);
        else strcpy(ts[i],s);
    }
    return ts;
}
void schimba(char **p,char **q){
    char*aux;
    aux=*p;
    *p=*q;
    *q=aux;
}
void bubbles(char **ts,int n){
    int sortat=0,i;
    while(!sortat)
    {
        sortat=1;
        for(i=1;i<n;i++)
        if(strcmp(ts[i-1],ts[i])>0){
            schimba(&ts[i],&ts[i-1]);
            sortat=0;
        }
        n--;
    }
}
void afissiruri(char **ts,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%s\n",ts[i]);
}
int main()
{
    //alocare dinamica
    char **ts;
    int n;
    ts=citsiruri(&n);
    bubbles(ts,n);
    printf("sirurilein ordine crescatoare: \n");
    afissiruri(ts,n);
    elib(ts,n);
    return 0;
}
