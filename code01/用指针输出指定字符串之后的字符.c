//用指针输出指定字符串之后的字符 
#include <stdio.h>
#include <stdlib.h>
char *locatesubstr(const char *p1,char *p2);
int main(int argc, char *argv[])
{
    char a[500],b[500];
    char *p,*p1,*p2;
    printf ("Please input one string:");
       gets(a);
    printf ("Please input anoter string:");
       gets(b);
    p1=a;
    p2=b;   
    p=locatesubstr(p1,p2);
    if(p!=NULL)
        puts(p);
    else
        printf ("NULL!");
    printf ("\n");
    system("PAUSE");	
    return 0;
}
char *locatesubstr(const char *p1,char *p2)
{
     int i,j,isok=1;
     for(i=0;*(p1+i);i++)
       {  
         for(j=0;*(p2+j);j++)
            if(*(p1+i+j)!=*(p2+j))
                {
                isok=0;
                break;
                }
         if(isok==1)
               return p1+i;
         isok=1;      
        }  
     return NULL;                
}                
