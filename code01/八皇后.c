//�˻ʺ�����
#include <stdio.h>
#include <stdlib.h>
#define N_ 8
void eightqueue(int);
int sum=0,c[N_]={0};//sum��ʾ�ݹ��ܴ���������ÿ����ԣ�
int main()           //c[N_]�洢��i�У��ʺ��λ�ã�������������ÿ�н���һ���ʺ󣬿��Խ������Դ洢��
{                     // ������i�лʺ��ڶ�ά����a[i][c[i]]λ��
    eightqueue(0);
    system("pause");
    return 0;
}
void eightqueue(int cur)
{
    int i,j;
    if(cur==N_)
    {
       sum++;
       int a[N_][N_]={0};
       for(i=0;i<=N_-1;i++)
         a[i][c[i]]=1;
       printf("case %d:\n",sum);
       for(i=0;i<=N_-1;i++)
       {
          for(j=0;j<=N_-1;j++)
             printf("%d",a[i][j]);
          printf("\n");
       }
    }
   else for(i=0;i<N_;i++)
      {
          c[cur]=i;
          int ok=1;
          for(j=0;j<cur;j++)
             if(c[j]==c[cur]||cur-j==c[cur]-c[j]||cur-j==c[j]-c[cur])
          {
             ok=0;break;
          }
          if(ok)
                eightqueue(cur+1);
      }
}
