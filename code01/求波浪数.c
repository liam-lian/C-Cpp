/*����������ż��ֱ���ȣ������߲���*/
#include <stdio.h>
#include <stdlib.h>      
int leng(int n);/*�ݹ����n�ĳ���*/
int isWaveNum(int n); 
int main(int argc, char *argv[])
{
    int n;
    scanf("%d",&n);
    switch(isWaveNum(n))
    {
      case 1:printf("YES\n");break;
      case 0:printf("NO\n");
    }                    
  system("PAUSE");	
  return 0;
}
int isWaveNum(int n)
{   
    int i,a,b,c,isok=1;
    a=n%10;
    n/=10;
    b=n%10;
    n/=10;
    if(a==b&&b!=0)//��֤��ǰ��λ����ȣ�ͬʱ�ų�ֻ��1λ������� 
      isok=0;
    for(i=1;isok==1&&n!=0;i++)//�ѱ�֤����λ���ȣ�����������ֻҪ������ȼ��� 
        {
        c=n%10;
        n/=10;
        if((i%2==1&&c!=a)||(i%2==0&&c!=b))
          isok=0;
        }
    return isok;    
}
int leng(int n)/*�ݹ����n�ĳ���*/
{
    if(n/10==0)
    return 1;
    else
    return leng(n/10)+1;
}     
