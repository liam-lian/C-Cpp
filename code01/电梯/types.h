#include<stdlib.h>
#include <stdio.h>
#include <graphics.h>

//分别表示电梯快关门所需时间 停靠时间 上下每层楼需要的时间
#define To 50
#define Tc 50
#define Ts 50
#define Tu 115
#define Td 115
//枚举电梯状态
enum STATE {IDLE,UP,DOWN,DOOROPENING,DOORCLOSING,STOP}; //IDLE 是空闲

//电梯结构，记录电梯状态、所在楼层、停靠时长等
struct ELEVATOR{
    enum STATE state,tip;   //tip 用于记录电梯是之前是上升状态还是停靠状态
    int aim,cur,stime,runtime;
    int type;               //0表示电梯处于顺便服务状态 1表示电梯处于先来先服务状态
};
//请求事件
struct REQ{
    int Number;             //表示请求的序号，用于先到先服务策略
    int floor;              //代表请求发生的楼层
    char kind;              //表示请求的类型
};

//请求队列链表节点
struct LIST {
   struct REQ req;
   struct LIST*nextPtr;
};

typedef struct LIST LISTNODE;
typedef LISTNODE * LISTNODEPTR;
typedef struct ELEVATOR * ELEVATORPTR;

