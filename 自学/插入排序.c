#include <stdio.h>
#include <stdlib.h>
#define N 10
#define key(A)(A)
#define change(A,B){int t=A;A=B;B=t;}
#define less(A,B)(key(A)<key(B))
main ()
{
    int a[N],i,j,k,t;
    for(i=0;i<N;i++) scanf("%d",&a[i]);
    for(i=1;i<N;i++)
       for(j=0;j<i;j++)
          if(less(a[i],a[j])){
            t=a[i];
            for(k=i;k>j;k--)
               a[k]=a[k-1];
                a[j]=t;
          }
    for(i=0;i<N;i++)
    printf("%d\n",a[i]);
    return 0;
}
