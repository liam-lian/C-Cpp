//É¸Ñ¡ËØÊı 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a[999]={0},p=2,i,b=0;
    for(p=2;p*p<=999;p++)
       for(i=2;i<=998;i++)
           if(i%p==0&&i!=p)
              a[i]=1;
    printf("The prime numbers between 1 and 999 are:\n");          
    for(i=2;i<=998;i++)
       {
       if(a[i]==0)
         {      
           printf("%d ",i);
           b++;
           if(b%5==0)
             printf("\n");
          }
       } 
    printf("\n");           
  system("PAUSE");	
  return 0;
}
