#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  int i=1,j=1;
  for(;i<=9;i++)
   {             
    for(j=1;j<=i;j++)
       {
        printf("%d*%d=%d ",i,j,i*j);
        if(j==i)
        printf("\n");
        }
    }    
  system("PAUSE");	
  return 0;
}
