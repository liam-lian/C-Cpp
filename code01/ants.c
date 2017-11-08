#include <stdio.h>
#include <stdlib.h>
int max(imt a,int b)
{
    return a>b?a:b;
}
int min(imt a,int b)
{
    return a<b?a:b;
}

int main()
{
    int n,i,j,l,p,a[1000000];
    scanf("%d",&p);
    for(i=1;i<=p;i++)
     {
       int maxT=0,minT=0;
       scanf("%d %d",&l,&n);
       for(j=0;j<=n-1;j++)
         scanf("%d",a[j]);
       for(j=0;j<=n-1;j++)
       {
         minT=max(minT,min(l,l-a[j]));
         maxT=max(max,max(l,l-a[j]));
       }
       printf("%d %d\n",minT,maxT);
     }
    system("pause"); 
    return 0;
}
