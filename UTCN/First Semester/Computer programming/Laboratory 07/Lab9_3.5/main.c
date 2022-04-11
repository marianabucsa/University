#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int index(const char *sir,const char *subsir){
 char *p=strstr(sir,subsir);
 int n=0;
 if(p==NULL)
    return -1;
    //else return p-sir; /pentru prima pozitie a subsirului
 else{
        printf("%d ",p-sir+n); //n devine mereu 0 nu e bun
        return index(sir+(p-sir)+strlen(subsir),subsir);
 }
}
void eliminaLF(char *sir){
int n=strlen(sir);
if(sir[n-1]=='\n')
    sir[n-1]='\0';
}
int main()
{
    char sir[255],subsir[255];
    int n;
    printf("dati sirul de caractere: ");
    fgets(sir,255,stdin);
    eliminaLF(sir);
    printf("dati subsirul: ");
    fgets(subsir,255,stdin);
    eliminaLF(subsir);
    n=index(sir,subsir);
   // if(n==-1) doar pentru prima pozitie
      //  printf("subsirul nu se afla in sir");
    //else printf("subsirul se afla in sir incepand cu pozitia %d \n",n);
return 0;
}
