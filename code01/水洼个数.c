#include <stdio.h>
#include <stdlib.h>
int M,N;
char a[100][100];
void A(int m,int n);
int main()
{
    int i,j,sum=0,p,q;
    scanf("%d %d",&N,&M);
    fflush(stdin);
    for(i=0;i<=N-1;i++)
      for(j=0;j<=M;j++)
        scanf("%c",&a[i][j]);
    for(i=0;i<=N-1;i++)
      for(j=0;j<=M-1;j++)
        if(a[i][j]=='w')
          {
           A(i,j);
           sum++;
        printf("\nsum=%d\n",sum);
        for(p=0;p<=N-1;p++)
        for(q=0;q<=M;q++)
        printf("%c",a[p][q]);
          }
         printf("\n\nsum=%d",sum);
     system("pause");    
    return 0;
}
void A(int m,int n)
{
int p,q;	
  a[m][n]='.';
  int i,j;
  for(i=m-1;i<=m+1;i++)
    for(j=n-1;j<=n+1;j++)
       if(i>=0&&i<=M-1&&j>=0&&j<=N-1&&a[i][j]=='w')
       {
          
      //  for(p=0;p<=N-1;p++)
      //  for(q=0;q<=M;q++)
        //printf("%c",a[p][q]);
       // printf("\n");
        A(i,j);
   }
}
