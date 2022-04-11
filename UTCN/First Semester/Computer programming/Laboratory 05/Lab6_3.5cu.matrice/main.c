#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nmax 200
void citsiruri(int *pn,char mat[][Nmax]){
    int i;
    printf("dati numarul de siruri: ");
    scanf("%d",pn);
    printf("dati sirurile: ");
    for(i=0;i<*pn;i++){
        fgets(mat[i],Nmax,stdin);

    }
}
void afissiruri(char mat[][Nmax],int n){
    int i;
    for(i=0;i<n;i++)
        printf("%s\n",mat[i]);
}
void schimba(int p,int q,char mat[][Nmax]){
    char aux[Nmax];
    strcpy(aux,mat[p]);
    strcpy(mat[p],mat[q]);
    strcpy(mat[q],aux);
}
void bubbles(char mat[][Nmax],int n)
{
    int sortat=0,i;
    while(!sortat)
    {
        sortat=1;
        for(i=1;i<n;i++)
        if(strcmp(mat[i-1],mat[i])>0){
            schimba(i-1,i,mat);
            sortat=0;
        }
    n--;
    }
}
int main()
{
    char mat[Nmax][Nmax];
    int n;
    citsiruri(&n,mat);
    bubbles(mat,n);
    afissiruri(mat,n);
    return 0;
}
