//数轴上有N个点，任意两点连线得到n(n-1)条线段，试求线段的总长。
//输入格式 InputFormat
//第一行，一个整数N，表示点数。
//接下来N行，每行一个整数X_i，表示点的坐标。
//输出格式 OutputFormat
//一个整数，表示线段的总长。
#include <stdio.h>
#include <stdlib.h>
long long int S(int *a,int n);
int main(int argc, char *argv[])
{
  long int n,a[10000],i,j,temp;
  scanf("%d",&n);
  for(i=0;i<=n-1;i++)
    scanf("%d",&a[i]);
  for(i=0;i<=n-1;i++)
    for(j=0;j<n-1;j++)
      if(a[j]>a[j+1])  
      {
       temp=a[j+1];
       a[j+1]=a[j];
       a[j]=temp;
       } 
    printf("%lld",2*S(a,n));                     
  system("PAUSE");	
  return 0;
}
long long int S(int *a,int n)
{
  if(n==2)
    return *(a+1)-*(a);
  if(n==3)
    return  2*(a[n-1]-*a);
  else
   return  (n-1)*(a[n-1]-*a)+S(a+1,n-2);//n个点恰好可以看做n乘以最大最小值之差，加上中间的（递归） 
}   
        
