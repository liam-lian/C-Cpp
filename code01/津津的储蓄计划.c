#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i,a[12],ok=1,j,sum=0,rest=0;
  for(i=0;i<=11;i++)
     scanf("%d",&a[i]);
  for(i=0;i<=11&&ok==1;i++)
     {
       rest+=(300-a[i]);
       if(rest<0)
         {
         printf("-%d",i+1);
         ok=0;
         }
       if(rest>=100)
       {
        sum=sum+rest-rest%100;
        rest%=100;
        }
      }
      if(ok==1)
        printf("%d",1.2*sum+rest);                                      
  system("PAUSE");	
  return 0;
}
