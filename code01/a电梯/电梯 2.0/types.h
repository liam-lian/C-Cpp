#include<stdlib.h>
#include <stdio.h>
#include <windows.h>

//分别表示电梯快关门所需时间 停靠时间 上下每层楼需要的时间
#define To 5
#define Tc 5
#define Ts 5
#define Tu 3
#define Td 3
//枚举电梯状态
enum STATE {IDLE,UP,DOWN,DOOROPENING,DOORCLOSING,STOP}; //IDLE 是空闲

//电梯结构，记录电梯状态、所在楼层、停靠时长等
struct ELEVATOR{
    enum STATE state;
    int aim,cur,stime,runtime;
};
//请求事件
struct REQ{
    int time;//表示请求的时间
    int floor;//代表请求发生的楼层
    char kind;//表示请求的类型
};

//请求队列链表节点
struct LIST {
   struct REQ req;
   struct LIST*nextPtr;
};

typedef struct LIST LISTNODE;
typedef LISTNODE * LISTNODEPTR;
typedef struct ELEVATOR * ELEVATORPTR;
//此处可添加其他需要的类型或者常量定义

