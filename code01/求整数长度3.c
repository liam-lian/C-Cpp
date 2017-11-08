#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i=0,c;
  printf("please input a number");
  while((c=getchar())!='\n')
  i++;
  printf("%d",i);
  system("PAUSE");	
  return 0;
}
