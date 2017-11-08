//数字全排列问题
#include <stdio.h>
#include <stdlib.h>
void PAI(int *a,int n,int cur);
int main()
{
    int n,a[100];
    scanf("%d",&n);
    PAI(a,n,0);
    system("pause");
        return 0;
}
void PAI(int *a,int n,int cur)
{
    int i,j;
    if(cur==n)
    {
    for(i=0;i<n;i++)
       printf("%d ",a[i]);
    printf("\n");
    }
    for(i=1;i<=n;i++)
      {
        int ok=1;
        for(j=0;j<=cur;j++)
          if(i==a[j])
             ok=0;
        if(ok==1)
         {
             a[cur]=i;
             PAI(a,n,cur+1);
         }
      }
}
