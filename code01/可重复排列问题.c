//���ظ���������
#include <stdio.h>
#include <stdlib.h>
void PAI(char *A,char *a,int n,int cur);
int main()
{
    int n,i;
    char A[100],a[100];
    scanf("%d",&n);
    getchar();
    for(i=0;i<=n-1;i++)
       scanf("%c",&A[i]);
    PAI(A,a,n,0);
        return 0;
}
void PAI(char *A,char *a,int n,int cur)
{
    int i,j;
    if(cur==n)
    {
    for(i=0;i<n;i++)
       printf("%c ",a[i]);
    printf("\n");
    }
    for(i=0;i<=n-1;i++)
       if(i==0||A[i]!=A[i-1])       //���������й������飬
         {
          int c1=0,c2=0;
          for(j=0;j<=cur-1;j++)
             if(A[i]==a[j])
                c1++;                    //ĳԪ���Ѿ����еĴ���
          for(j=0;j<=n-1;j++)
             if(A[i]==A[j])
                c2++;                   //ĳԪ���ظ����ܴ���
         if(c1<c2)
          {
             a[cur]=A[i];
             PAI(A,a,n,cur+1);
          }
        }
}
