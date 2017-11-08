#include <stdio.h>
#include <stdlib.h>
int isPrime(int n)
{
    int i=2,a=1;
    while(i<n&&a==1)
     {
       if(n%i==0)
       {
         a=0;
       }
      i++;  
     }
    return(a);
}
void printFactor(int n)
{
     int i=2;
     printf("%d=",n);
     if(n==1)
     printf("1");
     else
     { 
       for(;n!=1;i++)
       {  
          if(n%i==0&&isPrime(i))
          { 
             n=n/i;
             if(n==1)
             printf("%d",i);
             else
             printf("%d*",i);               
             i=1;//注意，，本层结束后，i回加1，要想从2开始，应输入1 
          }
       }
     }    
}                
int main(int argc, char *argv[])
{
    int a,b,i;
     printf("Please input two integers:"); 
     scanf("%d%*c%d",&a,&b);
     printf("The result is:\n");
     for(i=a;i>=a&&i<=b;i++)
       {
        printFactor(i); 
        printf("\n");
       } 
  system("PAUSE");	
  return 0;
}
