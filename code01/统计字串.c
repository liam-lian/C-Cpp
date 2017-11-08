//找出a串中b串出现的次数 
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
   char a[100],b[100],j;
   gets(a);
   gets(b);
   int alen=strlen(a),blen=strlen(b),i,ok=1,sum=0;
   for(i=0;i<=alen-blen;i++)
      {
        for(j=0;j<=blen-1;j++)
          {
           if(a[i+j]!=b[j])
           ok=0;
          }
        if(ok==1)
          sum++;
         ok=1;
      }
      printf("%d",sum) ;  
  system("PAUSE");	
  return 0;
}
