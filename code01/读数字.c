//������-99----99֮����� 
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
       printf("�ɣΣУУգԡ��ţңңϣ�\n"); 
  else
     {
         for(i=a;i<=b;i++)
            {    if(i==0)
                 DUSHU(0);          
                 c=i;       //Ŀ���Ǻ���iС��0ʱ��iֵ�仯���Ժ���ѭ������Ӱ�죬ͨ��c��ý������ 
                 if(i<0)
                  {
                  printf("FU ");
                  i=i*-1;    
                  }//��������Ϊ�� 
                  if(i/10>1)//��λ����һ                           
                  DUSHU(i/10);
                  if(i/10!=0)//��λ��Ϊ0 
                  printf("SHI ");
                  if(i%10!=0)//β����Ϊ�㡣�������Ƕ���0����ȴҪ���β����������0Ҫ�������� 
                  DUSHU(i%10);
                  printf("\n");
                  i=c;
            }
     }                                                     
  system("PAUSE");	
  return 0;
}
