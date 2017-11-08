#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n,p=2,i=2,inprim=0,count=0;
  printf("please input a number:");
  scanf("%d",&n);
  for(;p<=n;p++)
  {
     for(;i<p&&inprim==0;)
    {
    if(p%i!=0)
    i++;
    else
    inprim=1;
    }
      if(inprim==0)
       { 
        printf("%d   ",p);
          count++; 
       if(count%5==0)
        printf("\n");
        }
        i=2;
        inprim=0;
   }
 system("PAUSE");	
  return 0;
}







