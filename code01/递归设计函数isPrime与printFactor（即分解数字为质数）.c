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
    int i,m=1; 
    if(isPrime(n)) 
      printf("%d\n",n);
    else 
      for(i=2;i<=n/2&&m==1;i++)
       { 
         if(isPrime(i)&&(n%i==0))
          {
            printf("%d*",i);
            printFactor(n/i); 
             m=0; 
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
        printf("%d=",i);                    
        printFactor(i); 
       } 
  system("PAUSE");	
  return 0;
}
