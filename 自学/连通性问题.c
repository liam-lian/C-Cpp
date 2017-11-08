#include <stdio.h>
#include <stdlib.h>
//连通性问题。1-2,2-3可推出1-3
int main()
{
    int a[1000],i,t,j,p,q,ok=1;
    for(i=0;i<=999;i++) a[i]=i;
    scanf("%d",&p);
        if(p!=-1)
          scanf("-%d",&q);
    while(p!=-1)
     {
         if(a[p]==a[q]) continue;
         for(i=0;i<=999;i++)
           if(a[i]==a[p]) a[i]=a[q];
        scanf("%d",&p);
        if(p!=-1)
          scanf("-%d",&q);

     }
    for(i=0;i<=999;i++)
    {
     if(a[i])
      {
        t=a[i];
        for(j=i;j<=999;j++)
         {
            if(t==a[j]&&i!=j)
              {
                if(ok==1)
                 {
                    printf("%d-%d",i,j);
                    a[i]=0;a[j]=0;
                    ok=0;
                 }
                 else
                 {
                    printf("-%d",j);
                    a[j]=0;
                 }
               }
         }
      }
       if(ok==0){printf("\n");ok=1;}
    }
    return 0;
}
