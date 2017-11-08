#include "types.h"
void addServList(LISTNODEPTR headp,struct REQ* theReqs,int reqCount,struct ELEVATOR elevator)
{
    LISTNODEPTR lastptr=headp,newptr;
    while(lastptr->nextPtr!=NULL){
        lastptr=lastptr->nextPtr;
    }
    int i;
    for(i=0;i<reqCount;i++)
    {
        newptr=(LISTNODEPTR)malloc(sizeof(LISTNODE));
        lastptr->nextPtr=newptr;
        lastptr->req=theReqs[i];
        lastptr=newptr;
    }
    lastptr->nextPtr=NULL;
    return ;
}
