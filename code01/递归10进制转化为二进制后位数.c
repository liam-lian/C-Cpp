#include <stdio.h>
#include <stdlib.h>
int countBinary(int n)
{
     if(n==1)
     return 1;
     else
     return countBinary(n/2)+1;
}     
int main(int argc, char *argv[])
{
    int n;
    printf("Input an integer:");
    scanf("%d",&n);
    printf("The binary form of number %d has %d digits.",n,countBinary(n));
    system("PAUSE"); 
    return 0;
}
