//��������N���㣬�����������ߵõ�n(n-1)���߶Σ������߶ε��ܳ���
//�����ʽ InputFormat
//��һ�У�һ������N����ʾ������
//������N�У�ÿ��һ������X_i����ʾ������ꡣ
//�����ʽ OutputFormat
//һ����������ʾ�߶ε��ܳ���
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
   return  (n-1)*(a[n-1]-*a)+S(a+1,n-2);//n����ǡ�ÿ��Կ���n���������Сֵ֮������м�ģ��ݹ飩 
}   
        
