//在字符串的所有数字前加@，小写字符前加#，大写字符前加$，过滤掉其他字符
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void dele(char *,int);
void add(char *,int);
int main()
{
    int i;
    char a[100];
    gets(a);
    for(i=0;a[i];i++)
    {
       if((a[i]>='0'&&a[i]<='9')||(a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
       {
          add(a,i);
          i++;
       }
       else
       {
           dele(a,i);
           i--;
       }

    }
    puts(a);
    return 0;
}
void dele(char* a,int i)
{
     int j;
     for(j=i;j<=strlen(a);j++)
       a[j]=a[j+1];
}
void add(char *a,int i)
{
    int j;
   for(j=strlen(a);j>=i;j--)
      a[j+1]=a[j];
   if(a[i]>='0'&&a[i]<='9')
      a[i]='@';
   if(a[i]>='a'&&a[i]<='z')
      a[i]='#';
   if(a[i]>='A'&&a[i]<='Z')
      a[i]='$';
}
