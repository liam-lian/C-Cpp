#include "types.h"
void get_fileInput(FILE* fpin,struct REQ theReqs[],struct REQ ocReqs[],struct REQ *chReq,int *reqCount,int *ocCount)
{
    int res=0,i,j,time;
    int reqN=0,ocN=0;
    fscanf(fpin,"T=%d,CallF=",&time);       //处理文件输入的时间
    char a[100];
    fgets(a,100,fpin);                      //将之后的一行读进数组，在慢慢处理
    for(i=0;i<strlen(a);i++){
        if(a[i]>='1'&&a[i]<='9'){           //处理正常请求
            theReqs[reqN].floor=a[i]-'0';
            for(j=1;(a[i+j]>='1'&&a[i+j]<='9');j++) theReqs[reqN].floor=(a[i]-'0')+10*theReqs[reqN].floor;
            theReqs[reqN].kind=a[i+j];
            theReqs[reqN].Number=20*time+i;//标记该请求的序号
            i=i+j;
            reqN++;
        }
        else if(a[i]=='0'){                 //处理开关门请求
            ocReqs[ocN].floor=0;
            ocReqs[ocN].Number=20*time+i;
            ocReqs[ocN].kind=a[i+1];
            i++;
            ocN++;
        }
        //处理策略转换请求
        else if(a[i]=='a'){//转变为顺便服务
            chReq->Number=20*time;
            chReq->floor=0;
        }
        else if(a[i]=='b'){//转变为先来先服务服务
            chReq->Number=20*time;
            chReq->floor=-1;
        }
    }
    *reqCount=reqN;
    *ocCount=ocN;
    return ;
}
