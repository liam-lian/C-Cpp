#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main()
{
    float a,b,c;
    float S,area;
    printf("please input three integers:");
    scanf ("%f %f %f",&a,&b,&c);
    if((a+b<c)||(a+c<b)||(b+c<a))
    printf("the edges cannot make up of a triangle");
    else
    {
        S=(a+b+c)/2;
        area=sqrt(S*(S-a)*(S-b)*(S-c));
        printf("the area of the triangle is %.3lf",area);
        
    }
    
  
  system("PAUSE");	
  return 0;
}
