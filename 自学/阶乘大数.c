#include <stdio.h>
#include <stdlib.h>
# define MAX 30000
int main()
{
    int f[MAX],n,i,j;
    //for(i=0;i<MAX;i++) f[i]=0;
    memset(f,0,sizeof(f));//³õÊ¼»¯ 
    scanf("%d",&n);
    f[0]=1;
    for(i=2;i<=n;i++){
      int e=0;
      for(j=0;j<MAX;j++)
      {
          int c=i*f[j]+e;
          f[j]=c%10;
          e=c/10;
      }
    }
    for(j=MAX-1;;j--) if(f[j]) break;
    for(;j>=0;j--)
    printf("%d",f[j]);
    return 0;
}
