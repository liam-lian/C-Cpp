//ººÅµËşÎÊÌâ 
#include <stdio.h>
#include <stdlib.h>
int i=0;
void f(int n,int a,int b,int c);
int main()
{
    int n;
    scanf("%d",&n);
    f(n,1,2,3);
    printf("%d",i);
    system("pause");
    return 0;
}
void f(int n,int a,int b,int c)
{
    if(n==1)
       {
       i++;
       printf("%d->%d\n",a,c);
       }
    else
      {
          f(n-1,a,c,b);
          printf("%d->%d\n",a,c);
          i++;
          f(n-1,b,a,c);
      }   
}
