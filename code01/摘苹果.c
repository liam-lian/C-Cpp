#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10],i,p,sum=0;
    for(i=1;i<=10;i++)
    scanf("%d",&a[i]);
    scanf("%d",&p);
    for(i=1;i<=10;i++)
    {
        if(p+30>=a[i]);
        sum++;
    }
    printf("%d",sum);
        return 0;
}
