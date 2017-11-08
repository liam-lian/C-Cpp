#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string.h>
#define MAX 50000+10
using namespace std;
int main(int argc, char *argv[])
{
	int M,I,re=1;
	cin>>M>>I;
	for(int i=1;i<=M;i++)
	{
		re=I%2?2*re:2*re+1;
		I=(I+1)/2;
	}
	cout<<re/2;
    system("PAUSE");
    return EXIT_SUCCESS;
}

