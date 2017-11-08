//求数据，个数，和，平均值，中位数，众数，并打印频数直方图 
#include <stdio.h>
#include <stdlib.h>
void printarray(int a[],int num);
void Paixu(int a[],int num);
int main(int argc, char *argv[])
{
    int i,a[100]={0},Pinshu[100]={0},c[100],num=0,j,sum=0,p=1,max=0,q,isok=1;
    float mid;
    printf("请输入数据，以-1结束：");
    for(i=0;i<=99&&a[i-1]!=-1;i++)//注意i-1 
        {
           scanf("%d",&a[i]);
           if(a[i]!=-1)
              {
                sum=sum+a[i];
                num++;
              }
         }                                         //读取数据，并计算数据个数 
    printf("您共输入了%d个数据，其和为%d，平均数为%.2f\n该%d个数分别为\n",num,sum,(float)sum/num,num);
    printarray(a,num);                            //排序 
    printf("经排序，结果为：\n");
    Paixu(a,num);                             //打印数组 
    mid=num%2==0?(float)(a[num/2]+a[num/2-1])/2:(float)a[num/2];//求中位数 
    printf("中位数为：%.2f\n统计直方图为:\n",mid);
      c[0]=a[0]; 
    for(i=1;i<=num-1;i++)                  //找出所有出现过的数字，存入c        
      {
          for(j=0;j<i&&isok==1;j++)
            {
                if(a[i]==a[j])
                isok=0;
            }
          if(isok==1)
            {
                 c[p]=a[i];
                 p++;
            }
          isok=1;             //注意初始化 
      }
     for(i=0;i<=num;i++)
        for(j=0;j<=p-1;j++)
               if(a[i]==c[j])
                     Pinshu[j]++;//求各数频数 
    printf("%-8s%-8s%-8s\n","数字","次数","直方图");
    for(i=0;i<=p-1;i++)
        {
            printf("%-8d%-8d",c[i],Pinshu[i]);
            for(j=1;j<=Pinshu[i];j++)
              printf("%c",1);
            printf("\n");  
        }     
    for(i=0;i<=p;i++)      // 求众数 
        if(Pinshu[i]>max)
          {
             max=Pinshu[i];
             q=c[i];
          }
    printf("%d ",q);      
    for(i=q;i<=p;i++)
       if(Pinshu[i]==max)
          printf("%d ",c[i]);//考虑多个众数 
    printf("为众数，出现了%d次\n",max);
    system("PAUSE");	
    return 0;
}
void printarray(int array[],int num)//打印数组。8个一行 
{
     int i;
     for(i=0;i<=num-1;i++)
        {
           printf("%d ",array[i]);
           if((i+1)%8==0)
              printf("\n");
        }
         printf("\n");
}   
void Paixu(int a[],int n)//数组排序 
{
     int i,j,k;
     for(i=0;i<=n-2;i++)
       for(j=i+1;j<=n-1;j++)
            if(a[i]>a[j])
              {
                 k=a[i];
                 a[i]=a[j];
                 a[j]=k;
              }
     printarray(a,n);
}                                                
