//字符串的最小循环周期 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[100];
    int i=1,j,n,ok;
    gets(a);
    n=strlen(a);
    for(i=1;i<=n;i++)
      {
       for(j=i;j<n;j++)
        {
         ok=1;
         if(a[j]!=a[j%i])
           ok=0;
        }
       if(ok==1)
           {
            printf("%d",i);
            break;
           }
      }
     system("pause"); 
    return 0;
}
