#include <stdio.h>
#include <stdlib.h>
void filecopy(char* sourse,char* desk);
int main()
{
    filecopy("A.txt","B.txt");
    system("pause");
    return 0;
}
void filecopy(char* sourse,char* desk)
{
    FILE *a,*b;//定义两个指向FILE型的指针，要分别加*，注意 
    char c;
    if((a=fopen(sourse,"r"))==NULL)
       printf("can't open the source file\n");
    else if((b=fopen(desk,"w"))==NULL)
         printf("can't open the dest file\n");
         else
         {
          c=fgetc(a);
          while(!feof(a))
          {      
           fputc(c,b);
           c=fgetc(a);
          } 
           } 
}
