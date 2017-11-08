#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,j,k;
    char a[100][10000],b[11];
    gets(b);
    for(i=1;b[3]!='O';i++)
    {
          if(i%3==1)
              gets(a[i/3]);
          else
              gets(b);
    }
    for(j=0;j<=i/3-1;j++)
      {
        for(k=0;a[j][k];k++)
           {
             if(a[j][k]>='F'&&a[j][k]<='Z')
                 a[j][k]-=5;
             else  if(a[j][k]>='A' &&a[j][k]<='E')
                 a[j][k] +=21;
           }
       puts(a[j]);
      }
      system("pause");
      return 0;
}
