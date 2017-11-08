#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[100];
    int i=0,b[10]={0};
    while((a[i]=getchar())!='-')
     {
         if(a[i]>='0'&&a[i]<='9')
           b[a[i]-'0']++;
         i++;
     }
    for(i=0;i<=9;i++)
      if(b[i])
        printf("%d %d\n",i,b[i]);
    return 0;
}
