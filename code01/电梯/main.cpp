#include "types.h"
#include "初始化及其他杂乱函数.h"
#include "输入模块.h"
#include "输出模块.h"
#include "策略模块.h"
#include "运行模块.h"

static int timeCount=0;                        //计时器，每循环一次模拟2ms
static struct REQ theReqs[20];                 //暂存每次获得的某时刻的全部请求事件
static struct REQ ocReqs[20];
static struct REQ deleteReqs[20];
static struct REQ chReq;
static int reqCount = 0, ocCount = 0, deleteCount = 0;
static enum STATE  preState;                   // preState电梯前一状态，curState电梯当前状态
static LISTNODEPTR headp;
static struct ELEVATOR elevator;
static bool broken[10];
static 	mouse_msg msg = { 0 }, flag;
void output();
void input();
void GetReady();

int main(){
	initgraph(1280,640);
	setfont(18, 0, "宋体");
	setbkmode(TRANSPARENT);
	GetReady();
	for (; is_run(); delay_fps(60)){
		input();
		runService(&elevator, headp);
		timeCount++;
		cleardevice();
		output(elevator,headp,broken);
		xyprintf(0, 0, "%3d %3d", msg.x, msg.y);
	}
	closegraph();
	return 0;
}
void GetReady()
{
    headp=(LISTNODEPTR)malloc(sizeof(LISTNODE));                //设置链表头节点。该头节点不实际存储请求。
    headp->nextPtr=NULL;
    initElevator(&elevator,headp,broken);                                    //初始化电梯结构信息.电梯初始位于1层，为空闲状态。
    ocReqs[0].Number=-20;
    chReq.Number=-20;
    chReq.floor=(-elevator.type);
    return ;
}
void input()
{
	reqCount = 0;
	ocCount = 0;
	deleteCount = 0;
	flag= msg;
	while (mousemsg())
	{
		msg = getmouse();
	}
	//处理内部请求
	if ((msg.x >= 38) && (msg.x <= 98) &&
		(msg.y >= 413) && (msg.y <= 473)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 1;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'T';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 1;
			deleteReqs[deleteCount].kind = 'T';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 38) && (msg.x <= 98) &&
		(msg.y >= 321) && (msg.y <= 380)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 3;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'T';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 3;
			deleteReqs[deleteCount].kind = 'T';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 38) && (msg.x <= 98) &&
		(msg.y >= 232) && (msg.y <= 292)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 5;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'T';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 5;
			deleteReqs[deleteCount].kind = 'T';
			deleteReqs[deleteCount++].Number = 0;
		}
     }
	if ((msg.x >= 38) && (msg.x <= 98) &&
		(msg.y >= 145) && (msg.y <= 205)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 7;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'T';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 7;
			deleteReqs[deleteCount].kind = 'T';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 38) && (msg.x <= 98) &&
		(msg.y >= 49) && (msg.y <= 109)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 9;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'T';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 9;
			deleteReqs[deleteCount].kind = 'T';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 116) && (msg.x <= 176) &&
		(msg.y >= 363) && (msg.y <= 423)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 2;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'T';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 2;
			deleteReqs[deleteCount].kind = 'T';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 117) && (msg.x <= 177) &&
		(msg.y >= 279) && (msg.y <= 339)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 4;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'T';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 4;
			deleteReqs[deleteCount].kind = 'T';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 114) && (msg.x <= 174) &&
		(msg.y >= 185) && (msg.y <= 245)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 6;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'T';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 6;
			deleteReqs[deleteCount].kind = 'T';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 118) && (msg.x <= 178) &&
		(msg.y >= 97) && (msg.y <= 157)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 8;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'T';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 8;
			deleteReqs[deleteCount].kind = 'T';
			deleteReqs[deleteCount++].Number = 0;
		}
	}

	//外部请求
	if ((msg.x >= 248) && (msg.x <= 293) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 1;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'U';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 1;
			deleteReqs[deleteCount].kind = 'U';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 366) && (msg.x <= 411) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 2;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'U';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 2;
			deleteReqs[deleteCount].kind = 'U';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 416) && (msg.x <= 461) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 2;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'D';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 2;
			deleteReqs[deleteCount].kind = 'D';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 485) && (msg.x <= 530) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 3;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'U';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 3;
			deleteReqs[deleteCount].kind = 'U';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 535) && (msg.x <= 580) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 3;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'D';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 3;
			deleteReqs[deleteCount].kind = 'D';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
   if ((msg.x >= 596) && (msg.x <= 641) &&
		(msg.y >= 186) && (msg.y <= 231)){
	   if ((msg.is_left()) && (!flag.is_left())){
		   theReqs[reqCount].floor = 4;
		   theReqs[reqCount].Number = 20 * timeCount + reqCount;
		   theReqs[reqCount++].kind = 'U';
	   }
	   else if ((msg.is_right()) && (!flag.is_right())){
		   deleteReqs[deleteCount].floor = 4;
		   deleteReqs[deleteCount].kind = 'U';
		   deleteReqs[deleteCount++].Number = 0;
	   }
	}
	if ((msg.x >= 640) && (msg.x <= 685) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 4;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'D';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 4;
			deleteReqs[deleteCount].kind = 'D';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 717) && (msg.x <= 762) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 5;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'U';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 5;
			deleteReqs[deleteCount].kind = 'U';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 767) && (msg.x <= 812) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 5;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'D';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 5;
			deleteReqs[deleteCount].kind = 'D';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 830) && (msg.x <= 875) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 6;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'U';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 6;
			deleteReqs[deleteCount].kind = 'U';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 880) && (msg.x <= 925) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 6;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'D';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 6;
			deleteReqs[deleteCount].kind = 'D';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 943) && (msg.x <= 988) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 7;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'U';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 7;
			deleteReqs[deleteCount].kind = 'U';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 993) && (msg.x <= 1038) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 7;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'D';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 7;
			deleteReqs[deleteCount].kind = 'D';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 1055) && (msg.x <= 1100) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 8;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'U';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 8;
			deleteReqs[deleteCount].kind = 'U';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 1105) && (msg.x <= 1150) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 8;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'D';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 8;
			deleteReqs[deleteCount].kind = 'D';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	if ((msg.x >= 1219) && (msg.x <= 1264) &&
		(msg.y >= 186) && (msg.y <= 231)){
		if ((msg.is_left()) && (!flag.is_left())){
			theReqs[reqCount].floor = 9;
			theReqs[reqCount].Number = 20 * timeCount + reqCount;
			theReqs[reqCount++].kind = 'D';
		}
		else if ((msg.is_right()) && (!flag.is_right())){
			deleteReqs[deleteCount].floor = 9;
			deleteReqs[deleteCount].kind = 'D';
			deleteReqs[deleteCount++].Number = 0;
		}
	}
	//开关门请求
	if ((msg.x >= 38) && (msg.x <= 98) &&
		(msg.y >= 486) && (msg.y <= 540) &&
		(msg.is_left()) && (!flag.is_left())){
		ocReqs[ocCount].floor = 0;
		ocReqs[ocCount].Number = 20 * timeCount + ocCount;
		ocReqs[ocCount++].kind = 'o';
	}
	if ((msg.x >= 116) && (msg.x <= 176) &&
		(msg.y >= 486) && (msg.y <= 546) &&
		(msg.is_left()) && (!flag.is_left())){
		ocReqs[ocCount].floor = 0;
		ocReqs[ocCount].Number = 20 * timeCount + ocCount;
		ocReqs[ocCount++].kind = 'c';
	}
	//处理策略转化
	if ((msg.x >= 38) && (msg.x <= 98) &&
		(msg.y >= 560) && (msg.y <= 620) &&
		(msg.is_left()) && (!flag.is_left())){
		elevator.type = 1;
	}
	if ((msg.x >= 115) && (msg.x <= 175) &&
		(msg.y >= 560) && (msg.y <= 620) &&
		(msg.is_left()) && (!flag.is_left())) elevator.type = 0;
	//处理一键还原
	if ((msg.x >= 960) && (msg.x <= 1020) &&
		(msg.y >= 565) && (msg.y <= 625) &&
		(msg.is_left()) && (!flag.is_left())){
		initElevator(&elevator, headp,broken);
	}
	//处理故障楼层
	if ((msg.x - 910)*(msg.x - 910) + (msg.y - 595)*(msg.y - 595) <= 900&&
		(msg.is_left()) && (!flag.is_left())){
		for (int i = 2; i <= 5; i++) broken[i] = false;
	}
	addServList(headp, theReqs, reqCount, &elevator,broken);
	deleteOperation(headp, deleteReqs, deleteCount);
	ocOperation(&elevator, ocReqs, ocCount);
	return;
}