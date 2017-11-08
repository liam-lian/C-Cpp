#include "types.h"
static void getReq(ELEVATORPTR elePtr,LISTNODEPTR *ePtr)
{
    LISTNODEPTR headp=(*ePtr);
    LISTNODEPTR temPtr=headp;
    if(headp->nextPtr==NULL){
        if(elePtr->state==DOORCLOSING) elePtr->state=IDLE;
        return ;
    }
    struct REQ Rq;
    Rq=headp->req;
    elePtr->aim=Rq.floor;
    if(elePtr->aim>elePtr->cur){
        elePtr->runtime=0;
        elePtr->state=UP;
    }
    else if(elePtr->aim<elePtr->cur){
        elePtr->runtime=0;
        elePtr->state=DOWN;
    }
    else{
        elePtr->state=DOOROPENING;
        elePtr->stime=0;
    }
    free(temPtr);
    headp=headp->nextPtr;
    *ePtr=headp;
    return ;
}
void runService(ELEVATORPTR elePtr,LISTNODEPTR *headp)
{
    switch(elePtr->state)
    {
        case IDLE:
            getReq(elePtr,headp);
            break;
        case DOOROPENING:
            elePtr->stime++;
            if(elePtr->stime>=To){
                elePtr->stime=0;
                elePtr->state=STOP;
            }break;
        case STOP:
            elePtr->stime++;
            if(elePtr->stime>=Ts){
                elePtr->stime=0;
                elePtr->state=DOORCLOSING;
            }break;
        case DOORCLOSING:
            elePtr->stime++;
            if(elePtr->stime>=Tc){
                getReq(elePtr,headp);
            }break;
        case UP:
            elePtr->runtime++;
            if(elePtr->runtime==Tu){
                elePtr->cur++;
                elePtr->runtime=0;
                if(elePtr->cur==elePtr->aim){
                    elePtr->state=DOOROPENING;
                    elePtr->stime=0;
                }
            }break;
        case DOWN:
            elePtr->runtime++;
            if(elePtr->runtime==Td){
                elePtr->cur--;
                elePtr->runtime=0;
                if(elePtr->cur==elePtr->aim){
                    elePtr->state=DOOROPENING;
                    elePtr->stime=0;
                }
            }break;
    }
    return ;
}

void ocOperation(ELEVATORPTR elePtr,struct REQ ocReqs[],int ocCount)
{
    int i;
    for(i=0;i<ocCount;i++){
        //处理关门的情况
        if(ocReqs[i].kind=='c'){
            if(elePtr->state==DOOROPENING){
                elePtr->state=DOORCLOSING;
                elePtr->stime=Tc-(elePtr->stime)-2;
            }
            else if(elePtr->state==STOP){
                elePtr->state=DOORCLOSING;
                elePtr->stime=0;
            }
        }
        //处理开门的情况
        else{
            if(elePtr->state==IDLE){
                elePtr->state=DOOROPENING;
                elePtr->stime=0;
            }
            else if(elePtr->state==DOORCLOSING){
                elePtr->state=DOOROPENING;
                elePtr->stime=To-(elePtr->stime)-2;
            }
        }
    }
    return ;
}
