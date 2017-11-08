#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main(int argc, char *argv[])
{   
    int a,r,p=1;
    srand((unsigned)time(NULL)); 
    r=(rand()%1000)+1;
    printf("这是一个猜数游戏\n我有一个1--1000的数\n你能猜出是多少吗？\n请输入你的第一次尝试\n");
    scanf("%d",&a);
    while(a!=r)
     {
       if(a<r)
        { 
           printf("你的数太小啦，再试一次吧！\n请输入你的下一次尝试：\n");
          scanf("%d",&a);
        }
      else
        { 
            printf("你的数太大啦，再试一次吧！\n请输入你的下一次尝试：\n");
            scanf("%d",&a);
        }
      p++;
    } 
  printf("厉害！你猜对了！答案就是%d,\n共猜了%d次\n",a,p); 
  system("PAUSE");	
  return 0;
}
2
