//�ۺϵ� 
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int a[100][100]={0},m,n,i,j,isok=1,p,q;
    printf("Please input row and column of the matrix:");
    scanf("%d %d",&m,&n);
    printf("Please input element of the matrix:");
    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    printf("The result is:\n");        
    for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
         {        
          for(p=i-1;p<=i+1&&isok==1;p++)
             for(q=j-1;q<=j+1&&isok==1;q++)
                 if(a[i][j]<a[p][q])
                    isok=0;
          if(isok==1)
          printf("(%d,%d)\n",i-1,j-1);
          isok=1;   
          }
  
  system("PAUSE");	
  return 0;
}
//Ϊ���ų��߽�Ԫ�ص����⣬������Ȧ����0���ǳ�����˳����� 
