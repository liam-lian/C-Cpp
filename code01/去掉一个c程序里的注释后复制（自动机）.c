//去掉一个c程序里的注释
#include <stdio.h>
#include <stdlib.h>
enum states{normal,state1,state2,state3};
//枚举类型 normal代表正常输出的状态 state1代表处于//后面的注释的状态
//state2代表处于/*后面的注释的状态  state3代表处于printf函数中的状态
void filecopy(char* Sourse,char* Desk);//函数用于处理注释并且复制到Desk指向的文件中
int main()
{
    filecopy("text1.c","text2.c");
    return 0;
}
void filecopy(char* Sourse,char* Desk)
{
    enum states state=normal;//初始化，定义枚举类型变量
    FILE *source,*desk;//定义两个指向FILE型的指针
    char c,d;          //用于读取字符
    if((source=fopen(Sourse,"r"))==NULL)//打开文件
       printf("can't open the source file\n");
    else if((desk=fopen(Desk,"w"))==NULL)
         printf("can't open the dest file\n");
         else
         {
          c=fgetc(source);
           while(!feof(source))
            {
             d=fgetc(source);
             if(state==normal&&c=='/'&&d=='/')//出现//状态迁移到state1
                  state=state1;
             if(state==normal&&c=='/'&&d=='*')//出现/*状态迁移到state2
                  state=state2;
             if(state==normal&&c=='('&&d=='"')//print中的情况，状态迁移到state3
                  state=state3;
             if(state==state1&&c=='\n')//state1下出现\n状态回到normal
                  state=normal;
             if(state==normal||state==state3)//状态为normal，或者state3时，将数据写入desk指向文件
                  fputc(c,desk);
             if(state==state2&&c=='*'&&d=='/')//状态为state2下出现*/回到normal
              {
                state=normal;
                c=d;                      //回到normal，要跳过一个字符
                d=fgetc(source);
              }
              if(state==state3&&c==')'&&d==';')//状态为state3下出现);回到normal
                 state=normal;
              c=d;
            }
        }
}

