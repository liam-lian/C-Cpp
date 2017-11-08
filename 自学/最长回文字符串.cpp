#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string.h>
#define MAX 1000
using namespace std;
int p(char*m,int p,int q)
{
	for(int i=p;i<=(p+q)/2;i++)
	  if(m[i]!=m[q-i+p]) return 0;
	return 1;
}
int main(int argc, char *argv[])
{
	char a[MAX],b[MAX];
	int c[MAX];
	gets(a);
	for(int i=0;i<strlen(a);i++)
	 {
	 	static int j=0;
	 	if((a[i]>='0'&&a[i]<='9')||(a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
	 	   if((a[i]>='A'&&a[i]<='Z')) b[j]=a[i]+32;
	 	   else  b[j]=a[i];
	 	   c[j]=i;
	 	   j++;
	 	  }
	 	 b[j]='\0';
	 }
	 int x=0,y=1;
	 for(int i=x;i<strlen(b);i++)
	    for(int j=i+y-x;j<strlen(b);j++)
	      if(p(b,i,j)) {
	      	x=i;
	      	y=j;
	      }
	for(int i=c[x];i<=c[y];i++)
	   cout<<a[i];
	cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
