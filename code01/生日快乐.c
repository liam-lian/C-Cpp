#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("小怪，HAPPY BIRTHDAY");
    int i;
    char m;
    printf("\n\n为你带来美丽的流星雨\n\n准备好了吗？准备好了就轻敲回车\n");
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
printf("20个美丽的菱形，为你带来20岁生日的问候。\n\nＨＡＰＰＹ　ＢＩＲＴＨＤＡＹ　tO 小乖乖\n");
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
printf("\nＨＡＰＰＹ　　ＢＩＲＴＨＤＡＹ　　小怪　！\n\a");

}
printf("\n我不是长腿偶吧，但我用心为你写下每一行代码\n\n");
printf("\n\t\t\t\t\t\tcode printed by Zhuangzhuang.%c\n",1);
printf("\n\t\t\t\t\t\t/*记得放大看哦*/\n");
    system("pause");
    return 0;
}
