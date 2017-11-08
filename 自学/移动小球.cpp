#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string.h>
#define MAX 50000+10
using namespace std;
int main(int argc, char *argv[])
{
    int left[MAX],right[MAX],m,n,p,q;//m¸öÇò£¬nÌõÖ¸Áî
	char requ; 
	cin>>n>>m; 
	right[0]=1;  
	for(int i=1;i<=m;i++)
	 {
	 	left[i]=i-1;
	 	right[i]=i+1;
	 }
	for(int i=1;i<=n;i++)
	{
		cin>>requ>>p>>q;
     	int aa=left[p];
		right[left[p]]=right[p];
		left[right[p]]=aa;
		if(requ=='A')
		{
			right[left[q]]=p;
			left[p]=left[q];
			right[p]=q;
			left[q]=p;
		}
		if(requ=='B')
        {
        	left[right[q]]=p;
        	right[p]=right[q];
        	left[p]=q;
        	right[q]=p;
        }
	} 
	for(int p=0,i=0;i<m;i++)
	{
		p=right[p];
		cout<<p<<" ";
	}
	cout<<endl; 
    system("PAUSE");
    return EXIT_SUCCESS;
}

