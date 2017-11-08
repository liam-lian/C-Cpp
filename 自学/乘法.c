//求一序列乘积最大的子序列
#include<stdio.h>
#include<stdlib.h>
main()
{
    int max=-1,a[18]={0},n,t;
    while(scanf("%d",&n))
    {
        max=-1;
        int i,j;
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<n;i++){
          t=1;
          for(j=i;j<n;j++){
           t*=a[j];
           if(t>max) max=t;
          }
        }
        max<=0?printf("-1\n"):printf("%d\n",max);
    }
    return 0;
}
