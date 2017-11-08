#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i,n,line=1;
  printf("please input a number");
  scanf("%d",&n);
  for(;line<=n;line++)
  {
    for(i=1;i<=2*n-1;i++)
      {
      if((i>=n-line+1)&&(i<=n+line-1))
      printf("*");
      else
      printf(" ");
      }
      printf("\n");
      }
  system("PAUSE");	
  return 0;
}
