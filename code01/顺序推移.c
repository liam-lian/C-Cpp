#include <stdio.h>
#include <stdlib.h> 
#define SIZE 6
int main(int argc, char *argv[])
{
    int a[SIZE],i,k,p;
    printf("ÇëÊäÈë%d¸öÊı£º",SIZE);
    for(i=0;i<=SIZE-1;i++)
      scanf("%d",&a[i]); 
    for(i=0;i<=SIZE-1;i++)
      {
          k=a[0];
          a[0]=a[SIZE-1];
          for(p=SIZE-1;p>=2;p--)                 
               a[p]=a[p-1]; 
          a[1]=k;       
          for(p=0;p<=SIZE-1;p++)                                  
               printf("%d ",a[p]); 
          printf("\n"); 
       }      
  system("PAUSE");	
  return 0;
}
