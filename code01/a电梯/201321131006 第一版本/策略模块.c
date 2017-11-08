#include "types.h"
//将电梯运行请求以及开关门请求放入链表中
void addServList(LISTNODEPTR headp,struct REQ theReqs[],int reqCount,ELEVATORPTR elePtr)
{
    LISTNODEPTR newptr;
    while(headp->nextPtr!=NULL) headp=headp->nextPtr;//找到该链表的尾节点
    int i,mid;
    for(i=0;i<reqCount;i++){//遍历请求数列
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
    newptr=(LISTNODEPTR)malloc(sizeof(LISTNODE));//创建新节点，将请求按照顺序加入链表
        newptr->nextPtr=NULL;
        headp->nextPtr=newptr;
        headp->req=theReqs[i];
        headp=newptr;
    }
    return ;
}
