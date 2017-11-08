#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)==2){
        if(!a&&!b) break;
        int ans=0,now=0;
        while(a||b)
        {
           now=(a%10+b%10+now)>9?1:0;
           ans+=now;
           a/=10;b/=10;
        }
        printf("%d\n",ans);
     }
    return 0;
}
