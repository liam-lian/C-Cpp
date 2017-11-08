#include<stdio.h>
//#define DEBUG //定义宏
main()
{
   int age;
   char name[20];

   printf("input your age\n");
   scanf("%d",&age);
   printf("input your name\n");
   scanf("%s",name);
   #ifdef DEBUG
      printf("input age is:%d\n",age);
   #endif

   #undef DEBUG  //取消宏定义

   #ifdef DEBUG
      printf(“input name is:%s\n”,name); //将不被编译
   #endif
   system("pause");
   return 0;
}

