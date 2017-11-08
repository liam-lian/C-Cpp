#include "types.h"
#include "��ʼ�����������Һ���.h"
#include "����ģ��.h"
#include "���ģ��.h"
#include "����ģ��.h"
#include "����ģ��.h"

static int timeCount=0;                        //��ʱ����ÿѭ��һ��ģ��2ms
static struct REQ theReqs[20];                 //�ݴ�ÿ�λ�õ�ĳʱ�̵�ȫ�������¼�
static struct REQ ocReqs[20];
static struct REQ chReq;
static int reqCount,ocCount;
static enum STATE  preState;                   // preState����ǰһ״̬��curState���ݵ�ǰ״̬
static LISTNODEPTR headp;
static struct ELEVATOR elevator;
static FILE *fpin,*fpout,*fpout2;              //ָ�������ļ�������ļ�File�ṹ

DWORD WINAPI input1(LPVOID lpParameter);
void way_File();
void way_keyboard();
void GetReady();

int main(){
    int way;
    printf("��ѡ�������������뷽ʽ:\n����1�����ļ�����\n����2��ʾ��������\n");
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
    get_fileInput(fpin,theReqs,ocReqs,&chReq,&reqCount,&ocCount);              //��ȡ��һ��ĳʱ�̵���������theReqs��
    while (!(isEnd_fileInput(fpin)&&elevator.state==IDLE)){             //���ļ�����������ҵ��ݿ��в���ֹ����
        if ((theReqs[0].Number/20)==timeCount||
            (ocReqs[0].Number/20)==timeCount||
            (chReq.Number/20)==timeCount){     //������ʱ�䵽
            addServList(headp,theReqs,reqCount,&elevator);            //��������¼������������
            ocOperation(&elevator,ocReqs,ocCount);                      //�������еĿ���������
            elevator.type=-(chReq.floor);
            get_fileInput(fpin,theReqs,ocReqs,&chReq,&reqCount,&ocCount);      //��ȡ�ļ�����һʱ�̵�ȫ�������¼�
        }
        preState= elevator.state;//��¼ǰһ״̬
        runService(&elevator,headp);//���ݵ��ݵ�ǰ״̬������һ״̬
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
       preState= elevator.state;//��¼ǰһ״̬
       runService(&elevator,headp);//���ݵ��ݵ�ǰ״̬������һ״̬
	   //3.�������״̬
	   //�������״̬��Ϣ���ļ�2��
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
    headp=(LISTNODEPTR)malloc(sizeof(LISTNODE));                //��������ͷ�ڵ㡣��ͷ�ڵ㲻ʵ�ʴ洢����
    headp->nextPtr=NULL;
    initElevator(&elevator);                                    //��ʼ�����ݽṹ��Ϣ.���ݳ�ʼλ��1�㣬Ϊ����״̬��
    if(!openFileToRead("input.txt",&fpin)){
        printf("input file can't be opened\n");
    }
    ocReqs[0].Number=-20;
    chReq.Number=-20;
    chReq.floor=(-elevator.type);
    return ;
}
