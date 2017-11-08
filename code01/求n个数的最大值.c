#include <stdio.h>
#include <stdlib.h>
int Max(int n)
{
    int num,max;
    if(n==1)
    {
    scanf("%d",&num);
    return num; 
     }
     else
      scanf("%d",&num);
      max=Max(n-1);
      return max>num?max:num;
}      
int main(int argc, char *argv[])
{
    int n;
    printf("请输入数字的数量，以及各个数字：\n");
    scanf("%d",&n);
    printf("最大值：%d",Max(n));
    printf("\n");
    system("PAUSE");	
    return 0;
}
