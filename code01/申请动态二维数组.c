//申请动态二维数组 
#include <stdio.h>
#include <stdlib.h>
int **Create2(int m,int n); 
int main(int argc, char *argv[])
{
    int m,n,i,j,**a;
    printf("Please input m,n:");
    scanf("%d %d",&m,&n);
    a=Create2(m,n); 
    printf("Please input %d integers:\n",m*n); 
    for(i=0;i<=m-1;i++)
       {
       for(j=0;j<=n-1;j++)
          {
           scanf("%d",&a[i][j]);
           printf("%d ",-10*a[i][j]);
           }
       printf("\n");
       }   
     free(a);
     a=NULL;  
  system("PAUSE");	
  return 0;
}
int **Create2(int m,int n) 
{
     int **a; 
     int i;
     a=malloc(m*sizeof(int*)); 
     for(i=0;i<m;i++) 
        a[i]=malloc(n*sizeof(int)); 
     return a;
} 
