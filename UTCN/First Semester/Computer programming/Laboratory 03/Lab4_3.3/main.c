
#include <stdio.h>
#include <stdlib.h>
#define N 30
int main()
{
    //3.3
    float a[N],min,max;
    int n,imin,imax,i;
   /* printf("Nr de elemente <=%d ",N);
    scanf("%d",&n);
    if(n<1 || n>N)
      {
        printf("Valoare gresita");
        return 0;
      }*/
      for(n=0;n<1 || n>N;scanf("%d",&n))
        printf("nr elemente <=%d ",N); //fflash(stdin) goleste buffer-ul
     /* n=0;
      while(n<1 ||n>N)
      {
          printf("nr elemente <=%d",N);
          scanf("%d",&n);
      }*/
    printf("Elementele:\n");
    for(i=0;i<n;i++)
       {
            printf("a[%d]=",i);
            scanf("%f",&a[i]);
       }
    min=a[0]; imin=0;
    max=a[0]; imax=0;
    for(i=1;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            imin=i;
        }
        if(a[i]>max)
        {
            max=a[i];
            imax=i;
        }
    }
      printf("min= %.2f si pozitia= %d\n",min,imin);
      printf("max= %.2f si pozitia= %d",max,imax);
    return 0;
}
