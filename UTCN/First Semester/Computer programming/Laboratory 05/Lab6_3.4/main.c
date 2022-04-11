#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-5
double f(double x){
    return sin(x); //x*x-3*x+2
}
double rad(double a,double b,double (*p)(double)){
    double x,fx;
    do{
        x=(a+b)/2;
        fx=(*p)(x);
        if(fx*(*p)(a)<0)
            b=x;
        else
            a=x;
    }while(b-a>EPS && fabs(fx)>=EPS);
    return x;
}

int main()
{
   //metoda injumatatirii intervalului
   //f(a)*f(b)<0 f(x)<e
   double a,b;
   printf("a=");
   scanf("%lf",&a);
   printf("b=");
   scanf("%lf",&b);
   double x=rad(a,b,f);
   printf("rad din [%.2f,%.2f] : %.2f\n",a,b,x);
    return 0;
}
