#include "types.h"
#include "初始化及其他杂乱函数.h"
#include "输入模块.h"
#include "输出模块.h"
#include "策略模块.h"
#include "运行模块.h"

static int timeCount=0;                        //计时器，每循环一次模拟2ms
static struct REQ theReqs[20];                 //暂存每次获得的某时刻的全部请求事件
static struct REQ ocReqs[20];
static struct REQ chReq;
static int reqCount,ocCount;
static enum STATE  preState;                   // preState电梯前一状态，curState电梯当前状态
static LISTNODEPTR headp;
static struct ELEVATOR elevator;
static FILE *fpin,*fpout,*fpout2;              //指向请求文件和输出文件File结构

DWORD WINAPI input1(LPVOID lpParameter);
void way_File();
void way_keyboard();
void GetReady();

int main(){
    int way;
    printf("请选择电梯请求的输入方式:\n输入1代表文件输入\n输入2表示键盘输入\n");
    scanf("%d",&way);
    GetReady();
    switch(way){
        case 1:     way_File();break;
        case 2:     way_keyboard();break;
    }
	return 0;
}
void way_File()
{
    get_fileInput(fpin,theReqs,ocReqs,&chReq,&reqCount,&ocCount);              //读取第一个某时刻的所有请求到theReqs中
    while (!(isEnd_fileInput(fpin)&&elevator.state==IDLE)){             //当文件输入结束，且电梯空闲才终止程序
        if ((theReqs[0].Number/20)==timeCount||
            (ocReqs[0].Number/20)==timeCount||
            (chReq.Number/20)==timeCount){     //当请求时间到
            addServList(headp,theReqs,reqCount,&elevator);            //添加请求事件到服务队列中
            ocOperation(&elevator,ocReqs,ocCount);                      //处理所有的开关门请求
            elevator.type=-(chReq.floor);
            get_fileInput(fpin,theReqs,ocReqs,&chReq,&reqCount,&ocCount);      //读取文件中下一时刻的全部请求事件
        }
        preState= elevator.state;//记录前一状态
        runService(&elevator,headp);//根据电梯当前状态计算下一状态
        set_fileOutput(fpout2,timeCount,elevator,headp);
        if (elevator.state!=preState)
            set_fileOutput(fpout,timeCount,elevator,headp);
        system("cls");
        Output(timeCount,elevator,headp);
        timeCount++;
        Sleep(1000);
    }
    fclose(fpin);
    fclose(fpout);
    fclose(fpout2);
    return ;
}
void way_keyboard()
{
    while(1){
       HANDLE hThread;
       hThread=CreateThread(NULL,0,input1,NULL,0,NULL);
       preState= elevator.state;//记录前一状态
       runService(&elevator,headp);//根据电梯当前状态计算下一状态
	   //3.输出电梯状态
	   //输出电梯状态信息到文件2中
	   set_fileOutput(fpout2,timeCount,elevator, headp);
	   if (elevator.state!=preState)
	 	   set_fileOutput(fpout,timeCount,elevator, headp);
        system("cls");
	 	Output(timeCount,elevator,headp);
	   timeCount++;
	   Sleep(1000);
    }
    return ;
}
DWORD WINAPI input1(LPVOID lpParameter)
{
    while(1){
    int Floor;
    char upDown;
    scanf("%c",&upDown);
    reqCount=0;
    ocCount=0;
     if(upDown>='1'&&upDown<='9'){
          theReqs[reqCount].floor=upDown-'0';
          theReqs[reqCount].Number=20*timeCount+reqCount;
          theReqs[reqCount++].kind='T';
         }
     else if(upDown>='A'&&upDown<='H'){
         theReqs[reqCount].floor=upDown-'A'+1;
         theReqs[reqCount].Number=20*timeCount+reqCount;
         theReqs[reqCount++].kind='U';
         }
     else if(upDown>='I'&&upDown<='P'){
         theReqs[reqCount].floor=upDown-'I'+2;
         theReqs[reqCount].Number=20*timeCount+reqCount;
         theReqs[reqCount++].kind='D';
         }
     else if(upDown=='o'||upDown=='c'){
         ocReqs[ocCount].floor=0;
         ocReqs[ocCount].Number=20*timeCount+reqCount;
         ocReqs[ocCount++].kind=upDown;
        }
    else if(upDown=='a') elevator.type=0;
    else if(upDown=='b') elevator.type=1;
     addServList(headp,theReqs,reqCount,&elevator);
     ocOperation(&elevator,ocReqs,ocCount);
    }
    return ;
}
void GetReady()
{
    if(!openFileToWrite("output.txt",&fpout)){
       printf("output file can't be opened\n");
       return 0;
    }
   if(!openFileToWrite("outputDetail.txt",&fpout2)){
       printf("output file can't be opened\n");
       return 0;
    }
    headp=(LISTNODEPTR)malloc(sizeof(LISTNODE));                //设置链表头节点。该头节点不实际存储请求。
    headp->nextPtr=NULL;
    initElevator(&elevator);                                    //初始化电梯结构信息.电梯初始位于1层，为空闲状态。
    if(!openFileToRead("input.txt",&fpin)){
        printf("input file can't be opened\n");
    }
    ocReqs[0].Number=-20;
    chReq.Number=-20;
    chReq.floor=(-elevator.type);
    return ;
}
