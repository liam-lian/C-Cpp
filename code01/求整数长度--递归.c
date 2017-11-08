#include <stdio.h>
#include <stdlib.h>
int leng(int n)
{
    if(n/10==0)
    return 1;
    else
    return leng(n/10)+1;
} 
int main(int argc, char *argv[])
{
    int n; 
    scanf("%d",&n);
    printf("%d",leng(n));
  
  system("PAUSE");	
  return 0;
}
