//输出完全数，例6=1+2+3 
#include <stdio.h>
#include <stdlib.h>
int isPerfect(int n)//判断是否为完全数 
{
    int i=1,sum=0;
    for(;i<n;i++)
    { 
     if(n%i==0)
      sum+=i;
    }
    if(n==sum)
      return(1);
    else
      return(0);
}
void printPerfect(int n)//完全数输出 
{
     int i=1,p=0,q;
     if(isPerfect(n))
       {
          printf("%d=",n);
            for(;i<n;i++)
              {            
                 if(n%i==0)  
                    {
                      p++;
                      if(p==2)
                        q=i;
                      if(i==(float)n/q)          
                           printf("%d",i);
                      else
                         printf("%d+",i);
                     }
              }             
        }     
}                                     
int main(int argc, char *argv[])
{
    int a,b,i;
    printf("please input a and b:");
    scanf("%d%*c%d",&a,&b); 
    printf("The perfect numbers from %d to %d are:\n",a,b);
    for(;i>=a&&i<=b;i++)
     {  
       printPerfect(i);
       if(isPerfect(i))
         printf("\n");
     }      
  system("PAUSE");	
  return 0;
}
