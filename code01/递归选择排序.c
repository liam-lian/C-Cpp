#include <stdio.h>
#include <stdlib.h>
int max(int a[],int n);//求1--n的最大值 
void Printfarray(int a[],int n);//打印函数。最后以回车而非空格结束
void RecuiSelectSort(int a[],int n);//递归，选择排序，将0--n的最大值放在最后，实现排序 
int main(int argc, char *argv[])
{
    int a[1000],n,i;
    printf("Please input the number of integers:");
    scanf("%d",&n);
    printf("Please input the integers:");
    for(i=0;i<=n-1;i++)
      scanf("%d",&a[i]);
    RecuiSelectSort(a,n); 
    printf("The result is:");
    Printfarray(a,n);
    system("PAUSE");	
    return 0;
}
int max(int a[],int n)//求1--n的最大值 
{
    int max=0,i=0,c=0;
    for(i=0;i<=n-1;i++)
        if(max<a[i])
        {
           max=a[i]; 
           c=i;
        }   
    return c;       
}  
void Printfarray(int a[],int n)//打印函数。最后以回车而非空格结束 
{
     int i,j=0;
     for(i=0;i<=n-1;i++)
       {
        j++;
        if(j!=n)                
        printf("%d ",a[i]);
        if(j==n)                
        printf("%d",a[i]);
        }
     printf("\n");             
}         
void RecuiSelectSort(int a[],int n)//递归，选择排序，将0--n的最大值放在最后，实现排序 
{
     int b,i;
     if(n!=0)
     {     
         b=a[max(a,n)];
         a[max(a,n)]=a[n-1];
         a[n-1]=b;
         RecuiSelectSort(a,n-1);
     }
}     
