/*�󰰵�,���㼰������Ϊ�����е����ֵ�������е���Сֵ*/ 
#include <stdio.h>
#include <stdlib.h>
int Findmax(int a[][100],int i,int j);
int Findmin(int a[][100],int i,int j); 
int main(int argc, char *argv[])
{
    int a[100][100]={0},I,J,i,j,p=0;
    printf("����������������:");
    scanf("%d %d",&I,&J);
    printf("����������:\n");
    for(i=0;i<=I-1;i++)
       for(j=0;j<=J-1;j++)
         scanf("%d",&a[i][j]);
  for(i=0;i<=I-1;i++)
     for(j=0;j<=J-1;j++)
        if(i==Findmin(a,I,j)&&Findmax(a,i,J)==j)
           {    
            printf("��%d�е�%d��,����%d�ǰ���\n",i+1,Findmax(a,i,J)+1,a[i][Findmax(a,i,J)]);
            p++;
            }
            printf("���㹲%d��\n",p);
  system("PAUSE");	
  return 0;
}
int Findmax(int a[][100],int i,int j)//�ҵ���i�����ֵ�����б� 
{ 
    int p=0,max=a[i][0],c=0;
    for(p=1;p<=j-1;p++)
        if(a[i][p]>=max)
            c=p;
    return c;        
}  
int Findmin(int a[][100],int i,int j)//�ҵ���j����Сֵ�����б� 
{
    int p=0,min=a[0][j],c=0;
    for(p=1;p<=i-1;p++)
        if(a[p][j]<=min)
           c=p;
    return c;
}           
