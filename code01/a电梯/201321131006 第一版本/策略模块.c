#include "types.h"
//���������������Լ��������������������
void addServList(LISTNODEPTR headp,struct REQ theReqs[],int reqCount,ELEVATORPTR elePtr)
{
    LISTNODEPTR newptr;
    while(headp->nextPtr!=NULL) headp=headp->nextPtr;//�ҵ��������β�ڵ�
    int i,mid;
    for(i=0;i<reqCount;i++){//������������
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
    newptr=(LISTNODEPTR)malloc(sizeof(LISTNODE));//�����½ڵ㣬��������˳���������
        newptr->nextPtr=NULL;
        headp->nextPtr=newptr;
        headp->req=theReqs[i];
        headp=newptr;
    }
    return ;
}
