//求一序列乘积最大的子序列
#include<stdio.h>
#include<stdlib.h>
main()
{
    int k,x,y;
    while(scanf("%d",&k)==1)
    {
      int sum=0;
      for(y=k+1;y<=2*k;y++)
        {
            if((k*y)%(y-k)==0)
              {
                  sum++;
                  printf("1/%d=1/%d+1/%d\n",k,(k*y)/(y-k),y);
              }

        }
       printf("%d\n",sum);

    }
    return 0;
}
