#include <stdio.h>
#include <stdlib.h>
int isprimm(int n)
{
    int i=2,prim=1;
    for(i;i<n&&prim==1;i++)
       if(n%i==0)
          prim=0;
     return prim;
}
int main(int argc, char *argv[]) 
{
	int n,i;
	scanf("%d",&n);
	for(i=2;i<n/2;i++)
	 {
	 	if(isprimm(i)&&isprimm(n-i))
	 	  printf("%d=%d+%d\n",n,i,n-i);
	 }
	return 0;
}
