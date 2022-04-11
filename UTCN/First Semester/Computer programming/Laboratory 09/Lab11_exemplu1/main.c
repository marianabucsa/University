#include <stdio.h>
#include <stdlib.h>

void revers() {
char c;
scanf("%c",&c);
if (c!=' ' || c!='\n') {
printf("%c",c);
revers();
}
printf("%c",c);
}
int main() {
int n,i;
printf("Numarul de cuvinte=");
scanf("%d ",&n);
for(i=1;i<=n;++i)
{
revers();
printf("\n");
}
return 0;
}
