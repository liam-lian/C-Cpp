#include<stdlib.h>
#include <stdio.h>
#include <windows.h>

//�ֱ��ʾ���ݿ��������ʱ�� ͣ��ʱ�� ����ÿ��¥��Ҫ��ʱ��
#define To 5
#define Tc 5
#define Ts 5
#define Tu 3
#define Td 3
//ö�ٵ���״̬
enum STATE {IDLE,UP,DOWN,DOOROPENING,DOORCLOSING,STOP}; //IDLE �ǿ���

//���ݽṹ����¼����״̬������¥�㡢ͣ��ʱ����
struct ELEVATOR{
    enum STATE state;
    int aim,cur,stime,runtime;
};
//�����¼�
struct REQ{
    int time;//��ʾ�����ʱ��
    int floor;//������������¥��
    char kind;//��ʾ���������
};

//�����������ڵ�
struct LIST {
   struct REQ req;
   struct LIST*nextPtr;
};

typedef struct LIST LISTNODE;
typedef LISTNODE * LISTNODEPTR;
typedef struct ELEVATOR * ELEVATORPTR;
//�˴������������Ҫ�����ͻ��߳�������

