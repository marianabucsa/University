#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char adunare(char s1[40],int n,char s2[40],int m)
{
    char s3[40];
    if(m>n)
    strcpy(s1+(m-n),s1);
    for(i=m-n-1;i>=0;i--)
        s1[i]=0;
        for(i=m-1;i>=0;i--)
    {
        s=s1[i]+s2[i];
        if(s>=10)
            s3[i]=

    }
}
char scadere(char s1[40],int n,char s2[40],int m)
{

}
char inmultire(char s1[40],int n,char s2[40],int m)
{

}
char impartire(char s1[40],int n,char s2[40],int m)
{

}
int main()
{
    char s1[40],s2[40],ra[40],rs[40],rin[40],rim[40];
    printf("dati cele 2 nr ca siruri de caractere\n ");
    gets(s1);
    gets(s2);
    int n,m;
    n=strlen(s1);
    m=strlen(s2);
    ra=adunare(s1,n,s2,m);
    rs=scadere(s1,n,s2,m);
    rin=inmultire(s1,n,s2,m);
    rim=impartire(s1,n,s2,m);
    return 0;
}
