#include <stdio.h>
#include <stdlib.h>
void muta(char a,char b,int n){
    static int nr=1;
    printf("mutarea %d: %c --> %c discul:%d  \n",nr++,a,b,n);
}
void hanoi(int n,char a,char b,char c){
if(n==1)
    muta(a,c,1);
else{
    hanoi(n-1,a,c,b);
    muta(a,c,n);
    hanoi(n-1,b,a,c);
}
}
int main()
{
    int n;
    printf("n=");
    scanf("%d",&n);
    hanoi(n,'A','B','C');
    return 0;
}
