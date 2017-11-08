#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,j;
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    {
      for(j=1;j<=2*n-1;j++)
      {
          if(j<=i||j>=2*n-i)
           printf(" ");
          else
          printf("#");
      }
      printf("\n");
     }
     system("pause");
     return 0;
}
