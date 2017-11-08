#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   int a[1000],i,j,isok=0,n;
   printf("请输入苹果的个数及质量：");
   scanf("%d",&n); 
   for(i=1;i<=n;i++)
   scanf("%d",&a[i]); 
   for(i=1;i<=n&&isok==0;i++)
      {
      for(j=i+1;j<=n;j++)
        if(a[i]==a[j])
           {
           printf("相同的苹果的质量是：%d\n",a[i]);
           isok=1;
           }
      }                                 
  system("PAUSE");	
  return 0;
}
