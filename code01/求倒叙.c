#include <stdio.h>
#include <stdlib.h>
int pow(int n)/*计算10的n次方*/ 
{
    int sum=1,i;
    for(i=1;i<=n;i++)
       sum=sum*10;
    return sum;
}           
int leng(int n)/*递归计算n的长度*/
{
    if(n/10==0)
    return 1;
    else
    return leng(n/10)+1;
} 
int daoxu(int n)/*定义倒叙函数*/ 
{    
    if(leng(n)==1)
    return n;
    else
    return daoxu(n/10)+(n%10)*pow(leng(n)-1);//把最后一位提到第一位 
}    
int main(int argc, char *argv[])
{
    int n; 
    printf("请输入数字："); 
    scanf("%d",&n);
    printf("倒叙后为:%d\n",daoxu(n));
    system("PAUSE");	
    return 0;
}
