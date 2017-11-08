/*初始化电梯状态*/
#include "types.h"
#include "运行模块.h"
void initElevator(ELEVATORPTR ePtr, LISTNODEPTR headp, bool broken[])
{
     ePtr->state=IDLE;
     ePtr->cur=1;
     ePtr->aim=-1;
     ePtr->stime=0;
     ePtr->runtime=0;
     ePtr->tip=IDLE;
     ePtr->type=0;
	 while (headp->nextPtr != NULL) Free(headp);
	 for (int i = 0; i < 10; i++) broken[i] = true;
     return ;
}