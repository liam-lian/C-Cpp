//�Զ���Ʊϵͳ 
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
             printf("����%d����λ\n",JI);
             a[JI]=1;
       }  
      if(JI>5&&OU!=10)
         {
          printf("û��������Ʊ��,���Ƿ�Ը�ⱻ������������Ը��������1����Ը��������0\n");
          scanf("%d",&q);
          if(q==1)
               FEIXIYAN(a,w);
          if(q==0)
              printf("�Բ���û������Ʊ�ˣ���ѡ��һ����\n");
         }
}
void  FEIXIYAN(int a[],int w)
{
      if(OU==10)
         OU=11;
       if(OU<=10)
       {
             OU++;    
             printf("����%d����λ\n",OU);
             a[OU]=1;
        }
       if(OU>10&&JI!=6)
       {
       printf("û��������Ʊ��,���Ƿ�Ը�ⱻ������������Ը��������1����Ը��������0\n");
          scanf("%d",&l);
       if(l==1)
               XIYAN(a,w);
       if(l==0)
              printf("�Բ���û������Ʊ�ˣ���ѡ��һ����\n");
       }      
}             
int main(int argc, char *argv[])
{
    int a[11]={0},b,q,z=1;
    while(z==1)
     {
       printf("��ӭʹ����Ʊϵͳ��������������1��������������0\n");
       scanf("%d",&b);
       
       if(b==1)
        XIYAN(a,p);
       if(b==0)
        FEIXIYAN(a,w);
       if(b!=0&&b!=1)
         printf("��������ȷָ�");
         if(JI>=6&&OU>=10)
          {
          printf("Ʊȫ������,�����һ���ࡣ��\n");
          z=0;
          }
        
     }
  system("PAUSE");	
  return 0;
}
