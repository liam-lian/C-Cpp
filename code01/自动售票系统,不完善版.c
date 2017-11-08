#include <stdio.h>
#include <stdlib.h>
int p,w,i,JI=0,OU=6;
void  FEIXIYAN(int a[],int w);
void XIYAN(int a[],int p)
{
    int q;
    if(JI==5)
       JI=6;
    if(JI<=5)
       {
             JI++;
             printf("你在%d号\n",JI);
             a[JI]=1;
       }  
      if(JI>5)
         {
          printf("没有吸烟区票了,你是否愿意被分在无烟区，愿意则输入1，不愿意则输入0\n");
          scanf("%d",&q);
          if(q==1)
               FEIXIYAN(a,w);
          if(q==0)
              printf("对不起，没票了，请选下一航班\n");
         }
}
void  FEIXIYAN(int a[],int w)
{
       if(OU<=10)
       {
             printf("你在%d号\n",OU);
             a[OU]=1;
             OU++;
        }
       if(OU>10)
         printf("所有票都已售完，请选下一航班\n");
}                   
int main(int argc, char *argv[])
{
    int a[11]={0},b,q,z=1;
    for(;JI<=6&&OU<=10;)
     {
       printf("欢迎使用售票系统，吸烟区请输入1，非吸烟区输入0\n");
       scanf("%d",&b);
       if(b==1)
        XIYAN(a,p);
       else
        FEIXIYAN(a,w);
       for(i=0;i<=10;i++)
         if(a[i]!=0)
             z++;     
     }
  system("PAUSE");	
  return 0;
}
