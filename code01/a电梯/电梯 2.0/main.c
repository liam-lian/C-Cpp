#include "types.h"
#include "��ʼ�����������Һ���.h"
#include "����ģ��.h"
#include "���ģ��.h"
#include "����ģ��.h"
#include "����ģ��.h"
DWORD WINAPI input1(LPVOID lpParameter);
LISTNODEPTR headp;
struct ELEVATOR elevator;
int main(){
    int way;
    printf("��ѡ�������������뷽ʽ:\n����1�����ļ�����;����2��ʾ��������\n");
    scanf("%d",&way);
    int timeCount=0;                        //��ʱ����ÿѭ��һ��ģ��2ms
    struct REQ theReqs[20];                 //�ݴ�ÿ�λ�õ�ĳʱ�̵�ȫ�������¼�
    struct REQ ocReqs[20];
    int reqCount;                           //�ݴ�ÿ�λ�õ�ĳʱ�̵������¼�����
    int ocCount;
    enum STATE  preState,curState ;         // preState����ǰһ״̬��curState���ݵ�ǰ״̬
                          //�������������ͷָ��
    FILE *fpin,*fpout,*fpout2;              //ָ�������ļ�������ļ�File�ṹ
                  //�洢���ݶ�����Ϣ����������״̬������¥�㡢ͣ��ʱ��ȵ�


	//�����ļ��������������ļ�

	//�����ļ���������ļ�3��������״̬�б仯ʱ�ͻ����ļ������
    if(!openFileToWrite("output.txt",&fpout)){
       printf("output file can't be opened\n");
       return 0;
    }
	//�����ļ���������ļ�2���������ļ������������Ϣ
   if(!openFileToWrite("outputDetail.txt",&fpout2)){//�����ļ�������������ļ�
       printf("output file can't be opened\n");
       return 0;
    }
    //��������ͷ�ڵ㡣��ͷ�ڵ㲻ʵ�ʴ洢����
    headp=(LISTNODEPTR)malloc(sizeof(LISTNODE));
    headp->nextPtr=NULL;

    //��ʼ�����ݽṹ��Ϣ.���ݳ�ʼλ��1�㣬Ϊ����״̬��
    initElevator(&elevator);

    //��ʼģ���������
    if(way==1)
    {
       if(!openFileToRead("input.txt",&fpin))
          printf("input file can't be opened\n");
       else{
          get_fileInput(fpin,theReqs,ocReqs,&reqCount,&ocCount);  //��ȡ��һ��ĳʱ�̵���������theReqs��

          while (!(isEnd_fileInput(fpin)&&elevator.state==IDLE)){ //���ļ�����������ҵ��ݿ��в���ֹ����
	  //1.������������
	         if (theReqs[0].time==timeCount||ocReqs[0].time==timeCount){                       //������ʱ�䵽
		       addServList(headp,theReqs,reqCount,elevator);     //��������¼������������
		       ocOperation(&elevator,ocReqs,ocCount);            //�������еĿ���������
      	       get_fileInput(fpin,theReqs,ocReqs,&reqCount,&ocCount); //��ȡ�ļ�����һʱ�̵�ȫ�������¼�
	           }
       //2.�������״̬
              preState= elevator.state;//��¼ǰһ״̬
              runService(&elevator,&headp);//���ݵ��ݵ�ǰ״̬������һ״̬
	   //3.�������״̬
	   //�������״̬��Ϣ���ļ�2��
	          set_fileOutput(fpout2,timeCount,elevator, headp);
	          if (elevator.state!=preState)
	 	         set_fileOutput(fpout,timeCount,elevator, headp);
              Output(timeCount,elevator,headp);
	      /*��״̬�仯������ǰʱ�䡢״̬�͵ȴ����е����д�뵽�ļ��С�  */
	   //4.ʱ��Ƭ��1
	          timeCount++;
	          Sleep(5000);
		   //time_count(&timeCount);
	          }
           }

    //�ر���������ļ�
	fclose(fpin);
    }
   else
    {
      while(1){
       HANDLE hThread;
       hThread=CreateThread(NULL,0,input1,NULL,0,NULL);
       preState= elevator.state;//��¼ǰһ״̬
       runService(&elevator,&headp);//���ݵ��ݵ�ǰ״̬������һ״̬
	   //3.�������״̬
	   //�������״̬��Ϣ���ļ�2��
	   set_fileOutput(fpout2,timeCount,elevator, headp);
	   if (elevator.state!=preState)
	 	   set_fileOutput(fpout,timeCount,elevator, headp);
	 	Output(timeCount,elevator,headp);
	      /*��״̬�仯������ǰʱ�䡢״̬�͵ȴ����е����д�뵽�ļ��С�  */
	   //4.ʱ��Ƭ��1
	   timeCount++;
	   Sleep(1000);
	  }

    }
    fclose(fpout);
    fclose(fpout2);
    system("pause");
	return 0;
}
DWORD WINAPI input1(LPVOID lpParameter)
{
    //WaitForSingleObject(hMutex,INFINITE);
    while(1)
    {
    int Floor;
    char upDown;
    struct REQ theReqs[20];                 //�ݴ�ÿ�λ�õ�ĳʱ�̵�ȫ������-�¼�
    struct REQ ocReqs[20];
    int reqCount=0;                           //�ݴ�ÿ�λ�õ�ĳʱ�̵������¼�����
    int ocCount=0;
    scanf("%c",&upDown);
     if(upDown>='1'&&upDown<='9'){
          theReqs[reqCount].floor=upDown-'0';
          theReqs[reqCount++].kind='T';
         }
     if(upDown>='A'&&upDown<='H'){
         theReqs[reqCount].floor=upDown-'A'+1;
         theReqs[reqCount++].kind='U';
         }
     else if(upDown>='I'&&upDown<='P'){
         theReqs[reqCount].floor=upDown-'I'+2;
         theReqs[reqCount++].kind='D';
         }
     else if(upDown=='o'||upDown=='c'){
         ocReqs[ocCount].floor=0;
         ocReqs[ocCount++].kind=upDown;
           }
     addServList(headp,theReqs,reqCount,elevator);
     ocOperation(&elevator,ocReqs,ocCount);
    }
}


