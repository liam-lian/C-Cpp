#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{int a=0,b=1,c,i=1;
for(;i<=40;i++)
{
               c=a+b;
a=b;
b=c;
printf("%10d",c);
if(i%5==0)
printf("\n");
}
  system("PAUSE");	
  return 0;
}
