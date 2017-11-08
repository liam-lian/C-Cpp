/*波浪数，奇偶项分别相等，但二者不等*/
#include <stdio.h>
#include <stdlib.h>      
int leng(int n);/*递归计算n的长度*/
int isWaveNum(int n); 
int main(int argc, char *argv[])
{
    int n;
    scanf("%d",&n);
    switch(isWaveNum(n))
    {
      case 1:printf("YES\n");break;
      case 0:printf("NO\n");
    }                    
  system("PAUSE");	
  return 0;
}
int isWaveNum(int n)
{   
    int i,a,b,c,isok=1;
    a=n%10;
    n/=10;
    b=n%10;
    n/=10;
    if(a==b&&b!=0)//保证了前两位不相等，同时排除只有1位数的情况 
      isok=0;
    for(i=1;isok==1&&n!=0;i++)//已保证后两位不等，，，，其他只要间项相等即可 
        {
        c=n%10;
        n/=10;
        if((i%2==1&&c!=a)||(i%2==0&&c!=b))
          isok=0;
        }
    return isok;    
}
int leng(int n)/*递归计算n的长度*/
{
    if(n/10==0)
    return 1;
    else
    return leng(n/10)+1;
}     
