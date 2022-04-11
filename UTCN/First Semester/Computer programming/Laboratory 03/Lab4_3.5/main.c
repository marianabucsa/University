#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n,a;
    printf("dati n (numar natural):");
    scanf("%d",&n);
    a=sqrt(n);
    printf("cel mai mare patrat perfect mai mic decat %d= %d",n,a*a);
    return 0;
}
