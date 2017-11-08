#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i=1,n;
    long long int result=1;
  printf("请输入一个正整数:");
 scanf("%d",&n); 
  for(;i<=n;i++)
  result*=i;
  printf("The result is %lld",result);
  system("PAUSE");	//请输入一个正整数 
  return 0;
}
