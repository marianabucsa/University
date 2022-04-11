#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define  M_PI 3.14159265
int main()
{
    //3.2
    /*int cod;
    printf("Apasati o tasta speciala:");
    cod=getch();
    printf("%d",cod);
    cod=getch();
    printf(" %d\n",cod);*/
    //3.3
   /* int cod;
    printf("Dati un nr intreg <=127 sau >=32");
    scanf("%d",&cod);
    printf("conectorul:");
    putch(cod);*/
   /* int cod;
    for(cod=127;cod<256;cod++)
        printf("%c %3d   ",cod,cod);*/
    // 3.4
    /*char ch;
    printf("Dati un caracter:");
    scanf("%c",&ch);
    printf("codul: %d\n",ch);*/
    // 3.5
   /* int nr;
    printf("Dati un numar din intervalul [32,126]:");
    scanf("%d",&nr);
    printf("reprezentarea in ASCII a nr %d este %c",nr,(char)nr);*/
    //3.6
   /*char s[20];
    int i=0;
    gets(s);
    while(s[i]!=NULL)
    {
        printf("%c ",s[i]); //vedem ce se salveaza pe fiecare pozitie in sir
        i++;
    }*/
    //citirea caracterului \n (new line) este transformat in \0 (null)
    //3.7
    /*char c;
    printf("Dati o litera mica:");
    scanf("%c",&c);
    printf("Litera mare corespunzatoare = %c",c-('a'-'A'));*/
    //3.8
    /*char c;
    printf("Dati o litera mare:");
    scanf("%c",&c);
    printf("Litera mica corespunzatoare = %c",c+('a'-'A'));*/
    //3.9
    float a,b;
    printf("Dati 2 numere reale:");
    scanf("%f %f",&a,&b);
    printf(" x= %.2f\n ",a);
    printf(" y= %.2f\n ",b);
    printf(" x+y= %.2f\n ",a+b);
    printf(" x-y= %.2f\n ",a-b);
    printf(" x*y= %.2f\n ",a*b);
    printf(" x/y= %.2f\n ",a/b);
    //3.10
    /*printf("%c\n",(char)M_PI);
    printf("%d\n",(int)M_PI);
    printf("%f\n",(float)M_PI);
    printf("%o\n",(int)M_PI);
    printf("%x\n",(int)M_PI);
    printf("%ld\n",(long)M_PI);
    printf("%lf\n",(double)M_PI);*/
    //3.11
    /*int nr;
    printf("Dati un numar intreg zecimal:");
    scanf("%d",&nr);
    printf("Numarul in octal: %o\n",nr);
    printf("Numarul in hexazecimal: %x",nr);*/
    return 0;
}
