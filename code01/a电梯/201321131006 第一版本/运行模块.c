#include "types.h"
static void FindState(ELEVATORPTR elePtr,struct REQ Rq)    //������������ѡ�����ʵ������ ��������͵��ݵ�״̬
{                                                          //�Ե��ݵ�״̬�����ı�
    elePtr->aim=Rq.floor;
    if(elePtr->aim>elePtr->cur){                    //Ŀ��¥�Ӵ��ڵ�ǰ¥�� ����Ϊ����״̬ ����ʱ��
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
static void getReqFirst(ELEVATORPTR elePtr,LISTNODEPTR headPtr)   //�ȵ��ȷ������ �õ�����ĺ���
{
    LISTNODEPTR headp=headPtr;
    LISTNODEPTR temPtr;
    struct REQ Rq,mid;
    if(headp->nextPtr==NULL){                                     //��ʱ�Ѿ�û��������
        if(elePtr->state==DOORCLOSING) elePtr->state=IDLE;
        return ;
    }
    Rq.Number=-1;                                                  //���г�ʼ��
    while(headp->nextPtr!=NULL){                                   //������������ �ҵ�Numberֵ��С������
        if(Rq.Number==-1){                                         //-1��ʾ��ʼ״̬ ��ʱҪ��һ��ֵ ���ͷ�����ڵ�
            Rq=headp->req;
            temPtr=headp->nextPtr;
            headp->req=temPtr->req;
            headp->nextPtr=temPtr->nextPtr;
            free(temPtr);
            continue;
        }
        else if((headp->req).Number<Rq.Number){                   //�ҵ���һ����С�Ľڵ� ����Ҫ���ڵ��ֵ��Rq��ֵ���н���
                mid=Rq;
                Rq=headp->req;
                headp->req=mid;
        }
        headp=headp->nextPtr;
    }
    FindState(elePtr,Rq);                                         //�����������뵽�����ڲ�
    return ;
}
static void getReqConvenient(ELEVATORPTR elePtr,LISTNODEPTR headPtr)        //˳�������� �õ�����ĺ���
{
    LISTNODEPTR headp=headPtr;
    LISTNODEPTR temPtr;
    if(headp->nextPtr==NULL){
        if(elePtr->state==DOORCLOSING) elePtr->state=IDLE;//////
        return ;
    }
    struct REQ Rq,mid;

    if(elePtr->flag==UP){                                                   //����֮ǰ��״̬Ϊ����״̬
            Rq.floor=-1;//���г�ʼ��
            headp=headPtr;
            while(headp->nextPtr!=NULL){                                    //���������ҳ����ڵ�ǰ¥�����С����������ڲ�����
                if(((headp->req).kind=='U'||(headp->req).kind=='T')&&(headp->req).floor>=(elePtr->cur)){
                    if(Rq.floor==-1){                                       //�������״̬
                        Rq=headp->req;
                        temPtr=headp->nextPtr;
                        headp->req=temPtr->req;
                        headp->nextPtr=temPtr->nextPtr;
                        free(temPtr);
                        continue;
                    }
                    else if((headp->req).floor<Rq.floor){                   //�ҵ����Ž� ����
                        mid=Rq;
                        Rq=headp->req;
                        headp->req=mid;
                    }
                }
                headp=headp->nextPtr;
            }
            if(Rq.floor==-1){                                               //����ϴ�ִ��û���ҵ� ���ٴν��б��� �ҵ�
                headp=headPtr;                                              //���µ����������ڲ�����
                while(headp->nextPtr!=NULL){
                    if((headp->req).kind=='D'||(headp->req).kind=='T'){
                        if(Rq.floor==-1){                                   //�������״̬
                            Rq=headp->req;
                            temPtr=headp->nextPtr;
                            headp->req=temPtr->req;
                            headp->nextPtr=temPtr->nextPtr;
                            free(temPtr);
                            continue;
                        }
                        else if((headp->req).floor>Rq.floor){              //�ҵ����Ž� ����
                            mid=Rq;
                            Rq=headp->req;
                            headp->req=mid;
                        }
                    }
                    headp=headp->nextPtr;
                }
            }
            if(Rq.floor==-1){                                               //��һ��û�ҵ�������� �ٴα����ҵ� ���ϵ��������
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
    else if(elePtr->flag==DOWN){                                           //����֮ǰ����״̬Ϊ����״̬�����
            Rq.floor=-1;//���г�ʼ��
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
    else{      //flag ΪIDLE�����
        headp=headPtr;
        Rq=headp->req;
        temPtr=headp->nextPtr;
        headp->req=temPtr->req;
        headp->nextPtr=temPtr->nextPtr;
        free(temPtr);
    }
    FindState(elePtr,Rq);                                  //�������� ȷ�����ݵ�״̬
    return ;
}
void runService(ELEVATORPTR elePtr,LISTNODEPTR headp)       //���к���
{
    switch(elePtr->state)
    {
        case IDLE:
            switch(elePtr->type)                            //���ݵ��������Ĳ���״̬������ͬ��ѡ��
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

void ocOperation(ELEVATORPTR elePtr,struct REQ ocReqs[],int ocCount)           //�������ŵĺ���
{
    int i;
    for(i=0;i<ocCount;i++){
        //������ŵ����
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
        //�����ŵ����
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
