#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
void print_subset(int *a,int n,int cur)
{
    int i;
    if(n==cur){
      for(i=0;i<n;i++)
        if(a[i]) printf("%d ",i+1);
      printf("\n");
      return ;
    }
    a[cur]=0;
    print_subset(a,n,cur+1);
    a[cur]=1;
    print_subset(a,n,cur+1);
}
main()
{
    int a[10];
    print_subset(a,3,0);
}
