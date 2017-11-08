#include "types.h"
#include "����ģ��.h"
//���������������Լ��������������������
void addServList(LISTNODEPTR headp,struct REQ theReqs[],int reqCount,ELEVATORPTR elePtr,bool broken[])
{
    LISTNODEPTR newptr;
    while(headp->nextPtr!=NULL) headp=headp->nextPtr;//�ҵ��������β�ڵ�
    int i,mid;
    for(i=0;i<reqCount;i++){//������������
		if (!broken[theReqs[i].floor]) continue;
        if(elePtr->type==0){//˳��������
            if(elePtr->state==UP&&
                theReqs[i].floor>(elePtr->cur+1)&&
                theReqs[i].floor<elePtr->aim&&
                theReqs[i].kind!='D'){//�����ǰҪ���뵽����������ڵ������еĵ�ǰ¥����Ŀ��¥��֮����
                    mid=elePtr->aim;         //���з�����ͬ���򽫸���������ΪĿ��¥�㣬���ҽ�֮ǰ��Ŀ��¥��ȡ����������
                    elePtr->aim=theReqs[i].floor;//��������¥����Ŀ��¥�㽻��������ͬ��
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
    newptr=(LISTNODEPTR)malloc(sizeof(LISTNODE));//�����½ڵ㣬��������˳���������
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
void ocOperation(ELEVATORPTR elePtr, struct REQ ocReqs[], int ocCount)           //�������ŵĺ���
{
	int i;
	for (i = 0; i<ocCount; i++){
		//������ŵ����
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
		//�����ŵ����
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