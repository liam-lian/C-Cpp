#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a,b,c,d;
    float x=1.0,e=0;
    printf("please input four intrgers:");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    while(fabs(x-e)>1e-5)
   {
    e=x;
    x=x-(a*x*x*x+b*x*x+c*x+d)/(3*a*x*x+2*b*x+c);
   }
  printf("The solution is:%f",x);
  system("PAUSE");	
  return 0;
}
