#include "types.h"
#include "运行模块.h"
//将电梯运行请求以及开关门请求放入链表中
void addServList(LISTNODEPTR headp,struct REQ theReqs[],int reqCount,ELEVATORPTR elePtr,bool broken[])
{
    LISTNODEPTR newptr;
    while(headp->nextPtr!=NULL) headp=headp->nextPtr;//找到该链表的尾节点
    int i,mid;
    for(i=0;i<reqCount;i++){//遍历请求数列
		if (!broken[theReqs[i].floor]) continue;
        if(elePtr->type==0){//顺便服务策略
            if(elePtr->state==UP&&
                theReqs[i].floor>(elePtr->cur+1)&&
                theReqs[i].floor<elePtr->aim&&
                theReqs[i].kind!='D'){//如果当前要加入到链表的请求在电梯运行的当前楼层与目标楼层之间且
                    mid=elePtr->aim;         //运行方向相同，则将该请求设置为目标楼层，并且将之前的目标楼层取出放入链表
                    elePtr->aim=theReqs[i].floor;//即将请求楼层与目标楼层交换（上行同理）
                    theReqs[i].floor=mid;
                }
            else if(elePtr->state==DOWN&&
                    theReqs[i].floor<(elePtr->cur-1)&&
                    theReqs[i].floor>elePtr->aim&&
                    theReqs[i].kind!='U'){
                mid=elePtr->aim;
                elePtr->aim=theReqs[i].floor;
                theReqs[i].floor=mid;
                }
        }
        if(theReqs[i].floor==elePtr->cur){
            if(theReqs[i].floor==elePtr->cur&&
               elePtr->state==DOORCLOSING&&
               (elePtr->aim==-1||elePtr->aim>elePtr->cur)&&
               theReqs[i].kind=='U'){
                    elePtr->state=DOOROPENING;
                    elePtr->stime=To-(elePtr->stime)-2;
                    continue;
               }
            else if(theReqs[i].floor==elePtr->cur&&
                    elePtr->state==DOORCLOSING&&
                    (elePtr->aim==-1||elePtr->aim<elePtr->cur)&&
                    theReqs[i].kind=='D'){
                        elePtr->state=DOOROPENING;
                        elePtr->stime=To-(elePtr->stime)-2;
                        continue;
                    }
        }
    newptr=(LISTNODEPTR)malloc(sizeof(LISTNODE));//创建新节点，将请求按照顺序加入链表
        newptr->nextPtr=NULL;
        headp->nextPtr=newptr;
        headp->req=theReqs[i];
        headp=newptr;
    }
    return ;
}
void deleteOperation(LISTNODEPTR headp, struct REQ deleteReqs[], int deleteCount)
{
	int i;
	LISTNODEPTR midPtr = headp;
	for (i = 0; i < deleteCount; i++){
		midPtr = headp;
		while (midPtr->nextPtr != NULL){
			if (deleteReqs[i].floor == midPtr->req.floor&&
				deleteReqs[i].kind == midPtr->req.kind) Free(midPtr);
			else midPtr = midPtr->nextPtr;
		}
	}
	return;
}
void ocOperation(ELEVATORPTR elePtr, struct REQ ocReqs[], int ocCount)           //处理开关门的函数
{
	int i;
	for (i = 0; i<ocCount; i++){
		//处理关门的情况
		if (ocReqs[i].kind == 'c'){
			if (elePtr->state == DOOROPENING){
				elePtr->state = DOORCLOSING;
				elePtr->stime = Tc - (elePtr->stime) - 2;
			}
			else if (elePtr->state == STOP){
				elePtr->state = DOORCLOSING;
				elePtr->stime = 0;
			}
		}
		//处理开门的情况
		else{
			if (elePtr->state == IDLE){
				elePtr->state = DOOROPENING;
				elePtr->stime = 0;
			}
			else if (elePtr->state == DOORCLOSING){
				elePtr->state = DOOROPENING;
				elePtr->stime = To - (elePtr->stime) - 2;
			}
		}
	}
	return;
}