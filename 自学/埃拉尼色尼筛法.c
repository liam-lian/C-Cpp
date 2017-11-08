#include <stdlib.h>
#include <stdio.h>
#define N 10000
main()
{
  int i,j,a[N];
  for(i=2;i<N;i++) a[i]=1;
  for(i=2;i<N;i++)
   if(a[i])
     for(j=2;j<N;j++)
       if(i*j<N)
          a[i*j]=0;
  for(i=2;i<N;i++)
   if(a[i]) printf("%d\n",i);
  return 0;
}
