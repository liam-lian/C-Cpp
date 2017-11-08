//自动售票系统 
#include <stdio.h>
#include <stdlib.h>
int p,w,i,JI=0,OU=5,l;
void  FEIXIYAN(int a[],int w);
void XIYAN(int a[],int p)
{
    int q;
    if(JI==5)
       JI=6;
    if(JI<=5)
       {
             JI++;
             printf("您在%d号座位\n",JI);
             a[JI]=1;
       }  
      if(JI>5&&OU!=10)
         {
          printf("没有吸烟区票了,你是否愿意被分在无烟区，愿意则输入1，不愿意则输入0\n");
          scanf("%d",&q);
          if(q==1)
               FEIXIYAN(a,w);
          if(q==0)
              printf("对不起，没吸烟区票了，请选下一航班\n");
         }
}
void  FEIXIYAN(int a[],int w)
{
      if(OU==10)
         OU=11;
       if(OU<=10)
       {
             OU++;    
             printf("您在%d号座位\n",OU);
             a[OU]=1;
        }
       if(OU>10&&JI!=6)
       {
       printf("没有无烟区票了,你是否愿意被分在吸烟区，愿意则输入1，不愿意则输入0\n");
          scanf("%d",&l);
       if(l==1)
               XIYAN(a,w);
       if(l==0)
              printf("对不起，没无烟区票了，请选下一航班\n");
       }      
}             
int main(int argc, char *argv[])
{
    int a[11]={0},b,q,z=1;
    while(z==1)
     {
       printf("欢迎使用售票系统，吸烟区请输入1，非吸烟区输入0\n");
       scanf("%d",&b);
       
       if(b==1)
        XIYAN(a,p);
       if(b==0)
        FEIXIYAN(a,w);
       if(b!=0&&b!=1)
         printf("请输入正确指令：");
         if(JI>=6&&OU>=10)
          {
          printf("票全卖光了,请等下一航班。。\n");
          z=0;
          }
        
     }
  system("PAUSE");	
  return 0;
}
