//蛇形矩阵 
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   int a[100][100]={0},i=0,j=0,n,num,p=1,q=1;
   printf("Please input order of the snake matrix:");
   scanf("%d",&n);
   for(num=1;num<=(n*n);num++)
      {
             a[i][j]=num;
             if(j==0&&i!=n-1&&q==1)
                {
                i++;
                q++;
                }
             else if(i==0&&j!=n-1&&p==1)
                {
                j++;
                p++;
                }    
            else if(j==n-1&&p==1)
                {
                i++;
                p++;
                }
            else if(i==n-1&&q==1)
                {
                j++;
                q++;
                }                  
           else if(p==2)//向左下方 
                {
                 i++;
                 j--;
                 if(j==0||i==n-1)
                    p=1;
                 }                 
             else if(q==2)//向右上方 
                {
                 j++;
                 i--;
                 if(i==0||j==n-1)
                    q=1;
                 }
            }
   for(i=0;i<=n-1;i++)
       {
      for(j=0;j<=n-1;j++)
        printf("%-3d ",a[i][j]); 
      printf("\n");
      }                                       
  system("PAUSE");	
  return 0;
}
