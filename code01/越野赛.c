#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a,b,c,d,e,i;
   char p[100000],sum=0,m=0;
   scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
   getchar();
   for(i=0;i<=b-1;i++)
    {
      scanf("%c",&p[i]);
      getchar();
    }
   for(i=0;i<=b-1;i++)
    {
      if(p[i]=='u'||p[i]=='d')
     {
         sum+=(d+i);
         m++;
     }
      if(p[i]=='f')
      {
         sum+=2*e;
         m++;
      }
      if(sum>a)
       {
         m--;      
         break;
       }
    }
   printf("%d",m);
   system("pause");
   return 0;

}
