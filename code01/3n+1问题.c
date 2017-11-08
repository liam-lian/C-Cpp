#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i=0,n;
  scanf("%d",&n);
  for(;;)
  {
      if(n==1)
        break;
      if(n%2==0)
        n=n/2;
      else
       n=3*n+1;
      i++;
  }
  printf("%d",i);
    return 0;
}
