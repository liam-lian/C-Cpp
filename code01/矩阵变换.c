//矩阵变换 //将n阶方阵，按每行平均数从小到大输出 
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int a[100][100]={0},i,j,n,p,b[100]={0};
    printf("Please input row of matrix:");
    scanf("%d",&n);
    printf("Please input elements of the matrix:");
    for(i=0;i<=n-1;i++)
       for(j=0;j<=n-1;j++)
          scanf("%d",&a[i][j]);
    for(i=0;i<=n-1;i++)
       for(j=0;j<=n-1;j++)  
             b[i]+=a[i][j];
    for(i=1;i<=n-1;i++)
       for(j=0;j<=n-2;j++)
          if(b[j]>b[j+1])
             for(p=0;p<=n-1;p++)
               {
                 a[n][p]=a[j][p];
                 a[j][p]=a[j+1][p];
                 a[j+1][p]=a[n][p];
                }
    for(i=0;i<=n-1;i++)
        {
       for(j=0;j<=n-1;j++)
           printf("%d",a[i][j]);               
         printf("\n");
         }                                   
  system("PAUSE");	
  return 0;
}
