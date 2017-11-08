#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   int a,b,c,d=0,num,i,sum;
    printf("Input three integers:");
    scanf("%d %d %d",&a,&b,&c );
    printf("The result is:\n");
   for(num=a;num<=b;num++)
   {sum=0;
           for(i=1;i<num;i++)                        
           {
                                                    
                  if(num%i==0)
                    sum=sum+i; 
            }
            if(abs(num-sum)<=c)
            {  
             d++;
             printf("%d       ",num);
             if(d%5==0)
             printf("\n");
             }
                      
   }
   if(d==0)
   printf("There is no proper number in the interval");
  system("PAUSE"); 
  return 0;
}
