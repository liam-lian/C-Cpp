#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n,k,i,j=1,a[1000]={0};
   scanf("%d %d",&n,&k);
  for(j=1;j<=k;j++)
   for(i=1;i<=n;i++)
    {
      if(i%j==0)
        {
         /*if(a[i]==0)
           a[i]=1;
         else
           a[i]=0;*/
        a[i]=!a[i];   
        }
    }
   for(i=1;i<=n;i++)
     if(a[i]==1)
       printf("%d ",i);
   system("pause");
   return 0;
}
