/*��ʼ������״̬*/
#include "types.h"
void initElevator(ELEVATORPTR ePtr)
{
     ePtr->state=IDLE;
     ePtr->cur=1;
     ePtr->aim=-1;
     ePtr->stime=0;
     ePtr->runtime=0;
     ePtr->flag=IDLE;
     ePtr->type=1;
     return ;
}
/*�ж�input�ļ��Ƿ����*/
int isEnd_fileInput(FILE *fpin)
{
    if(feof(fpin)) return 1;
    return 0;
}
/*��input�ļ��Ƿ�ɹ����ж�*/
int openFileToRead(char *fileName,FILE **fpin)
{
    if((*fpin=fopen(fileName,"r"))!=NULL) return 1;
    return 0;
}

/*��output�ļ��Ƿ�ɹ����ж�*/
int openFileToWrite(char *fileName,FILE **fpout)
{
    if((*fpout=fopen(fileName,"w"))!=NULL) return 1;
    return 0;
}
