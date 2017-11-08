#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int JZZH(int* a,int n,int b)//进制转化后存入数组
{
	int i;
	for(i=0;n;i++)
	{
		a[i]=n%b;
		n/=b;
	}
	return i;//i就指该数字实际的位数
}
int OK(int *a,int num)//判断是否为回文数组
{
	int i;
	for(i=0;i<num/2;i++)
	  if(a[i]!=a[num-i-1])
	    return 0;
	return 1;
}
main()
{
	int n,res,i,p=0,a[50]={0};
	scanf("%d",&n);
	for(res=n;;res++)
	{
		p=0;
		for(i=2;i<=10;i++)
		{
		  if(OK(a,JZZH(a,res,i)))
		    	p++;
            }
		if(p>=2)
		{
		  printf("%d\n",res);
		  break;
	    }
	}
    return 0;
}
