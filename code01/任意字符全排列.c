//任意数据全排列问题
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
      {
        int ok=1;
        for(j=0;j<=cur;j++)
          if(A[i]==a[j])
             ok=0;
        if(ok==1)
         {
             a[cur]=A[i];
             PAI(A,a,n,cur+1);
         }
      }
}
