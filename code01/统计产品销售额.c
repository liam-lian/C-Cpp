//统计产品销售额 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a[7][6]={0},i,j,num;
    printf("请输入每人每天工作情况，(人，产品，销售额).以-1结束,如1,1,44 \n(人代号1--4，产品代号1--5)\n");
           scanf("%d,%d,%d",&i,&j,&num);
           while(i!=-1)
              {
                 a[j][i]+=num;
                 scanf("%d,%d,%d",&i,&j,&num);
              }
     for(i=1;i<=4;i++)
        for(j=1;j<=5;j++)
            a[6][i]+=a[j][i];
     for(j=1;j<=5;j++)
         for(i=1;i<=4;i++)
            a[j][5]+=a[j][i];
     for(i=1;i<=4;i++)
        a[0][i]=i;
     for(i=1;i<=5;i++)
        a[i][0]=i;   
     for(i=0;i<=6;i++)
         for(j=0;j<=5;j++)
           {
            if(a[i][j]!=0)
               printf("%-8d",a[i][j]);
            if(a[i][j]==0)
               printf("\t");
            if(j==5)
               printf("\n");
           }    
  system("PAUSE");	
  return 0;
}
