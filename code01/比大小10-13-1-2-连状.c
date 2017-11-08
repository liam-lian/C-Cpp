#include <stdio.h>
#include <stdlib.h>

 main(int argc, char *argv[])
{
    int a,b,Max,Min;
    printf("please input two integers style(5 10)\n");
scanf("%d%d",&a,&b);
         if(a==b)
printf("the two number are equal\n");
else 
if(a>b)
{Max=a;
Min=b;
printf("the larger number is:%d the smaller number is:%d\n",Max,Min);
}
else
{
Max=b;
Min=a;
printf("the larger number is:%d the smaller number is:%d\n",Max,Min);
}

  system("PAUSE");	
  return 0;
}
