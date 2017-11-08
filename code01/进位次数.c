#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,n,i;
    scanf("%d %d",&a,&b);
    for(;a&&b;)
    {
       int sum=0;
       for(;a&&b;)
        {
         sum+=((a%10)+(b%10))>9?1:0;
         a/=10;b/=10;
        }
        printf("%d\n",sum);
        scanf("%d %d",&a,&b);
    }
    return 0;
}
