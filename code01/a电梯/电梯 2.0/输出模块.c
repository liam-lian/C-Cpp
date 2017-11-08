/*将电梯当前运行情况及电梯请求队列情况按一定的文件格式输出到一个文本文件中*/
#include "types.h"
static void putState(struct ELEVATOR elevator,FILE *fpout)
{
    switch(elevator.state)
    {
        case IDLE:          fprintf(fpout,"State=       IDLE,");break;
        case DOOROPENING:   fprintf(fpout,"State=DOOROPENING,");break;
        case STOP:          fprintf(fpout,"State=       STOP,");break;
        case DOORCLOSING:   fprintf(fpout,"State=DOORCLOSING,");break;
        case UP:            fprintf(fpout,"State=         UP,");break;
        case DOWN:          fprintf(fpout,"State=       DOWN,");break;
    }
    return ;
}
void set_fileOutput(FILE *fpout,int timeCount,struct ELEVATOR elevator,LISTNODEPTR headp)
{
    fprintf(fpout,"T=%3d,",timeCount);
    putState(elevator,fpout);
    if(elevator.state==UP){
        fprintf(fpout,"NowF=%d+%d,",elevator.cur,elevator.runtime);
    }
    else if(elevator.state==DOWN){
        fprintf(fpout,"NowF=%d-%d,",elevator.cur,elevator.runtime);
    }
    else{
        fprintf(fpout,"NowF=%d 0,",elevator.cur);
    }
    fprintf(fpout,"GoalF=%d,",elevator.aim);
    if(elevator.state==STOP){
        fprintf(fpout,"StopT=%d,",elevator.stime);
    }
    else{
        fprintf(fpout,"StopT=0,");

    }
    fprintf(fpout,"waifF=");
    while(headp->nextPtr!=NULL){
        fprintf(fpout,"%d%c ",headp->req.floor,headp->req.kind);
        headp=headp->nextPtr;
    }
    fprintf(fpout,"\n");
    return ;
}




void Output(int timeCount,struct ELEVATOR elevator,LISTNODEPTR headp)
{
     int i=1;
     printf("\n\n\n\n\n\n\n\n\n\n%c",17);
     for(i=1;i<=77;i++)
        printf("~");
     printf("%c\n",16);
     printf("%c",17);
     for(i=1;i<=24;i++)
        printf(" ");
     printf("<<欢迎使用电梯模拟控制系统>>");
     for(i=1;i<=25;i++)
        printf(" ");
     printf("%c\n",16);
     printf("%c",17);
     for(i=1;i<=31;i++)
        printf(" ");
     printf("%c WELCOME %c",123,125);
     for(i=1;i<=31;i++)
        printf(" ");
     printf("%5c\n",16);
     printf("%c",17);
     for(i=1;i<=77;i++)
        printf("~");
     printf("%c\n",16);

  //打印电梯的运行状态

     printf("%c",17);
     printf("\t      %c%c电梯运行请求%c%c\t\t\t\t\t              %c\n",40,40,41,41,16);
     printf("%c\t* * * * * * * * * * * * * *%44c\n",17,16);
     printf("%c\t*   电梯内部     电梯外部 *%44c\n",17,16);
     printf("%c\t*                上  下   *%44c\n",17,16);
     qingqiu(9,elevator,headp);
     printf("\t          %c%c运行状态%c%c%17c\n",40,40,41,41,16);
     qingqiu(8,elevator,headp);
     printf("\t   * * * * * * * * * * * * * *%9c\n",16);
     qingqiu(7,elevator,headp);
     printf("\t   * 当前状态:");
     switch(elevator.state){
        case IDLE:          printf("空闲    ");break;
        case DOOROPENING:   printf("开门    ");break;
        case STOP:          printf("停靠    ");break;
        case DOORCLOSING:   printf("关门    ");break;
        case UP:            printf("向上运行");break;
        case DOWN:          printf("向下运行");break;
        }
     printf("       *%9c\n",16);
     qingqiu(6,elevator,headp);
     printf("\t   * 当前楼层:第%2d层         *%9c\n",elevator.cur,16);
     qingqiu(5,elevator,headp);
     printf("\t   * 目标楼层:第%2d层         *%9c\n",elevator.aim,16);
     qingqiu(4,elevator,headp);
     printf("\t   * * * * * * * * * * * * * *%9c\n",16);
     qingqiu(3,elevator,headp);
     printf("%44c\n",16);
     qingqiu(2,elevator,headp);
     printf("\t  注：左图中@表示电梯当前所处楼层%6c\n",16);
     qingqiu(1,elevator,headp);
     printf("\t     左图中*表示请求队列中楼层分布%5c\n",16);
     printf("%c\t* * * * * * * * * * * * * *%11c情况%29c\n",17,32,16);
     printf("%c\t%71c\n",17,16);
     printf("%c",17);
     for(i=1;i<=4;i++)
        printf("~");
     printf(" 温馨提示 ");
     for(i=1;i<=63;i++)
        printf("~");
     printf("%c\n",16);
     printf("%c\t%71c\n",17,16);
     printf("%c 键盘输入：1 2 3 4 5 6 7 8 9，表示：电梯在该楼层时内部有请求；   %13c\n",17,16);
     printf("%c 键盘输入：A B C D E F G H ，表示：1~8楼电梯外部在该楼层有上行请求；  %8c\n",17,16);
     printf("%c 键盘输入：  I J K L M N O P ，表示：2~9楼电梯外部在该楼层有下行请求； %7c\n",17,16);
     printf("%c 键盘输入：o:表示开门； c:表示关门。");
     printf("%42c\n",16);
     printf("%c",17);
     for(i=1;i<=77;i++)
        printf("~");
     printf("%c\n",16);
     printf("%c%44c程序编制人员：陈思嘉&连状&郑琼霞 %c\n",17,32,16);
     printf("%c",17);
     for(i=1;i<=77;i++)
        printf("~");
     printf("%c",16);
     printf("\n");

}


//函数
qingqiu(int n,struct ELEVATOR elevator,LISTNODEPTR headp)
{
     int k=1,a=1,b=1,c=1,e=1,f=1,d=1,g=1;
     LISTNODEPTR hp=headp;
     if(n==elevator.cur)
        printf("%c\t* @",17);
     else
        printf("%c\t*  ",17);//打印了当前楼层
     while(headp!=NULL)
     {
        if(headp->req.floor==n&&headp->req.kind=='T'&&g==1)
        {
            g=0;
            printf("%d  %c%10d",n,5,n);
        }

        headp=headp->nextPtr;
      }
    if(g==1)
        printf("%d  %11d",n,n);
      headp=hp;
     while(headp!=NULL)
     {
        if(headp->req.floor==n&&headp->req.kind=='U'&&k==1)
        {
            k=0;
            printf(" %c",5);
        }
         headp=headp->nextPtr;
     }

    if(k==1)
            printf("  ");
        headp=hp;
     while(headp!=NULL)
        {
           if(headp->req.floor==n&&headp->req.kind=='D'&&b==1)
        {
            b=0;
            printf("  %c",5);
        }

        headp=headp->nextPtr;
      }
      if(b==1){
            printf("   ");

        }
      printf("    *");
        return ;

}
