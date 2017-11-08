#include <stdio.h>
#include <stdlib.h>
int conver(int n)
{
    if(n==1)
    return(1);
    else
    return n%10+conver(n/10)*2;
} 
int main(int argc, char *argv[])
{
    int n;
    printf("Please input an integer:");
    scanf("%d",&n);
    printf("The result is:%d\n",conver(n));
  
  system("PAUSE");	
  return 0;
}
