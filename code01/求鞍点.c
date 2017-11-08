/*求鞍点,鞍点及该数字为所在行的最大值，所在列的最小值*/ 
#include <stdio.h>
#include <stdlib.h>
int Findmax(int a[][100],int i,int j);
int Findmin(int a[][100],int i,int j); 
int main(int argc, char *argv[])
{
    int a[100][100]={0},I,J,i,j,p=0;
    printf("请输入行数和列数:");
    scanf("%d %d",&I,&J);
    printf("请输入数据:\n");
    for(i=0;i<=I-1;i++)
       for(j=0;j<=J-1;j++)
         scanf("%d",&a[i][j]);
  for(i=0;i<=I-1;i++)
     for(j=0;j<=J-1;j++)
        if(i==Findmin(a,I,j)&&Findmax(a,i,J)==j)
           {    
            printf("第%d行第%d列,数字%d是鞍点\n",i+1,Findmax(a,i,J)+1,a[i][Findmax(a,i,J)]);
            p++;
            }
            printf("鞍点共%d个\n",p);
  system("PAUSE");	
  return 0;
}
int Findmax(int a[][100],int i,int j)//找到第i行最大值所在列标 
{ 
    int p=0,max=a[i][0],c=0;
    for(p=1;p<=j-1;p++)
        if(a[i][p]>=max)
            c=p;
    return c;        
}  
int Findmin(int a[][100],int i,int j)//找到第j列最小值所在行标 
{
    int p=0,min=a[0][j],c=0;
    for(p=1;p<=i-1;p++)
        if(a[p][j]<=min)
           c=p;
    return c;
}           
