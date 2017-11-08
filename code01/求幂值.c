#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
    int i=1;
  double x,result=1.0,a=1.0;
  printf("please input an float number");
  scanf("%lf",&x);
   while (fabs(a)>=1e-8)
{
         result=result+a*x/i;
         a=a*x/i;
i++;
}
printf("The result is:%.4lf",result);
  system("PAUSE");	
  return 0;
}
