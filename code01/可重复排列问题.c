//可重复排列问题
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
       if(i==0||A[i]!=A[i-1])       //对事先排列过的数组，
         {
          int c1=0,c2=0;
          for(j=0;j<=cur-1;j++)
             if(A[i]==a[j])
                c1++;                    //某元素已经排列的次数
          for(j=0;j<=n-1;j++)
             if(A[i]==A[j])
                c2++;                   //某元素重复的总次数
         if(c1<c2)
          {
             a[cur]=A[i];
             PAI(A,a,n,cur+1);
          }
        }
}
