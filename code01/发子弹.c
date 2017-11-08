#include <stdio.h>
#include <stdlib.h>
int same(int*);
int main()
{
    int sum=0,a[10]={10,2,8,22,16,4,10,6,14,20},b[10],i;
    while(!same(a))
    {
        printf("THE %2d EXCHANGE ",sum);
        for(i=0;i<=9;i++)
          printf("%2d ",a[i]);
        printf("\n");
        sum++;
        for(i=0;i<=9;i++)
        {
         if(a[i]%2==1)
            a[i]++;
         b[i]=a[i];
        }
       for(i=0;i<=9;i++)
        {
         a[(i+1)%10]+=b[i]/2;
         a[i]-=b[i]/2;
        }
    }
   printf("THE %2d EXCHANGE ",sum);
        for(i=0;i<=9;i++)
          printf("%2d ",a[i]);
        printf("\n");
   return 0;
}
int same(int *a)
{
    int i,ok=1;
    for(i=1;i<=9;i++)
      if(a[i]!=a[0])
        ok=0;
    return ok;
}
