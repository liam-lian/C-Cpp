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
    printf("���������ֵ��������Լ��������֣�\n");
    scanf("%d",&n);
    printf("���ֵ��%d",Max(n));
    printf("\n");
    system("PAUSE");	
    return 0;
}
