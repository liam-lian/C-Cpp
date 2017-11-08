#include<stdlib.h>
#include <stdio.h>
#include <windows.h>

//�ֱ��ʾ���ݿ��������ʱ�� ͣ��ʱ�� ����ÿ��¥��Ҫ��ʱ��
#define To 2
#define Tc 2
#define Ts 2
#define Tu 3
#define Td 3
//ö�ٵ���״̬
enum STATE {IDLE,UP,DOWN,DOOROPENING,DOORCLOSING,STOP}; //IDLE �ǿ���

//���ݽṹ����¼����״̬������¥�㡢ͣ��ʱ����
struct ELEVATOR{
    enum STATE state,flag;   //flag ���ڼ�¼������֮ǰ������״̬����ͣ��״̬
    int aim,cur,stime,runtime;
    int type;               //0��ʾ���ݴ���˳�����״̬ 1��ʾ���ݴ��������ȷ���״̬
};
//�����¼�
struct REQ{
    int Number;             //��ʾ�������ţ������ȵ��ȷ������
    int floor;              //������������¥��
    char kind;              //��ʾ���������
};

//�����������ڵ�
struct LIST {
   struct REQ req;
   struct LIST*nextPtr;
};

typedef struct LIST LISTNODE;
typedef LISTNODE * LISTNODEPTR;
typedef struct ELEVATOR * ELEVATORPTR;

