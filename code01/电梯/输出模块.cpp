#include "types.h"

void output(struct ELEVATOR elevator, LISTNODEPTR headp,bool broken[])
{
	PIMAGE background;
	PIMAGE num_in_[10];
	PIMAGE num_broken[10];
	PIMAGE brokenFlag;
	PIMAGE Up, Down;
	PIMAGE door_left, door_right;
	PIMAGE F, C;
	PIMAGE flag; //表示电梯所处楼层

	background = newimage();//此处省略多个步骤
	for (int i = 1; i <= 9; i++) num_in_[i] = newimage();
	Up = newimage();
	Down = newimage();
	door_left = newimage();
	door_right = newimage();
	F = newimage();
	C = newimage();
	flag = newimage();

	getimage(background, "材料Final\\背景.bmp");//此处省略多个步骤
	getimage(num_in_[1], "材料Final\\1.bmp");
	getimage(num_in_[2], "材料Final\\2.bmp");
	getimage(num_in_[3], "材料Final\\3.bmp");
	getimage(num_in_[4], "材料Final\\4.bmp");
	getimage(num_in_[5], "材料Final\\5.bmp");
	getimage(num_in_[6], "材料Final\\6.bmp");
	getimage(num_in_[7], "材料Final\\7.bmp");
	getimage(num_in_[8], "材料Final\\8.bmp");
	getimage(num_in_[9], "材料Final\\9.bmp");
	getimage(Up, "材料Final\\up.bmp");
	getimage(Down, "材料Final\\down.bmp");
	getimage(door_left, "材料Final\\门左.bmp");
	getimage(door_right, "材料Final\\门右.bmp");
	getimage(flag, "材料Final\\气球.bmp");
	getimage(F, "材料Final\\先来先服务.bmp");
	getimage(C, "材料Final\\顺便服务.bmp");

	putimage(0, 0, background);
	//根据电梯信息打印图片
	if (elevator.state == UP) putimage(280 + (elevator.cur - 1) * 115 + elevator.runtime, 12, flag);
	else putimage(280 + (elevator.cur - 1) * 115 - elevator.runtime, 12, flag);

	if (elevator.type == 0) putimage(115, 558, C);
	else putimage(38, 558, F);

	if (elevator.state == DOORCLOSING){
		putimage(335 + elevator.stime, 380, door_left);
		putimage(660 - elevator.stime, 380, door_right);
	}
	else if (elevator.state == DOOROPENING){
		putimage(385 - elevator.stime, 380, door_left);
		putimage(610 + elevator.stime, 380, door_right);
	}
	else if(elevator.state==STOP){
		putimage(335, 380, door_left);
		putimage(660, 380, door_right);
	}
	else{
		putimage(385, 380, door_left);
		putimage(610, 380, door_right);
	}
	//打印所有的需求信息
	while (headp->nextPtr != NULL){
		REQ rq = headp->req;
		if (rq.kind == 'T'){
			switch (rq.floor)
			{
			case 1:
				putimage(38, 410, num_in_[1]); break;
			case 2:
				putimage(115, 362, num_in_[2]); break;
			case 3:
				putimage(38, 320, num_in_[3]); break;
			case 4:
				putimage(116, 278, num_in_[4]); break;
			case 5:
				putimage(38, 230, num_in_[5]); break;
			case 6:
				putimage(114, 185, num_in_[6]); break;
			case 7:
				putimage(38, 144, num_in_[7]); break;
			case 8:
				putimage(115, 96, num_in_[8]); break;
			case 9:
				putimage(38, 49, num_in_[9]); break;
			}
		}
		else{
			switch (rq.floor)
			{
				case 1:
					putimage(248, 186, Up); break;
				case 2:
					if (rq.kind == 'U')putimage(366, 186, Up);
					else putimage(416, 185, Down); break;
				case 3:
					if (rq.kind == 'U')putimage(485, 186, Up);
					else putimage(534, 185, Down); break;
				case 4:
					if (rq.kind == 'U')	putimage(596, 186, Up);
					else putimage(646, 185, Down); break;
				case 5:
					if (rq.kind == 'U')putimage(717, 186, Up);
					else putimage(767, 185, Down); break;
				case 6:
					if (rq.kind == 'U')putimage(830, 186, Up);
					else putimage(880, 185, Down); break;
				case 7:
					if (rq.kind == 'U')putimage(943, 186, Up);
					else putimage(993, 185, Down); break;
				case 8:
					if (rq.kind == 'U')putimage(1055, 186, Up);
					else putimage(1105, 185, Down); break;
				case 9:
					putimage(1218, 185, Down); break;
			}
		}
		headp = headp->nextPtr;
	}
	
	//处理故障楼层
	for (int i = 1; i <= 9; i++) num_broken[i] = newimage();
	brokenFlag = newimage();
	getimage(num_broken[1], "材料Final\\broken_1.bmp");
	getimage(num_broken[2], "材料Final\\broken_2.bmp");
	getimage(num_broken[3], "材料Final\\broken_3.bmp");
	getimage(num_broken[4], "材料Final\\broken_4.bmp");
	getimage(num_broken[5], "材料Final\\broken_5.bmp");
	getimage(num_broken[6], "材料Final\\broken_6.bmp");
	getimage(num_broken[7], "材料Final\\broken_7.bmp");
	getimage(num_broken[8], "材料Final\\broken_8.bmp");
	getimage(num_broken[9], "材料Final\\broken_9.bmp");
	getimage(brokenFlag, "材料Final\\红.bmp");
	if (!broken[1]){ putimage(243, 74, num_broken[1]); }
	if (!broken[2]){ putimage(361, 74, num_broken[2]); }
	if (!broken[3]){ putimage(479, 74, num_broken[3]); }
	if (!broken[4]){ putimage(591, 74, num_broken[4]); }
	if (!broken[5]){ putimage(712, 74, num_broken[5]); }
	if (!broken[6]){ putimage(825, 74, num_broken[6]); }
	if (!broken[7]){ putimage(938, 74, num_broken[7]); }
	if (!broken[8]){ putimage(1050, 74, num_broken[8]); }
	if (!broken[9]){ putimage(1163, 74, num_broken[9]); }
	for (int i = 1; i <= 9; i++){
		if (!broken[i]){ putimage(879, 565, brokenFlag); break; }
	}

	for (int i = 1; i <= 9; i++) delimage(num_broken[i]);
	delimage(brokenFlag);

	delimage(background);
	for (int i = 1; i <= 9; i++) delimage(num_in_[i]);
	delimage(Up);
	delimage(Down);
	delimage(door_left);
	delimage(door_right);
	delimage(F);
	delimage(C);
	delimage(flag);
	return;
}