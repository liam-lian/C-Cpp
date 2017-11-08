#include <stdio.h>
#include <stdlib.h>
int DIGUI(int*,int,int);
int main()
{
    int a[100],n,x,i;
    scanf("%d %d",&n,&x);
    for(i=0;i<=n;i++)
      scanf("%d",&a[i]);
    printf("%d",DIGUI(a,n,x));
    system("pause");
    return 0;
}
int DIGUI(int* a,int n,int x)
{
    if(n==0)
      return a[0];
   else
      return a[n]+x*DIGUI(a,n-1,x);
}
