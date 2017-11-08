#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i=0,num;
    printf("please input a number");
    scanf("%d",&num);
    if(num==0)
     printf("the length of the number is 1");
      else
 {
        for(;num!=0;i++)
  {
    num/=10;             
     }
     printf("the length of the number is:%d",i);
  }
  system("PAUSE");	
  return 0;
}
