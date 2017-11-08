#include "types.h"
static void FindState(ELEVATORPTR elePtr,struct REQ Rq)    //当从链表中挑选出合适的请求后 根据请求和电梯的状态
{                                                          //对电梯的状态做出改变
    elePtr->aim=Rq.floor;
    if(elePtr->aim>elePtr->cur){                    //目标楼从大于当前楼层 设置为上升状态 重置时间
        elePtr->runtime=0;
        elePtr->state=UP;
        elePtr->flag=UP;
    }
    else if(elePtr->aim<elePtr->cur){
        elePtr->runtime=0;
        elePtr->state=DOWN;
        elePtr->flag=DOWN;
    }
    else{
        elePtr->state=DOOROPENING;
        elePtr->stime=0;
    }
    return ;
}
static void getReqFirst(ELEVATORPTR elePtr,LISTNODEPTR headPtr)   //先到先服务策略 得到请求的函数
{
    LISTNODEPTR headp=headPtr;
    LISTNODEPTR temPtr;
    struct REQ Rq,mid;
    if(headp->nextPtr==NULL){                                     //此时已经没有请求了
        if(elePtr->state==DOORCLOSING) elePtr->state=IDLE;
        return ;
    }
    Rq.Number=-1;                                                  //进行初始化
    while(headp->nextPtr!=NULL){                                   //遍历整个链表 找到Number值最小的请求
        if(Rq.Number==-1){                                         //-1表示初始状态 此时要附一个值 并释放这个节点
            Rq=headp->req;
            temPtr=headp->nextPtr;
            headp->req=temPtr->req;
            headp->nextPtr=temPtr->nextPtr;
            free(temPtr);
            continue;
        }
        else if((headp->req).Number<Rq.Number){                   //找到了一个更小的节点 所以要将节点的值和Rq的值进行交换
                mid=Rq;
                Rq=headp->req;
                headp->req=mid;
        }
        headp=headp->nextPtr;
    }
    FindState(elePtr,Rq);                                         //将这个请求读入到电梯内部
    return ;
}
static void getReqConvenient(ELEVATORPTR elePtr,LISTNODEPTR headPtr)        //顺便服务策略 得到请求的函数
{
    LISTNODEPTR headp=headPtr;
    LISTNODEPTR temPtr;
    if(headp->nextPtr==NULL){
        if(elePtr->state==DOORCLOSING) elePtr->state=IDLE;//////
        return ;
    }
    struct REQ Rq,mid;

    if(elePtr->flag==UP){                                                   //电梯之前的状态为上升状态
            Rq.floor=-1;//进行初始化
            headp=headPtr;
            while(headp->nextPtr!=NULL){                                    //遍历链表找出大于当前楼层的最小上升请求或内部请求
                if(((headp->req).kind=='U'||(headp->req).kind=='T')&&(headp->req).floor>=(elePtr->cur)){
                    if(Rq.floor==-1){                                       //处理最初状态
                        Rq=headp->req;
                        temPtr=headp->nextPtr;
                        headp->req=temPtr->req;
                        headp->nextPtr=temPtr->nextPtr;
                        free(temPtr);
                        continue;
                    }
                    else if((headp->req).floor<Rq.floor){                   //找到更优解 交换
                        mid=Rq;
                        Rq=headp->req;
                        headp->req=mid;
                    }
                }
                headp=headp->nextPtr;
            }
            if(Rq.floor==-1){                                               //如果上次执行没有找到 则再次进行遍历 找到
                headp=headPtr;                                              //向下的最高请求或内部请求
                while(headp->nextPtr!=NULL){
                    if((headp->req).kind=='D'||(headp->req).kind=='T'){
                        if(Rq.floor==-1){                                   //处理最初状态
                            Rq=headp->req;
                            temPtr=headp->nextPtr;
                            headp->req=temPtr->req;
                            headp->nextPtr=temPtr->nextPtr;
                            free(temPtr);
                            continue;
                        }
                        else if((headp->req).floor>Rq.floor){              //找到更优解 交换
                            mid=Rq;
                            Rq=headp->req;
                            headp->req=mid;
                        }
                    }
                    headp=headp->nextPtr;
                }
            }
            if(Rq.floor==-1){                                               //上一步没找到的情况下 再次遍历找到 向上的最低请求
                headp=headPtr;
                while(headp->nextPtr!=NULL){
                    if((headp->req).kind=='U'||(headp->req).kind=='T'){
                        if(Rq.floor==-1){
                            Rq=headp->req;
                            temPtr=headp->nextPtr;
                            headp->req=temPtr->req;
                            headp->nextPtr=temPtr->nextPtr;
                            free(temPtr);
                            continue;
                        }
                        else if((headp->req).floor>Rq.floor){
                            mid=Rq;
                            Rq=headp->req;
                            headp->req=mid;
                        }
                    }
                    headp=headp->nextPtr;
                }
            }
    }
    else if(elePtr->flag==DOWN){                                           //处理之前运行状态为向下状态的情况
            Rq.floor=-1;//进行初始化
            headp=headPtr;
            while(headp->nextPtr!=NULL){
                if(((headp->req).kind=='D'||(headp->req).kind=='T')&&(headp->req).floor<=(elePtr->cur)){
                    if(Rq.floor==-1){
                        Rq=headp->req;
                        temPtr=headp->nextPtr;
                        headp->req=temPtr->req;
                        headp->nextPtr=temPtr->nextPtr;
                        free(temPtr);
                        continue;
                    }
                    else if((headp->req).floor>Rq.floor){
                        mid=Rq;
                        Rq=headp->req;
                        headp->req=mid;
                    }
                }
                headp=headp->nextPtr;
            }
            if(Rq.floor==-1){
                headp=headPtr;
                while(headp->nextPtr!=NULL){
                    if((headp->req).kind=='U'||(headp->req).kind=='T'){
                        if(Rq.floor==-1){
                            Rq=headp->req;
                            temPtr=headp->nextPtr;
                            headp->req=temPtr->req;
                            headp->nextPtr=temPtr->nextPtr;
                            free(temPtr);
                            continue;
                        }
                        else if((headp->req).floor<Rq.floor){
                            mid=Rq;
                            Rq=headp->req;
                            headp->req=mid;
                        }
                    }
                    headp=headp->nextPtr;
                }
            }
            if(Rq.floor==-1){
                headp=headPtr;
                while(headp->nextPtr!=NULL){
                    if((headp->req).kind=='D'||(headp->req).kind=='T'){
                        if(Rq.floor==-1){
                            Rq=headp->req;
                            temPtr=headp->nextPtr;
                            headp->req=temPtr->req;
                            headp->nextPtr=temPtr->nextPtr;
                            free(temPtr);
                            continue;
                        }
                        else if((headp->req).floor>Rq.floor){
                            mid=Rq;
                            Rq=headp->req;
                            headp->req=mid;
                        }
                    }
                    headp=headp->nextPtr;
                }
            }
    }
    else{      //flag 为IDLE的情况
        headp=headPtr;
        Rq=headp->req;
        temPtr=headp->nextPtr;
        headp->req=temPtr->req;
        headp->nextPtr=temPtr->nextPtr;
        free(temPtr);
    }
    FindState(elePtr,Rq);                                  //根据请求 确定电梯的状态
    return ;
}
void runService(ELEVATORPTR elePtr,LISTNODEPTR headp)       //运行函数
{
    switch(elePtr->state)
    {
        case IDLE:
            switch(elePtr->type)                            //根据电梯所处的策略状态做出不同的选择
            {
                case 0:getReqConvenient(elePtr,headp);break;
                case 1:getReqFirst(elePtr,headp);break;
            }
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
                switch(elePtr->type)
                {
                    case 0:getReqConvenient(elePtr,headp);break;
                    case 1:getReqFirst(elePtr,headp);break;
                }
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

void ocOperation(ELEVATORPTR elePtr,struct REQ ocReqs[],int ocCount)           //处理开关门的函数
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
