#include <stdio.h>
#include <stdlib.h>
void Shanchu(char*,char);
void Move(char*,int);
int main()
{
    char a[100],p;
    printf("�����ַ�����");
    gets(a);
    printf("����Ҫɾ�����ַ�:");
    scanf("%c",&p);
    Shanchu(a,p);
    puts(a);
    system("pause");
    return 0;

}
void Shanchu(char* a,char p)
{
    int i;
    for(i=0;a[i];i++)
        if(a[i]==p)
          {
           Move(a,i);
           i--;//ɾ���ַ�ǰ�ƺ�Ҳ����ΪҪɾ�����ַ�
          }
}
void Move(char* a,int i)
{
    int j;
    for(j=i;a[j+1];j++)
      a[j]=a[j+1];
    a[j]='\0';
}
