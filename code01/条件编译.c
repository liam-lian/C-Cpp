#include<stdio.h>
//#define DEBUG //�����
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

   #undef DEBUG  //ȡ���궨��

   #ifdef DEBUG
      printf(��input name is:%s\n��,name); //����������
   #endif
   system("pause");
   return 0;
}

