#include "types.h"
void get_fileInput(FILE* fpin,struct REQ theReqs[],struct REQ ocReqs[],struct REQ *chReq,int *reqCount,int *ocCount)
{
    int res=0,i,j,time;
    int reqN=0,ocN=0;
    fscanf(fpin,"T=%d,CallF=",&time);       //�����ļ������ʱ��
    char a[100];
    fgets(a,100,fpin);                      //��֮���һ�ж������飬����������
    for(i=0;i<strlen(a);i++){
        if(a[i]>='1'&&a[i]<='9'){           //������������
            theReqs[reqN].floor=a[i]-'0';
            for(j=1;(a[i+j]>='1'&&a[i+j]<='9');j++) theReqs[reqN].floor=(a[i]-'0')+10*theReqs[reqN].floor;
            theReqs[reqN].kind=a[i+j];
            theReqs[reqN].Number=20*time+i;//��Ǹ���������
            i=i+j;
            reqN++;
        }
        else if(a[i]=='0'){                 //������������
            ocReqs[ocN].floor=0;
            ocReqs[ocN].Number=20*time+i;
            ocReqs[ocN].kind=a[i+1];
            i++;
            ocN++;
        }
        //�������ת������
        else if(a[i]=='a'){//ת��Ϊ˳�����
            chReq->Number=20*time;
            chReq->floor=0;
        }
        else if(a[i]=='b'){//ת��Ϊ�����ȷ������
            chReq->Number=20*time;
            chReq->floor=-1;
        }
    }
    *reqCount=reqN;
    *ocCount=ocN;
    return ;
}
