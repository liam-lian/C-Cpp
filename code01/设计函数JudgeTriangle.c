//��ƺ����ж���������״ 
#include <stdio.h>
#include <stdlib.h>
int JudgeTriangle(int a,int b,int c)
{
    if(a+b>c&&a+c>b&&b+c>a)//�ж��Ƿ�Ϊ������ 
    {
      if(a==b&&b==c)//�ȱ������� 
       return(3);
      else if(a==b||b==c||a==c)//���������� 
      return(2);
      else if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)//ֱ�������� 
      return(1);
      else                    //��ͨ������/ 
      return(0);
      }
    else            //������������ 
    return(-1);
}                            
int main(int argc, char *argv[])
{
    int a,b,c;
    printf("Please input three integers:");
    scanf("%d %d %d",&a,&b,&c);
    switch(JudgeTriangle(a,b,c))
    {
      case -1:printf("It is not a triangle.\n");break;
      case 0:printf("It is a scalenous triangle.\n");break;
      case 1:printf("It is a right-angled triangle.\n");break;       
      case 2:printf("It is an isoscele triangle.\n");break;    
      case 3:printf("It is a equilateral triangle.\n");break;
    }
  system("PAUSE");	
  return 0;
}
