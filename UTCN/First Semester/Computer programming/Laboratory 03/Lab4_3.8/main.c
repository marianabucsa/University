#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Nmax 20
int main()
{
    int grad,i;
    float c[Nmax],x,valPol;
    printf("dati gradul polinomului(<=%d):",Nmax);
     scanf("%d",&grad);
    printf("dati coeficientii( incepand cu cel mai mare grad):");
    for(i=grad+1;i>=1;i--)
    {
        printf("c[%d]= ",i);
        scanf("%f",&c[i]);
    }
    printf("Dati valoare lui x = ");
    scanf("%f",&x);
    valPol=c[0];
    for(i=1;i<=grad+1;i++)
        valPol=valPol+c[i]*pow(x,i);
    printf("valoarea polinomului= %.2f",valPol);
    return 0;
}
