//���仯���� 
#include <stdio.h>
#include <stdlib.h>
long long int fib(int n);
long long int fib1(int n);
int main(int argc, char *argv[])
{
      int n;
      scanf("%d",&n);
    printf("fib1=%lld\n",fib1(n));
    printf("fib=%lld\n",fib(n));
      system("PAUSE");	
      return 0;
}
long long int fib(int n)
{
   if (n==0) return 0;
   if (n==1) return 1;
   return fib(n-1)+fib(n-2);
}
long long int fib1(int n) 
{
    int solved[10000];
    if (n==0) return 0;
    if (n==1) return 1;
    if (solved[n])
       return solved[n];
    return solved[n]=fib1(n-1)+fib1(n-2);
}
//ͨ��fib1���Դ�����߼���Ч��,�����ٶ������ӿ�,���Լ���fib���ܼ�������֡� 
