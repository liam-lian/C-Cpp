#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
void PAiLie(int*,int,int);
main()
{
    int a[100],n;
    scanf("%d",&n);
    PAiLie(a,n,0);
    return 0;
}
void PAiLie(int *a,int n,int cur)
{
    int i,j;
    if(n==cur){
     for(i=0;i<n;i++)
       printf("%d ",a[i]);
      printf("\n");
      Sleep(1000);
    }
    else for(i=1;i<=n;i++)
         {
             int ok=1;
             for(j=0;j<cur&&ok;j++)
               if(a[j]==i) ok=0;
             if(ok){
               a[cur]=i;
          //     int p;
            //     printf("==============\n");
              // for(p=0;p<cur+1;p++)
                // printf("%d ",a[p]);
               //printf("\n==============\n");
               PAiLie(a,n,cur+1);
             }
         }
}
