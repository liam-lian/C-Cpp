//果园里的树 
#include <stdio.h>
#include <stdlib.h>
double area(double x1,double y1,double x2,double y2,double x3,double y3);
int main()
{
    double x1,y1,x2,y2,x3,y3,ar;
    int  x0,y0,i=0;
    scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
    ar=area(x1,y1,x2,y2,x3,y3);
    for(x0=1;x0<=99;x0++)
       for(y0=1;y0<=99;y0++)
         if(fabs(fabs(area(x0,y0,x2,y2,x3,y3))+fabs(area(x1,y1,x0,y0,x3,y3))+fabs(area(x1,y1,x2,y2,x0,y0))-fabs(ar))<=1e-9)
            i++;
    printf("%d",i);
    return 0;
}
double area(double x1,double y1,double x2,double y2,double x3,double y3)//三角形有向面积的二倍 
{
    return x1*y2+x3*y1+x2*y3-x3*y2-x2*y1-x1*y3;
}
