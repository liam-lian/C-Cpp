/*将电梯当前运行情况及电梯请求队列情况按一定的文件格式输出到一个文本文件中并将相关状态输出到屏幕上*/
#include "types.h"
static void putState(struct ELEVATOR elevator,FILE *fpout)/*输出当前电梯状态到fpout文件中*/
{
    switch(elevator.state){
        case IDLE:          fprintf(fpout,"State=       IDLE,");break;
        case DOOROPENING:   fprintf(fpout,"State=DOOROPENING,");break;
        case STOP:          fprintf(fpout,"State=       STOP,");break;
        case DOORCLOSING:   fprintf(fpout,"State=DOORCLOSING,");break;
        case UP:            fprintf(fpout,"State=         UP,");break;
        case DOWN:          fprintf(fpout,"State=       DOWN,");break;
    }
    return ;
}
/*将各个电梯参数输出到文件中*/
void set_fileOutput(FILE *fpout,int timeCount,struct ELEVATOR elevator,LISTNODEPTR headp)
{
    fprintf(fpout,"T=%3d,",timeCount);                //输出当前时间
    putState(elevator,fpout);                        //输出当前电梯状态到fpout文件中
    if(elevator.state==UP){                         //当前状态为上升
        fprintf(fpout,"NowF=%d+%d,",elevator.cur,elevator.runtime);
    }
    else if(elevator.state==DOWN){                   //当前状态为下降
        fprintf(fpout,"NowF=%d-%d,",elevator.cur,elevator.runtime);
    }
    else{
        fprintf(fpout,"NowF=%d 0,",elevator.cur);
    }
    fprintf(fpout,"GoalF=%d,",elevator.aim);          //输出目标楼层
    if(elevator.state==STOP)                          //当前状态为停靠
        fprintf(fpout,"StopT=%d,",elevator.stime);
    else
        fprintf(fpout,"StopT=0,");                    //当前状态非停靠
    fprintf(fpout,"waifF=");
    while(headp->nextPtr!=NULL){                     //遍历链表，输出未响应的请求
        fprintf(fpout,"%d%c ",headp->req.floor,headp->req.kind);
        headp=headp->nextPtr;
    }
    fprintf(fpout,"\n");
    return ;
}
/*当前楼层及未响应请求的图形化输出*/
void Output_requst(int n,struct ELEVATOR elevator,LISTNODEPTR headp)
{
     int k=1,b=1,g=1;//g标记电梯内部请求，k标记上行请求，b标记下行请求
     LISTNODEPTR hp=headp;
     if(n==elevator.cur)    printf("%c\t* @ ",17);
     else                   printf("%c\t*   ",17);//打印当前楼层的状态，如果该楼层为当前楼层，以@标记
     while(headp!=NULL){                         //遍历链表中是否有电梯内部请求
        if(headp->req.floor==n&&headp->req.kind=='T'&&g==1){
            g=0;
            printf("%d   %c%7d ",n,5,n);         //电梯内部有请求的情况，如果电梯内部在该层有请求，以////标记
        }
        headp=headp->nextPtr;
      }
    if(g==1)          printf("%d %10d ",n,n);     //电梯内部无请求的情况
    headp=hp;
     while(headp!=NULL){                          //遍历链表中是否有上行请求
        if(headp->req.floor==n&&headp->req.kind=='U'&&k==1){
            k=0;
            printf(" %c",24);                      //电梯有上行请求的情况，以//标记
        }
        headp=headp->nextPtr;
     }
    if(k==1)    printf("  ");                      //电梯无上行请求的情况
    headp=hp;
     while(headp!=NULL){                           //遍历链表中是否有下行请求
        if(headp->req.floor==n&&headp->req.kind=='D'&&b==1){
            b=0;
            printf("  %c",25);                     //电梯有下行请求的情况，以//标记
        }
    headp=headp->nextPtr;
    }
    if(b==1)    printf("   ");                      //电梯无下行请求的情况
    printf("    *");
    return ;

}
/*输出电梯当前状态到屏幕上*/
void Output(int timeCount,struct ELEVATOR elevator,LISTNODEPTR headp)
{
     int i=1;                               //打印出基本用户界面
     printf("%c",17);
     for(i=1;i<=77;i++)     printf("~");
     printf("%c\n",16);
     printf("%c",17);
     for(i=1;i<=24;i++)      printf(" ");
     printf("<<欢迎使用电梯模拟控制系统>>");
     for(i=1;i<=25;i++)      printf(" ");
     printf("%c\n",16);
      printf("%c",17);
     for(i=1;i<=77;i++)
      printf("~");
     printf("%c\n",16);

  //打印电梯的运行状态
     printf("%c",17);
     printf("\t      %c%c电梯运行请求%c%c\t\t\t\t\t              %c\n",40,40,41,41,16);
     printf("%c\t* * * * * * * * * * * * * *%44c\n",17,16);
     printf("%c\t*   电梯内部     电梯外部 *%44c\n",17,16);
     Output_requst(9,elevator,headp);                         //当前楼层及未响应请求的图形化输出
     printf("\t          %c%c运行状态%c%c%17c\n",40,40,41,41,16);
     Output_requst(8,elevator,headp);
     printf("\t   * * * * * * * * * * * * * *%9c\n",16);
     Output_requst(7,elevator,headp);
     printf("\t   * 当前状态:");                                 //提示电梯的当前状态
     switch(elevator.state){
        case IDLE:          printf("空闲    ");break;
        case DOOROPENING:   printf("开门    ");break;
        case STOP:          printf("停靠    ");break;
        case DOORCLOSING:   printf("关门    ");break;
        case UP:            printf("向上运行");break;
        case DOWN:          printf("向下运行");break;
        }
     printf("       *%9c\n",16);
     Output_requst(6,elevator,headp);                           //提示当前楼层和目标楼层
     printf("\t   * 当前楼层:第%2d层         *%9c\n",elevator.cur,16);
     Output_requst(5,elevator,headp);
     printf("\t   * 目标楼层:第%2d层         *%9c\n",elevator.aim,16);
     Output_requst(4,elevator,headp);
     printf("\t   * * * * * * * * * * * * * *%9c\n",16);   //当前楼层及未响应请求的图形化输出
     Output_requst(3,elevator,headp);                      //用户界面说明
     printf("\t注：左图中@表示电梯当前所处楼层；%6c\n",16);
     Output_requst(2,elevator,headp);
     printf("\t    左图中%c表示该楼层电梯内部有请求；%2c\n",5,16);
     Output_requst(1,elevator,headp);
     printf("\t    左图中%c、%c分别表示该楼层有上下行%3c\n",24,25,16);
     printf("%c\t* * * * * * * * * * * * * *%11c请求。%27c\n",17,32,16);
     printf("%c",17);
     for(i=1;i<=4;i++)
        printf("~");
     printf(" 温馨提示 ");
     for(i=1;i<=63;i++)
        printf("~");
     printf("%c\n",16);
    //用户操作提示说明
     printf("%c 键盘输入：1 2 3 4 5 6 7 8 9，表示：电梯在该楼层时内部有请求；   %13c\n",17,16);
     printf("%c 键盘输入：A B C D E F G H ，表示：1~8楼电梯外部在该楼层有上行请求；  %8c\n",17,16);
     printf("%c 键盘输入：I J K L M N O P ，表示：2~9楼电梯外部在该楼层有下行请求；   %7c\n",17,16);
     printf("%c 键盘输入：o:表示开门,c:表示关门;a:表示顺便服务策略,b:表示先来先服务策略。");
     printf("%4c\n",16);
     printf("%c",17);
     for(i=1;i<=77;i++)     printf("~");
     printf("%c\n",16);
     printf("%c当前策略:",17);
     switch(elevator.type){
        case 0:printf("顺便服务%21c",32);break;
        case 1:printf("先来先服务%19c",32);break;
     }
     printf("程序编制人员：陈思嘉&连状&郑琼霞 %7c\n",16);
     printf("%c",17);
     for(i=1;i<=77;i++)     printf("~");
     printf("%c\n",16);
}
