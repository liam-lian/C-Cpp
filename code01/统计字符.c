#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int English=0,spaces=0,numbers=0,other=0,c;
  printf("please input a string:");
  while((c=getchar())!='\n')
  {
if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
English++;
else if(c==' ')
spaces++;
 else if(c>='0'&&c<='9')
 numbers++ ;
else 
other++;
}
printf("The number of English characters,spaces,numbers,other characters are:%d,%d,%d,%d",English,spaces,numbers,other);
  system("PAUSE");	
  return 0;
}
