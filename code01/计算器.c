#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{ 
    int n,a[1000]={0},i,b,c;
    char d;
    float f[1000]={0};
    scanf("%d",&n);
    fflush(stdin);
    for(i=1;i<=n;i++)
      {
       scanf("%c %d %d",&d,&b,&c);
       fflush(stdin);
       if(d=='+')
          a[i]=b+c;       
       if(d=='-')
          a[i]=b-c;
       if(d=='/')
          f[i]=(float)b/c;
       if(d=='*')
          a[i]=b*c;
         }      
    for(i=1;i<=n;i++)
        {
         if(f[i]!=0)
            printf("%.2f\n",f[i]);
         else
            printf("%d\n",a[i]);
         }       
  system("PAUSE");	
  return 0;
}
