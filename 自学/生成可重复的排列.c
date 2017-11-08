#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
char p[100];
void PAiLie(char*,int,int);
void Paixu(int n);
main()
{
    int n,i;
    scanf("%d",&n);
    char a[100];
    for(i=0;i<n;i++) scanf("%s",&p[i]);
    Paixu(n);
    PAiLie(a,n,0);
    return 0;
}
void PAiLie(char *a,int n,int cur)
{
    int i,j;
    if(n==cur){
     for(i=0;i<n;i++)
       printf("%c ",a[i]);
      printf("\n");
      Sleep(1000);
    }
    else for(i=0;i<n;i++)
         {
            int c1=0,c2=0;
            for(j=0;j<n;j++)  if(p[j]==p[i]) c1++;  //表示原排列中p【i】出现的次数
            for(j=0;j<cur;j++) if(a[j]==p[i]) c2++;//表示递归排列中p[i]出现的次数
            if(c2<c1){
              a[cur]=p[i];
              PAiLie(a,n,cur+1);
             }
         }
}
void Paixu(int n)
{
    int i,j;
    for(i=0;i<n;i++)
      for(j=i;j<n;j++)
         if(p[i]>p[j])
         {
             char t=p[i];
             p[i]=p[j];
             p[j]=t;
         }
}
