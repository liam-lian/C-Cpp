//Ï´ÅÆ·¢ÅÆ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void output(int n,int m);
void Xipai(int a[][13]);
void Fapai(int a[][13]);
int main()
{
    int a[4][13]={0};
    srand(time(NULL));
    Xipai(a);
    Fapai(a);
    system("PAUSE");
    return 0;
}
void Xipai(int a[][13])
{
    int i,j,p;
    for(p=1;p<=52;p++)
      {
          i=rand()%4;
          j=rand()%13;
          if(a[i][j]==0)
              a[i][j]=p;
          else
            {
             while(a[i][j] !=0)
                 {
                     i=rand()%4;
                      j=rand()%13;
                 }
            a[i][j]=p;
            }
      }     
}
void output(int n,int m)
{
    switch(n)
    {
        case 0:printf("ºìÌÒ");break;
        case 1:printf("ºÚÌÒ");break;
        case 2:printf("·½Æ¬");break;
        case 3:printf("Ã·»¨");break;
    }
    if(m>=1&&m<=9)
       printf(" %d\n",m+1);
    else
       switch(m+1)
        {
         case 1:printf(" A\n");break;          
         case 11:printf(" J\n");break;
         case 12:printf(" Q\n");break;
         case 13:printf(" K\n");break;
         }
}
void Fapai(int a[][13])
{
    int i,j,num,ok=1;
    for(num=1;num<=52;num++)
      {
         for(i=0;i<=3&&ok==1;i++)
              for(j=0;j<=12&&ok==1;j++)
                    if(a[i][j]==num)
                        {
                            ok=0;
                            printf("µÚ%-2dÕÅÅÆÊÇ:",num);
                            output(i,j);
                        }
         ok=1;
         }
}
