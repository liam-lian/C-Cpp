#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("С�֣�HAPPY BIRTHDAY");
    int i;
    char m;
    printf("\n\nΪ�����������������\n\n׼��������׼�����˾����ûس�\n");
    scanf("%c",&m);
    if(m=='\n')
    {
    int n=40,line,p;
for(p=1;p<=20;p++)
{
  line=1;
  for(;line<=n;line++)
  {
    for(i=1;i<=2*n-1;i++)
      {
      if((i==n-line+1)||(i==n+line-1))
      printf("*");
      else
      printf(" ");
      }
      printf("\n");
      }
      line=n+1;
        for(;line<=2*n-1;line++)
  {
    for(i=1;i<=2*n-1;i++)
      {
      if((i==line-n+1)||(i==3*n-line-1))
      printf("*");
      else
      printf(" ");
      }
      printf("\n");
      }
      printf("\a");
}
printf("20�����������Σ�Ϊ�����20�����յ��ʺ�\n\n�ȣ��УУ١��£ɣңԣȣģ��١�tO С�Թ�\n");
for(i=1;i<=5;i++)
{
  for(p=1;p<=i;p++)
     printf("%c ",i);
  printf("\n");
}
for(i=15;i<=30;i++)
{
  for(p=1;p<=i-9;p++)
     printf("%c ",i);
  printf("\n");
}
for(i=0;i<=25;i++)
printf("\n�ȣ��УУ١����£ɣңԣȣģ��١���С�֡���\n\a");

}
printf("\n�Ҳ��ǳ���ż�ɣ���������Ϊ��д��ÿһ�д���\n\n");
printf("\n\t\t\t\t\t\tcode printed by Zhuangzhuang.%c\n",1);
printf("\n\t\t\t\t\t\t/*�ǵ÷Ŵ�Ŷ*/\n");
    system("pause");
    return 0;
}
