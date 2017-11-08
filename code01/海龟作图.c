//海龟作图 --指令：1-笔朝上、2-笔朝下、3-右转弯、4-左转弯、5，x-向前走x步 、6-打印轨迹、9-数据结束； 
#include <stdio.h>
#include <stdlib.h>
#define EAST 1
#define WEST 2
#define SOUTH 3
#define NORTH 4
void TURTLEPRINT(int a[]); 
int main(int argc, char *argv[])
{
  int a[100]={0},i;
  printf("输入指令,以9结束:");
  scanf("%d",&a[0]);
  for(i=1;a[i-1]!=9;i++)
       scanf("%d",&a[i]);
  TURTLEPRINT(a);     
  system("PAUSE");	
  return 0;
}
void TURTLEPRINT(int a[])
{
     int b[80][80]={0},pen=0,M=25,N=25,dir=NORTH,i,j,p;
     for(i=0;a[i]!=9;i++)
          switch(a[i])
             {
                 case 1:pen=0;break;
                 case 2:pen=1;b[M][N]=1;break;
                 case 3:switch(dir)
                       {
                         case 1:dir=SOUTH;break;
                         case 2:dir=NORTH;break;
                         case 3:dir=WEST;break;
                         case 4:dir=EAST;break;
                       };break;           
                 case 4:switch(dir)
                       {
                          case 1:dir=NORTH;break;
                          case 4:dir=WEST;break;
                          case 3:dir=EAST;break;
                          case 2:dir=SOUTH;break;
                       };break;
                 case 5:switch(dir)
                      {
                         case 1:N+=a[i+1];
                                    if(pen==1)
                                       for(j=N-a[i+1];j<=N;j++)       //切不要忘了加上break！!!!!!!!!!!!!!!!!!!!! 
                                           b[M][j]=1;break;           //
                         case 2:N-=a[i+1];                            //
                                    if(pen==1)
                                       for(j=N+a[i+1];j>=N;j--)
                                           b[M][j]=1;break;
                         case 3:M+=a[i+1];
                                    if(pen==1)
                                       for(j=M-a[i+1];j<=M;j++)
                                           b[j][N]=1;break;
                         case 4:M-=a[i+1];
                                    if(pen==1)
                                       for(j=M+a[i+1];j>=M;j--)
                                           b[j][N]=1;break;
                      };i++;break;
                 case 6:for(j=0;j<=49;j++)
                        {
                          for(p=0;p<=49;p++)
                           {
                             if(b[j][p]==0)
                                 printf(".");
                             if(b[j][p]==1)
                                printf("%c",1);          
                            }
                        printf("\n");                          
                        };printf("\n");break;
          }
}                                                                                               
