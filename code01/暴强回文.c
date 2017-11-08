#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[1000],b[1000];
    int n,i,j,m=0,p[1000];
    gets(a);
    n=strlen(a);
    for(i=0;i<n;i++)
      if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
      {
          p[m]=i;
          if(a[i]>='a'&&a[i]<='z')
              b[m]=a[i]-32;
          else
              b[m]=a[i];
          m++;
      }
     int max=0,k,ok,x,y;
     for(i=0;i<m;i++)
       for(j=i;j<m;j++)
         {
          ok=1;
          for(k=i;k<=j;k++)
            {
             if(b[k]!=b[j+i-k])
               ok=0;
           }
         if(ok&&j-i+1>max)
           {
             max=j-i+1;
             x=i;
             y=j;
           }
         }
    printf("%d\n",max);
    for(i=p[x];i<=p[y];i++)
       printf("%c",a[i]);
   system("pause");
    return 0;
}
