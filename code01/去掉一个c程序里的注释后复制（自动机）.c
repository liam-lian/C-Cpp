//ȥ��һ��c�������ע��
#include <stdio.h>
#include <stdlib.h>
enum states{normal,state1,state2,state3};
//ö������ normal�������������״̬ state1������//�����ע�͵�״̬
//state2������/*�����ע�͵�״̬  state3������printf�����е�״̬
void filecopy(char* Sourse,char* Desk);//�������ڴ���ע�Ͳ��Ҹ��Ƶ�Deskָ����ļ���
int main()
{
    filecopy("text1.c","text2.c");
    return 0;
}
void filecopy(char* Sourse,char* Desk)
{
    enum states state=normal;//��ʼ��������ö�����ͱ���
    FILE *source,*desk;//��������ָ��FILE�͵�ָ��
    char c,d;          //���ڶ�ȡ�ַ�
    if((source=fopen(Sourse,"r"))==NULL)//���ļ�
       printf("can't open the source file\n");
    else if((desk=fopen(Desk,"w"))==NULL)
         printf("can't open the dest file\n");
         else
         {
          c=fgetc(source);
           while(!feof(source))
            {
             d=fgetc(source);
             if(state==normal&&c=='/'&&d=='/')//����//״̬Ǩ�Ƶ�state1
                  state=state1;
             if(state==normal&&c=='/'&&d=='*')//����/*״̬Ǩ�Ƶ�state2
                  state=state2;
             if(state==normal&&c=='('&&d=='"')//print�е������״̬Ǩ�Ƶ�state3
                  state=state3;
             if(state==state1&&c=='\n')//state1�³���\n״̬�ص�normal
                  state=normal;
             if(state==normal||state==state3)//״̬Ϊnormal������state3ʱ��������д��deskָ���ļ�
                  fputc(c,desk);
             if(state==state2&&c=='*'&&d=='/')//״̬Ϊstate2�³���*/�ص�normal
              {
                state=normal;
                c=d;                      //�ص�normal��Ҫ����һ���ַ�
                d=fgetc(source);
              }
              if(state==state3&&c==')'&&d==';')//״̬Ϊstate3�³���);�ص�normal
                 state=normal;
              c=d;
            }
        }
}

