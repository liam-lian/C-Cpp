#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i=1,n;
    long long int result=1;
  printf("������һ��������:");
 scanf("%d",&n); 
  for(;i<=n;i++)
  result*=i;
  printf("The result is %lld",result);
  system("PAUSE");	//������һ�������� 
  return 0;
}
