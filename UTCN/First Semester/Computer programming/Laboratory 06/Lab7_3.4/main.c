#include <stdio.h>
#include <stdlib.h>
typedef struct{
float re,im;
}complex;
complex adunare(complex a,complex b);
complex inmultire(complex a,complex b);
complex valpol(complex x,int grad,complex a[]){
complex v={0,0};
int i;
for(i=grad;i>=0 i--)
    v=adunare(inmultire(v,x),a[i]);
return v;
}
complex adunare(complex a,complex b){
complex r;
r.re=a.re+b.re;
r.im=a.im+b.im;
return r;
}
complex inmultire(complex a,complex b){
complex r;
r.re=a.re*b.re-a.im*b.im;
r.im=a.re*b.im+a.im*b.re;
return r;
}
complex citirecom(){
complex val;
printf(" dati valori lui a si b (a+b*i)= " )
scanf("%f + %f*i",&val.re,&val.im);
return val;
}
int main()
{

    return 0;
}
