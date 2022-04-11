#include <stdio.h>
#include <stdlib.h>

int main()
{
    float xa,ya,xb,yb,xc,yc,xd,yd,mAB,mBC,mCD,mDA,mAC,mBD;
    printf("Dati coordonatele punctului A: ");
    scanf("%f %f",&xa,&ya);
    printf("Dati coordonatele punctului B: ");
    scanf("%f %f",&xb,&yb);
    printf("Dati coordonatele punctului C: ");
    scanf("%f %f",&xc,&yc);
    printf("Dati coordonatele punctului D: ");
    scanf("%f %f",&xd,&yd);
    mAB=(yb-ya)/(xb-xa);
    mBC=(yc-yb)/(xc-xb);
    mCD=(yd-yc)/(xd-xc);
    mDA=(ya-yd)/(xa-xd);
    mAC=(yc-ya)/(xc-xa);
    mBD=(yd-yb)/(xd-xb);
    if((xa+xc)/2==(xb+xd)/2 && (ya+yc)/2==(yb+yd)/2)
    {
        if(mAB==-1/mBC && mAB==-1/mDA && mAB==mCD)
        {
            if(mAC==-1/mBD)
                printf("Figura este patrat.\n");
            else printf("Figura este dreptunghi\n");
        }
        else
        {
            if(mAC==-1/mBD)
                printf("Figura este romb\n");
            else printf("Figura este paralelogram\n");
        }
    }
    else printf("Figura nu formeaza un patrulater regulat\n");
    return 0;
}
