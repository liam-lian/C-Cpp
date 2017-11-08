#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

const double	PI=3.14159265;
	double r,c,s;
 
	printf ("Please input a float number: \n");
		scanf ("%lf",&r);
		c=2*PI*r;
		s=PI*r*r;

printf ("The perimeter is %.4lf the area is  %.4lf\n",c,s);

  system("PAUSE");	
  
  return 0;
}
