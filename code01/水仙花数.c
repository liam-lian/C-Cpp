 //��һ����λ����λ���η�֮�͵����䱾��Ϊˮ�ɻ��� 
 #include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int a,b,c,num;
  printf("please input an interger:");
  scanf("%d",&num);
  a=num/100;
  b=(num/10)%10;
  c=num%10;
  if(a*a*a+b*b*b+c*c*c==num)
  printf("the result is:Yes");
  else
  printf ("the result is:No");
    system("PAUSE");	
  return 0;
}






