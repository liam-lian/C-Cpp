#include <stdio.h>
#include <stdlib.h>
#define N 10
#define key(A)(A)
#define change(A,B){int t=A;A=B;B=t;}
#define less(A,B)(key(A)<key(B))
main ()
{
    int a[N],i,j,min;
    for(i=0;i<N;i++)  scanf("%d",&a[i]);
    for(i=0;i<N;i++){
      min=i;
      for(j=i;j<N;j++){
         if(less(a[j],a[min]))
            min=j;
        }
        change(a[i],a[min]);
    }
    for(i=0;i<N;i++)
    printf("%d\n",a[i]);
    return 0;
}
