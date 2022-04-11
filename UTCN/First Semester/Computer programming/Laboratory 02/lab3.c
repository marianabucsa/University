#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.141592
# include <math.h>
int main()
{
    //3.2
    /*double x,y,z;
    printf("Dati 2 nr intregi");
    scanf("%lf%lf",&x,&y);
    z=pow(y,x);
    printf("%.0lf=%.0lf la puterea %.0lf",z,y,x);*/
    //3.3
    /*int a,b;
    printf("Dati 2 valori:");
    scanf("%d%d",&a,&b);
    if(b!=0)
    {
        printf("Catul impartirii: %d\n",a/b);
        printf("Restul:%d\n",a%b);
        float c=a/b; //(float)a/b; a/(float)b;
        printf("Impartire reala:%f\n",c);
    }*/
    //3.4
    //r=g*pi/180
    //M_PI simbol sau #define M_PI 3.141592
    /*int g;
    printf("Dati unghiul in grade:");
    scanf("%d",&g);
    double r=g/180.0*M_PI;
    printf("sin(%d)=%10f\n",g,sin(r)); //cos,tan;*/
    //3.5
   /* int an;
    printf("Dati un an intre 1600 si 4900:");
    scanf("%d",&an);
    if(an<1600 || an>4900)
        printf("Nu se aplica");
    else
        if((an%4==0 && an%100!=0) || an%400==0)
            printf("E an bisect");
        else printf("Nu e an bisect");*/
    //3.6
    /*float x,fx;
    printf("x=");
    scanf("%f",&x);
    fx=x<-2?x*x+4*x+4:x==-2?0:x*x+5*x;
    printf("f(%.2f)=%.2f\n",x,fx);*/
    //3.7
   /* float r,g,m,s;
    printf("dati un unghi in radiani");
    scanf("%f",&r);
    g=r*180/M_PI;
    printf("%d grade ",(int)g);
    m=60*(g-(int)g);
    printf("%d minute ",(int)m);
    s=60*(m-(int)m);
    printf("%f sec ",s);*/
    //
    //printf("int ocupa %d octeti\n",sizeof(int);
    //3.9
    /*int x,y,p=1,cx,cy;
    long binx=0,biny=0; //corespondentii in binar ai lui x si y
    printf("Dati 2 nr intregi");
    scanf("%d %d",&x,&y);
    cx=x; cy=y;
    while(cx!=0)
    {
        binx=binx+(cx%2)*p;
        cx/=2;
        p=p*10;
    }
    p=1;
    while(cy!=0)
    {
        biny=biny+(cy%2)*p;
        cy/=2;
        p=p*10;
    }
    printf("%d in binar= %ld\n",x,binx);
    printf("%d in binar= %ld\n",y,biny);
    printf("x<<4:%d\n",x<<4);
    printf("y<<2:%d\n",y<<2);
    printf("x&y %d\n",x&y);
    printf("x^y %d\n",x^y);
    printf("x|y %d\n",x|y);*/
    //3.10
    //3.11
    /*int a,b,c,d; float x,y;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    x=a/b;
    y=c/d;
    if(x<y)
    printf("a/b<c/d");
    else printf("a/b>=c/d");*/
    //3.12
  /* float c1,c2,r,x1,y1,x2,y2,a,b,c;
    float d; //c1 si c2 coordonatele centrului cercului, r= raza, x,y coordonatele punctelor ce determina dreapta
   printf("dati coordonatele centrului: ");
   scanf("%f %f",&c1,&c2);
   printf("dati raza: ");
   scanf("%f",&r);
   printf("dati coordonatele celor doua puncte: ");
   scanf("%f %f",&x1,&y1);
   scanf("%f %f",&x2,&y2);
   a=y2-y1;
   b=x1-x2;
   c=y1*x2-x1*y2;
   d=abs(a*c1+b*c2+c)/sqrt(a*a+b*b);
   printf("%f %f ",d,r);
   if(d>r)
        printf("dreapta este exterioara.");
   if(d<r || d==0)
        printf("dreapta este secanta.");
    if(d==r) printf("dreapta este tangenta");*/
    //3.13
    /*char gen;
    float h,mb,mf;
    int v;
    printf("dati sexul persoanei(f pentru feminin respectiv m pentru masculin)\n");
    scanf("%c",&gen);
    printf("dati inaltimea persoanei(in centimetri)\n");
    scanf("%f",&h);
    printf("dati varsta persoanei(in ani)\n");
    scanf("%d",&v);
    mb=50+0.75*(h-150)+(v-20)/4;
    mf=mb-10;
    if(gen=='f')
        printf("masa ideala=%f",mf);
    if(gen=='m')
        printf("masa ideala=%f",mb);*/
    //p14 coordonate carteziene x,y coordonate polare lungimea vectorului si unghiul cu ox..cu cateta..*/
    //3.14
  /*  float x,y,l,u;
    printf("dati cordonatele carteziene:\n");
    scanf("%f %f",&x,&y);
    l=sqrt(x*x+y*y);
    u=atan2(x,y);
    u=u*180/M_PI;
    printf("lungimea vectorului=%.2f\n",l);
    printf("unghiul in grade=%.2f\n",u);
    printf("coordonatele polare:(%.2f,%.2f)",l,u);*/
    return 0;
}
