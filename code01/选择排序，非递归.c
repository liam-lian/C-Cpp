//—°‘Ò≈≈–Ú£¨∑«µ›πÈ 
#include <stdio.h>
#include <stdlib.h>
int max(int a[],int n);
void selectsort(int a[],int n);
int main(int argc, char *argv[])
{
    int a[1000],n,i,j;
    printf("Please input the number of intergers:");
    scanf("%d",&n);
    printf("Please input the integers:");
    for(i=0;i<=n-1;i++)
      scanf("%d",&a[i]);
    selectsort(a,n);
    printf("The result is:"); 
    for(i=0;i<=n-1;i++)
       {
        j++;
        if(j!=n)                
        printf("%d ",a[i]);
        if(j==n)                
        printf("%d",a[i]);
        }
     printf("\n");     
    system("PAUSE");	
    return 0;
}
int max(int a[],int n)
{
    int max=0,i=0,c=0;
    for(i=0;i<=n-1;i++)
        if(max<=a[i])
        {
           max=a[i]; 
           c=i;
        }   
    return c;       
}    
void selectsort(int a[],int n)
{  
    int k,i;
    for(i=n;i>=1;i--)
       {
       k=a[max(a,i)];
       a[max(a,i)]=a[i-1];
       a[i-1]=k;
       } 
}               
