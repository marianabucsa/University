#include <stdio.h>
#include <stdlib.h>
int hermite(int n,int x){
if(n==0)
    return 1;
if(n==1)
    return 2*x;
else
    return 2*x*hermite(n-1,x)-2*(n-1)*hermite(n-2,x);

}
int hermite_nr(int n,int x){
int p=2,h0,h1,h;
h0=1;
h1=2*x;
while(p<=n)
    {
        h=2*x*h1-2*(p-1)*h0;
        h0=h1;
        h1=h;
        p++;
    }
    return h;

}
int main()
{
    int n,x,k;
    printf("n=");
    scanf("%d",&n);
    printf("x=");
    scanf("%d",&x);
    k=hermite(n,x);
    printf("varianta recursiva: %d \n",k);
    k=hermite_nr(n,x);
    printf("varianta nerecursiva: %d",k);
    return 0;
}
