//�������Լ������С���������� 
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
 int GCD(int a,int b);//���Լ������ 
 int LCM(int a,int b);//��С���������� 
int main()
{
  int a,b;
  printf("please input two integers:");
  scanf("%d %d",&a,&b);
  printf("the greatest common divisor is %d and the lowest common multiple is %d\n", GCD(a,b),LCM(a,b)); 
  system("PAUSE");	
  return 0;
}
  int GCD(int a,int b)
   {int min,i,c;
       if(a>=b)
       min=b;
       else
       min=a;
       for(i=1;i<=min;i++)
         if(a%i==0&&b%i==0)
         c=i;
          return(c);
    }
  int LCM(int a,int b)
   {   
      int i;
      i=a*b/GCD(a,b);
      return(i);
    } 
      

  

