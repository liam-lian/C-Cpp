//读出从-99----99之间的数 
#include <stdio.h>
#include <stdlib.h>
void DUSHU(int n)
{
     switch(n)
     {
     case 0:printf("LING ");break; 
     case 1:printf("YI ");break;
     case 2:printf("ER ");break;
     case 3:printf("SAN ");break;
     case 4:printf("SI ");break;
     case 5:printf("WU ");break;
     case 6:printf("LIU ");break;
     case 7:printf("QI ");break;
     case 8:printf("BA ");break;
     case 9:printf("JIU ");break;
     } 
}     
int main(int argc, char *argv[])
{
  int a,b,c,p=1,i;
  printf("Please input two integers:");
  scanf("%d%*c%d",&a,&b);
  if(a<-99||b>99)
       printf("ＩＮＰＰＵＴ　ＥＲＲＯＲ\n"); 
  else
     {
         for(i=a;i<=b;i++)
            {    if(i==0)
                 DUSHU(0);          
                 c=i;       //目的是后面i小于0时，i值变化，对后面循环产生影响，通过c起媒介作用 
                 if(i<0)
                  {
                  printf("FU ");
                  i=i*-1;    
                  }//负数处理为正 
                  if(i/10>1)//首位大于一                           
                  DUSHU(i/10);
                  if(i/10!=0)//首位不为0 
                  printf("SHI ");
                  if(i%10!=0)//尾数不为零。。。但是对于0本身却要输出尾数，，所以0要单独讨论 
                  DUSHU(i%10);
                  printf("\n");
                  i=c;
            }
     }                                                     
  system("PAUSE");	
  return 0;
}
