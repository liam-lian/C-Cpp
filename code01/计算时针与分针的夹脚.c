#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) 
{
	float a,b,c;
	scanf("%f%f",&a,&b);
	c=fabs(a+b/60-b/5)*30;
	if(c>=180)
	  {
	  if(b<10)
	   printf("At %.f:0%.f the angle is %.1f degrees.\n",a,b,360-c);
	  else 
       printf("At %.f:%.f the angle is %.1f degrees.\n",a,b,360-c);
      }
	else   
	   {
	  if(b<10)
	   printf("At %.f:0%.f the angle is %.1f degrees.\n",a,b,c);
	  else 
       printf("At %.f:%.f the angle is %.1f degrees.\n",a,b,c);
      }
	return 0;
}
