/*初始化电梯状态*/
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
/*判断input文件是否结束*/
int isEnd_fileInput(FILE *fpin)
{
    if(feof(fpin)) return 1;
    return 0;
}
/*打开input文件是否成功的判断*/
int openFileToRead(char *fileName,FILE **fpin)
{
    if((*fpin=fopen(fileName,"r"))!=NULL) return 1;
    return 0;
}

/*打开output文件是否成功的判断*/
int openFileToWrite(char *fileName,FILE **fpout)
{
    if((*fpout=fopen(fileName,"w"))!=NULL) return 1;
    return 0;
}
