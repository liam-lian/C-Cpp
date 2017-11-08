#include <stdio.h>
#include <stdlib.h>
long long int f(int n)
{
    if(n==1)
     return 1;
    else
     return f(n-1)*n;
}
int main(int argc, char *argv[])
{
    int n;
    printf("请输入一个数：");
    scanf("%d",&n);
    printf("%d!=%lld\n",n,f(n));
    system("PAUSE");
    return 0;
}
