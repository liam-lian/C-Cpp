//±ê×¼Ã°ÅÝ
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[100],n,i,j,b;
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++)
       for(j=0;j<=n-1-i;j++)
             if(a[j]>a[j+1])
               {
                   b=a[j];
                   a[j]=a[j+1];
                   a[j+1]=b;
               }
    for(i=0;i<=n-1;i++)
        printf("%d ",a[i]);
    system("pause");
    return 0;
}
