#include "types.h"
#include "初始化及其他杂乱函数.h"
#include "输入模块.h"
#include "输出模块.h"
#include "策略模块.h"
#include "运行模块.h"
void fileinput(void)  {
    int timeCount=0;                        //计时器，每循环一次模拟2ms
    struct REQ theReqs[20];                 //暂存每次获得的某时刻的全部请求事件
    struct REQ ocReqs[20];
    int reqCount;                           //暂存每次获得的某时刻的请求事件总数
    int ocCount;
    enum STATE  preState,curState ;         // preState电梯前一状态，curState电梯当前状态
                       //存请求队列链表头指针
    FILE *fpin,*fpout,*fpout2;              //指向请求文件和输出文件File结构
    struct ELEVATOR elevator;               //存储电梯对象信息，包括电梯状态、所在楼层、停靠时间等等


	//根据文件名打开请求输入文件
    if(!openFileToRead("input.txt",&fpin)){
       printf("input file can't be opened\n");
       return 0;
    }

	//根据文件名打开输出文件3，当电梯状态有变化时就会往文件中输出
    if(!openFileToWrite("output.txt",&fpout)){
       printf("output file can't be opened\n");
       return 0;
    }
	//根据文件名打开输出文件2，定期往文件中输出电梯信息
   if(!openFileToWrite("outputDetail.txt",&fpout2)){//根据文件名打开输入输出文件
       printf("output file can't be opened\n");
       return 0;
    }
    //设置链表头节点。该头节点不实际存储请求。
    headp=(LISTNODEPTR)malloc(sizeof(LISTNODE));
    headp->nextPtr=NULL;

    //初始化电梯结构信息.电梯初始位于1层，为空闲状态。
    initElevator(&elevator);

    //开始模拟电梯运行
    get_fileInput(fpin,theReqs,ocReqs,&reqCount,&ocCount);  //读取第一个某时刻的所有请求到theReqs中

    while (!(isEnd_fileInput(fpin)&&elevator.state==IDLE)){ //当文件输入结束，且电梯空闲才终止程序
	  //1.处理输入请求
	  if (theReqs[0].time==timeCount||ocReqs[0].time==timeCount){                       //当请求时间到
		   addServList(headp,theReqs,reqCount,elevator);     //添加请求事件到服务队列中
		   ocOperation(&elevator,ocReqs,ocCount);            //处理所有的开关门请求
      	   get_fileInput(fpin,theReqs,ocReqs,&reqCount,&ocCount); //读取文件中下一时刻的全部请求事件
	   }
       //2.计算电梯状态
       preState= elevator.state;//记录前一状态
       runService(&elevator,&headp);//根据电梯当前状态计算下一状态
	   //3.输出电梯状态
	   //输出电梯状态信息到文件2中
	   set_fileOutput(fpout2,timeCount,elevator, headp);
	   if (elevator.state!=preState)
	 	   set_fileOutput(fpout,timeCount,elevator, headp);
	 	Output(timeCount,elevator,headp);
	      /*当状态变化，将当前时间、状态和等待队列的情况写入到文件中。  */
	   //4.时间片加1
	   timeCount++;
	   Sleep(1000);
		   //time_count(&timeCount);
	}

    //关闭输入输出文件
	fclose(fpin);
    fclose(fpout);
}
