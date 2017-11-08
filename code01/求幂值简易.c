
  #include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
    double x;
  printf("please input an float number");
  scanf("%lf",&x);
  x=exp(x);
  printf("The result is:%.4lf",x);

  system("PAUSE");	
  return 0;
}
