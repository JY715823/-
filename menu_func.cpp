#include "head&func.h"


//绘制主界面
int draw_MenuAnimation(linkqueue* q, int frames, int preframes, int speed, const char* name,
	int width, int height)
{	//frames 表示总帧数，pre_frames表示需要预先加载的帧数,
	//speed表示帧率，name表示文件名，x和y表示图片左上角的点所在坐标
	//width和height与加载函数的x，y相同

	int time_speed = 1000 / speed;//计算想要控制的每一帧所需时间
	int current_frame = 0;//帧索引

	int frame_start;//表示每一帧开始绘制时的时间
	int	frame_time;//表示每一帧绘制实际所需时间

	while (true)
	{
		frame_start = clock();

		int x = 0;
		int y = 0;
		//接受鼠标消息
		if (true)
		{
			//获取鼠标信息	
			while (peekmessage(&msg))
			{
			}
			if (msg.message == WM_LBUTTONDOWN)
			{
				x = msg.x;
				y = msg.y;
			}
		}
		

		//绘制图像
		if (true)
		{
			cleardevice();
			IMAGE* animation = new IMAGE();
			*animation = dequeue(q);//保存出队帧
			if (q->head->next != NULL)
			{

				putimage(0, 0, animation);
			}
			delete animation;//将已经绘制好的图片资源释放掉
			animation = NULL;

			draw_MenuButton();//绘制按钮

			//帧索引改变
			current_frame = ++current_frame % frames;

			//加载背景图之后剩余的图片——每次循环绘制一帧，加载一帧
			thread load(load_FollowAnim, q, &current_frame, frames, preframes, name, width, height);
			load.detach();
		}


		//数据处理
		if (true)
		{
			//点击任意一个按钮后结束主界面绘制，跳转按钮对应界面
			if (x > 605 && x < 774 && y > 153 && y < 442 ||
				x > 577 && x < 807 && y > 464 && y < 606 ||
				x > 557 && x < 824 && y > 632 && y < 756 ||
				x > 2 && x < 281 && y > 578 && y < 750 ||
				x > 1080 && x < 1378 && y > 592 && y < 762)
			{
				return menu_Button(x, y);//返回点击的按钮
			}
		}


		//休眠快了的时间以控制帧率
		frame_time = clock() - frame_start;
		int temp = time_speed - frame_time;
		if (temp > 0)
		{
			Sleep(temp);
		}
	}
	Sleep(300);
}


//绘制主界面的按钮
void draw_MenuButton()
{	
	//绘制主菜单——“游戏标题”
	drawImg(805, 15, img[1]);

	setfillcolor(RGB(195,154,102));
	//绘制主菜单——“开始游戏”按钮
	fillroundrect(598, 146, 781, 449,10,10);
	putimage(605,153 ,img[2]);
	drawImg(605,153, img[3]);

	//绘制主菜单——“游戏设置”按钮
	fillroundrect(570, 457, 814, 613, 10, 10);
	putimage(577, 464, img[4]);
	drawImg(577, 464, img[5]);

	//绘制主菜单——“游戏说明”按钮
	fillroundrect(550, 625, 831, 763, 10, 10);
	putimage(557, 632, img[6]);
	drawImg(557, 632, img[7]);

	//绘制主菜单——“制作人员及更多”
	fillroundrect(5, 571, 298, 757, 10, 10);
	putimage(12, 578, img[8]);
	drawImg(12,578, img[9]);

	//绘制主菜单——“退出游戏”按钮
	fillroundrect(1063, 585, 1375, 769, 10, 10);
	putimage(1070, 592, img[10]);
	drawImg(1070, 592, img[11]);

	FlushBatchDraw();
}


//保存鼠标在主菜单点击的按钮
int menu_Button(int msg_x, int msg_y)
{
	if (in_Button(msg_x,msg_y,605,153,169,289))
	{//1进入游戏界面
		return 1;
	}	
	if (in_Button(msg_x, msg_y, 577,464,230,142))
	{//2进入游戏设置
		return 2;
	}	
	if (in_Button(msg_x, msg_y, 557,632,267,124))
	{//3进入游戏说明
		return 3;
	}	
	if (in_Button(msg_x, msg_y, 2,578,279,172))
	{//4进入开发人员及更多
		return 4;
	}	
	if (in_Button(msg_x, msg_y, 1080,592,298,170))
	{//5退出游戏
		return 5;
	}

	return  0;
}



