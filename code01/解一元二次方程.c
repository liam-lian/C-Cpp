#include <stdio.h>
#include <math.h>
int main(void)
{
	float a,b,c,X1,X2,m,n;

	printf ("please input three float number: ");
	scanf  ("%f %f %f",&a,&b,&c);

	if (a==0)
		printf ("The equation is not quadratic.\n");
	else
	{
	X1=(-b+sqrt(b*b-4*a*c))/(2*a);
	X2=(-b-sqrt(b*b-4*a*c))/(2*a);
	if (fabs(X1-X2)<=1e-6)
		printf ("The equation has two equal roots: %.4lf\n",X1);
	else if (b*b-4*a*c>0)
		printf ("The equation has two distinct roots: %.4lf and %.4lf\n",X1,X2);
	else 
	{
         	m=-b/(2*a);
		n=sqrt(-b*b+4*a*c)/(2*a);
		printf ("The equation has two complex roots:%.4lf+%.4lfi and %.4lf-%.4lfi\n",m,n,m,n);
}
    }
  system("PAUSE");	
    return 0;
}
