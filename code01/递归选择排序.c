#include <stdio.h>
#include <stdlib.h>
int max(int a[],int n);//��1--n�����ֵ 
void Printfarray(int a[],int n);//��ӡ����������Իس����ǿո����
void RecuiSelectSort(int a[],int n);//�ݹ飬ѡ�����򣬽�0--n�����ֵ�������ʵ������ 
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
int max(int a[],int n)//��1--n�����ֵ 
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
void Printfarray(int a[],int n)//��ӡ����������Իس����ǿո���� 
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
void RecuiSelectSort(int a[],int n)//�ݹ飬ѡ�����򣬽�0--n�����ֵ�������ʵ������ 
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
