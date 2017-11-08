#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
void print_subset(int *a,int n,int cur)
{
    int i;
    for(i=0;i<cur;i++) printf("%d",a[i]);
    printf("\n");
    //Sleep(1000);
    int s=cur?a[cur-1]+1:0;
    for(i=s;i<n;i++)
    {
        a[cur]=i;
        print_subset(a,n,cur+1);
    }
}
main()
{
    int a[10];
    print_subset(a,5,0);
}
