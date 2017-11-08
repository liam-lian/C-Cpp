#include<stdlib.h>
#include <stdio.h>
#include <graphics.h>

//�ֱ��ʾ���ݿ��������ʱ�� ͣ��ʱ�� ����ÿ��¥��Ҫ��ʱ��
#define To 50
#define Tc 50
#define Ts 50
#define Tu 115
#define Td 115
//ö�ٵ���״̬
enum STATE {IDLE,UP,DOWN,DOOROPENING,DOORCLOSING,STOP}; //IDLE �ǿ���

//���ݽṹ����¼����״̬������¥�㡢ͣ��ʱ����
struct ELEVATOR{
    enum STATE state,tip;   //tip ���ڼ�¼������֮ǰ������״̬����ͣ��״̬
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

