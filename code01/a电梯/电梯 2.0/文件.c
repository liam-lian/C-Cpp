#include "types.h"
#include "��ʼ�����������Һ���.h"
#include "����ģ��.h"
#include "���ģ��.h"
#include "����ģ��.h"
#include "����ģ��.h"
void fileinput(void)  {
    int timeCount=0;                        //��ʱ����ÿѭ��һ��ģ��2ms
    struct REQ theReqs[20];                 //�ݴ�ÿ�λ�õ�ĳʱ�̵�ȫ�������¼�
    struct REQ ocReqs[20];
    int reqCount;                           //�ݴ�ÿ�λ�õ�ĳʱ�̵������¼�����
    int ocCount;
    enum STATE  preState,curState ;         // preState����ǰһ״̬��curState���ݵ�ǰ״̬
                       //�������������ͷָ��
    FILE *fpin,*fpout,*fpout2;              //ָ�������ļ�������ļ�File�ṹ
    struct ELEVATOR elevator;               //�洢���ݶ�����Ϣ����������״̬������¥�㡢ͣ��ʱ��ȵ�


	//�����ļ��������������ļ�
    if(!openFileToRead("input.txt",&fpin)){
       printf("input file can't be opened\n");
       return 0;
    }

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
	   Sleep(1000);
		   //time_count(&timeCount);
	}

    //�ر���������ļ�
	fclose(fpin);
    fclose(fpout);
}
