#include <stdio.h>
#include <stdlib.h>
int pow(int n)/*����10��n�η�*/ 
{
    int sum=1,i;
    for(i=1;i<=n;i++)
       sum=sum*10;
    return sum;
}           
int leng(int n)/*�ݹ����n�ĳ���*/
{
    if(n/10==0)
    return 1;
    else
    return leng(n/10)+1;
} 
int daoxu(int n)/*���嵹����*/ 
{    
    if(leng(n)==1)
    return n;
    else
    return daoxu(n/10)+(n%10)*pow(leng(n)-1);//�����һλ�ᵽ��һλ 
}    
int main(int argc, char *argv[])
{
    int n; 
    printf("���������֣�"); 
    scanf("%d",&n);
    printf("�����Ϊ:%d\n",daoxu(n));
    system("PAUSE");	
    return 0;
}
