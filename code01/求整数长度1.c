#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int a=10000000,b=0,i=7,number;
  printf("������һ����");9
  scanf("%d",&number);
  if(number==0)
  printf("����Ϊ1");
  else
  { 
  for(;number/a==0;i--)
  a=a/10;
  i=i+1;
  printf("����Ϊ%d",i);
}
  system("PAUSE");	
  return 0;
}
