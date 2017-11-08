#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int is_prime(int n)
{
    int i;
    for(i=2;i*i<=n;i++)
       if(n%i==0) return 0;
    return 1;
}
main()
{
    int prime[100],i,j,count=0,ans[100]={0};
    int m;
    for(i=2;i<=100;i++)
     if(is_prime(i))
       prime[count++]=i;//得到1-100的素数表
    int n;
    int maxp=0;
    while(scanf("%d",&n)==1)
    {
       maxp=0;//标记所打印的最大坐标
       memset(ans,0,sizeof(ans));//清空数组ans
       printf("%d!=",n);
       for(j=2;j<=n;j++)
         {
           m=0;
           int temp=j;
           while(temp>=prime[m]&&m<count)
           {
             while(temp%prime[m]==0)
               {
                 ans[m]++;
                 temp/=prime[m];
               }
               m++;
           }
         if(m-1>maxp) maxp=m-1;
        }
        for(i=0;i<=maxp;i++)
           printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
