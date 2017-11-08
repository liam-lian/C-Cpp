/*�����ݵ�ǰ�������������������������һ�����ļ���ʽ�����һ���ı��ļ��в������״̬�������Ļ��*/
#include "types.h"
static void putState(struct ELEVATOR elevator,FILE *fpout)/*�����ǰ����״̬��fpout�ļ���*/
{
    switch(elevator.state){
        case IDLE:          fprintf(fpout,"State=       IDLE,");break;
        case DOOROPENING:   fprintf(fpout,"State=DOOROPENING,");break;
        case STOP:          fprintf(fpout,"State=       STOP,");break;
        case DOORCLOSING:   fprintf(fpout,"State=DOORCLOSING,");break;
        case UP:            fprintf(fpout,"State=         UP,");break;
        case DOWN:          fprintf(fpout,"State=       DOWN,");break;
    }
    return ;
}
/*���������ݲ���������ļ���*/
void set_fileOutput(FILE *fpout,int timeCount,struct ELEVATOR elevator,LISTNODEPTR headp)
{
    fprintf(fpout,"T=%3d,",timeCount);                //�����ǰʱ��
    putState(elevator,fpout);                        //�����ǰ����״̬��fpout�ļ���
    if(elevator.state==UP){                         //��ǰ״̬Ϊ����
        fprintf(fpout,"NowF=%d+%d,",elevator.cur,elevator.runtime);
    }
    else if(elevator.state==DOWN){                   //��ǰ״̬Ϊ�½�
        fprintf(fpout,"NowF=%d-%d,",elevator.cur,elevator.runtime);
    }
    else{
        fprintf(fpout,"NowF=%d 0,",elevator.cur);
    }
    fprintf(fpout,"GoalF=%d,",elevator.aim);          //���Ŀ��¥��
    if(elevator.state==STOP)                          //��ǰ״̬Ϊͣ��
        fprintf(fpout,"StopT=%d,",elevator.stime);
    else
        fprintf(fpout,"StopT=0,");                    //��ǰ״̬��ͣ��
    fprintf(fpout,"waifF=");
    while(headp->nextPtr!=NULL){                     //�����������δ��Ӧ������
        fprintf(fpout,"%d%c ",headp->req.floor,headp->req.kind);
        headp=headp->nextPtr;
    }
    fprintf(fpout,"\n");
    return ;
}
/*��ǰ¥�㼰δ��Ӧ�����ͼ�λ����*/
void Output_requst(int n,struct ELEVATOR elevator,LISTNODEPTR headp)
{
     int k=1,b=1,g=1;//g��ǵ����ڲ�����k�����������b�����������
     LISTNODEPTR hp=headp;
     if(n==elevator.cur)    printf("%c\t* @ ",17);
     else                   printf("%c\t*   ",17);//��ӡ��ǰ¥���״̬�������¥��Ϊ��ǰ¥�㣬��@���
     while(headp!=NULL){                         //�����������Ƿ��е����ڲ�����
        if(headp->req.floor==n&&headp->req.kind=='T'&&g==1){
            g=0;
            printf("%d   %c%7d ",n,5,n);         //�����ڲ���������������������ڲ��ڸò���������////���
        }
        headp=headp->nextPtr;
      }
    if(g==1)          printf("%d %10d ",n,n);     //�����ڲ�����������
    headp=hp;
     while(headp!=NULL){                          //�����������Ƿ�����������
        if(headp->req.floor==n&&headp->req.kind=='U'&&k==1){
            k=0;
            printf(" %c",24);                      //����������������������//���
        }
        headp=headp->nextPtr;
     }
    if(k==1)    printf("  ");                      //������������������
    headp=hp;
     while(headp!=NULL){                           //�����������Ƿ�����������
        if(headp->req.floor==n&&headp->req.kind=='D'&&b==1){
            b=0;
            printf("  %c",25);                     //����������������������//���
        }
    headp=headp->nextPtr;
    }
    if(b==1)    printf("   ");                      //������������������
    printf("    *");
    return ;

}
/*������ݵ�ǰ״̬����Ļ��*/
void Output(int timeCount,struct ELEVATOR elevator,LISTNODEPTR headp)
{
     int i=1;                               //��ӡ�������û�����
     printf("%c",17);
     for(i=1;i<=77;i++)     printf("~");
     printf("%c\n",16);
     printf("%c",17);
     for(i=1;i<=24;i++)      printf(" ");
     printf("<<��ӭʹ�õ���ģ�����ϵͳ>>");
     for(i=1;i<=25;i++)      printf(" ");
     printf("%c\n",16);
      printf("%c",17);
     for(i=1;i<=77;i++)
      printf("~");
     printf("%c\n",16);

  //��ӡ���ݵ�����״̬
     printf("%c",17);
     printf("\t      %c%c������������%c%c\t\t\t\t\t              %c\n",40,40,41,41,16);
     printf("%c\t* * * * * * * * * * * * * *%44c\n",17,16);
     printf("%c\t*   �����ڲ�     �����ⲿ *%44c\n",17,16);
     Output_requst(9,elevator,headp);                         //��ǰ¥�㼰δ��Ӧ�����ͼ�λ����
     printf("\t          %c%c����״̬%c%c%17c\n",40,40,41,41,16);
     Output_requst(8,elevator,headp);
     printf("\t   * * * * * * * * * * * * * *%9c\n",16);
     Output_requst(7,elevator,headp);
     printf("\t   * ��ǰ״̬:");                                 //��ʾ���ݵĵ�ǰ״̬
     switch(elevator.state){
        case IDLE:          printf("����    ");break;
        case DOOROPENING:   printf("����    ");break;
        case STOP:          printf("ͣ��    ");break;
        case DOORCLOSING:   printf("����    ");break;
        case UP:            printf("��������");break;
        case DOWN:          printf("��������");break;
        }
     printf("       *%9c\n",16);
     Output_requst(6,elevator,headp);                           //��ʾ��ǰ¥���Ŀ��¥��
     printf("\t   * ��ǰ¥��:��%2d��         *%9c\n",elevator.cur,16);
     Output_requst(5,elevator,headp);
     printf("\t   * Ŀ��¥��:��%2d��         *%9c\n",elevator.aim,16);
     Output_requst(4,elevator,headp);
     printf("\t   * * * * * * * * * * * * * *%9c\n",16);   //��ǰ¥�㼰δ��Ӧ�����ͼ�λ����
     Output_requst(3,elevator,headp);                      //�û�����˵��
     printf("\tע����ͼ��@��ʾ���ݵ�ǰ����¥�㣻%6c\n",16);
     Output_requst(2,elevator,headp);
     printf("\t    ��ͼ��%c��ʾ��¥������ڲ�������%2c\n",5,16);
     Output_requst(1,elevator,headp);
     printf("\t    ��ͼ��%c��%c�ֱ��ʾ��¥����������%3c\n",24,25,16);
     printf("%c\t* * * * * * * * * * * * * *%11c����%27c\n",17,32,16);
     printf("%c",17);
     for(i=1;i<=4;i++)
        printf("~");
     printf(" ��ܰ��ʾ ");
     for(i=1;i<=63;i++)
        printf("~");
     printf("%c\n",16);
    //�û�������ʾ˵��
     printf("%c �������룺1 2 3 4 5 6 7 8 9����ʾ�������ڸ�¥��ʱ�ڲ�������   %13c\n",17,16);
     printf("%c �������룺A B C D E F G H ����ʾ��1~8¥�����ⲿ�ڸ�¥������������  %8c\n",17,16);
     printf("%c �������룺I J K L M N O P ����ʾ��2~9¥�����ⲿ�ڸ�¥������������   %7c\n",17,16);
     printf("%c �������룺o:��ʾ����,c:��ʾ����;a:��ʾ˳��������,b:��ʾ�����ȷ�����ԡ�");
     printf("%4c\n",16);
     printf("%c",17);
     for(i=1;i<=77;i++)     printf("~");
     printf("%c\n",16);
     printf("%c��ǰ����:",17);
     switch(elevator.type){
        case 0:printf("˳�����%21c",32);break;
        case 1:printf("�����ȷ���%19c",32);break;
     }
     printf("���������Ա����˼��&��״&֣��ϼ %7c\n",16);
     printf("%c",17);
     for(i=1;i<=77;i++)     printf("~");
     printf("%c\n",16);
}
