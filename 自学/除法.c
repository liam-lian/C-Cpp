#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
main()
{
	int a[5],sum,n,p[5],i,j;
	scanf("%d",&n);
	for(a[0]=0;a[0]<=9;a[0]++)
	  for(a[1]=0;a[1]<=9;a[1]++)
	    for(a[2]=0;a[2]<=9;a[2]++)
	      for(a[3]=0;a[3]<=9;a[3]++)
	        for(a[4]=0;a[4]<=9;a[4]++)
	          {
	              int ok=1;
	              for(i=0;i<5;i++)
                   for(j=0;j<5;j++)
                     if(i!=j&&a[i]==a[j])
                       ok=0;
                  if(ok)
	                 sum=n*(10000*a[0]+1000*a[1]+100*a[2]+10*a[3]+a[4]);
	              if(sum>=100000) ok=0;
                  for(i=4;i>=0;i--)
                  {
                   p[i]=sum%10;
                   sum/=10;
                  }
                  for(i=0;i<5;i++)
                   for(j=0;j<5;j++)
                     if(i!=j&&p[i]==p[j])
                       ok=0;
                  for(i=0;i<5;i++)
                   for(j=0;j<5;j++)
                     if(a[i]==p[j])
                        ok=0;
                  if(ok)
                  {
                  for(i=0;i<5;i++)
                    printf("%d",p[i]);
                  printf("/");
                  for(i=0;i<5;i++)
                    printf("%d",a[i]);
                  printf("=%d\n",n);
               }
	          }
    return 0;
}
