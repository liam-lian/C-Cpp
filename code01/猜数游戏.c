#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main(int argc, char *argv[])
{   
    int a,r,p=1;
    srand((unsigned)time(NULL)); 
    r=(rand()%1000)+1;
    printf("����һ��������Ϸ\n����һ��1--1000����\n���ܲ³��Ƕ�����\n��������ĵ�һ�γ���\n");
    scanf("%d",&a);
    while(a!=r)
     {
       if(a<r)
        { 
           printf("�����̫С��������һ�ΰɣ�\n�����������һ�γ��ԣ�\n");
          scanf("%d",&a);
        }
      else
        { 
            printf("�����̫����������һ�ΰɣ�\n�����������һ�γ��ԣ�\n");
            scanf("%d",&a);
        }
      p++;
    } 
  printf("��������¶��ˣ��𰸾���%d,\n������%d��\n",a,p); 
  system("PAUSE");	
  return 0;
}
2
