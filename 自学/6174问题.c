#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GetNext(int);
int main()
{
    int i,j,a[100];
    int found=0;
    scanf("%d",&a[0]);
    printf("%d",a[0]);
    for(i=0;!found;i++)
    {
        a[i+1]=GetNext(a[i]);
        for(j=0;!found&&j<=i;j++){
        if(a[i]==a[i+1])
        found=1;
        }
        printf("->%d",a[i+1]);
        //if(found) break;
    }
    return 0;
}
int GetNext(int num)
{
    char s[100],t;
    int i,j,a,b;
    sprintf(s,"%d",num);
    int n=strlen(s);
    for(i=0;i<n;i++)
      for(j=i+1;j<n;j++)
        if(s[i]>s[j]){ t=s[i];s[i]=s[j];s[j]=t;  }
    sscanf(s,"%d",&a);
    for(i=0;i<n/2;i++)
    {
        t=s[i];s[i]=s[n-i-1];s[n-i-1]=t;
    }
    sscanf(s,"%d",&b);
    return b-a;
}
