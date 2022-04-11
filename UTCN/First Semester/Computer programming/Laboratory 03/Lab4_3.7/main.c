#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BAZA_MAX 16
int main()
{
    int baza,nrb10,cifra,i;
    char nr[32];
    printf("Baza(intre 2 si %d) = ",BAZA_MAX);
    scanf("%d",&baza);
    printf("nr in baza %d =",baza);
    scanf("%31s",nr);
    nrb10=0;
    for(i=0;nr[i]!='\0';i++)
       {
        if(nr[i]>='0' && nr[i]<='9')
         cifra=nr[i]-'0';
        else {
                nr[i]=toupper(nr[i]); //transforma literele mici in litere mari
                if(nr[i]>='A' && nr[i]<='Z')
                    cifra=nr[i]-'A'+10;
                else {
                        printf("caracter gresit: %c\n",nr[i]);
                        return 0;
                }
        }
        if(cifra>=baza)
            printf("cifra gresita %c (%d) \n",nr[i],cifra);
        nrb10=nrb10*baza+cifra;
       }
       printf("nr in baza 10= %d",nrb10);
    return 0;
}
