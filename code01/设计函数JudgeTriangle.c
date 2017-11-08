//设计函数判断三角形形状 
#include <stdio.h>
#include <stdlib.h>
int JudgeTriangle(int a,int b,int c)
{
    if(a+b>c&&a+c>b&&b+c>a)//判断是否为三角形 
    {
      if(a==b&&b==c)//等边三角形 
       return(3);
      else if(a==b||b==c||a==c)//等腰三角形 
      return(2);
      else if(a*a+b*b==c*c||a*a+c*c==b*b||b*b+c*c==a*a)//直角三角形 
      return(1);
      else                    //普通三角形/ 
      return(0);
      }
    else            //不构成三角形 
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
