#include "head&func.h"
 
 
//绘制游戏说明界面
void game_Instruction()
{
	while (true)
	{
		//接收消息
		int x = 0;
		int y = 0;
		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				x = msg.x;
				y = msg.y;
			}
		}

		//绘制
		cleardevice();
		setfillcolor(RGB(195, 154, 102));

		putimage(0, 0, img[35]);//背景图
		drawImg(0, 0, img[36]);//游戏说明文字

		fillroundrect(1154, 642, 1333, 751, 10, 10);
		putimage(1161, 649, img[25]);//返回主界面
		drawImg(1161, 649, img[26]);//退出主界面文字
		FlushBatchDraw();

		//数据处理
		if (in_Button(x, y, 1161, 649, 165, 95))
		{//返回主界面
			Sleep(1000);
			return;
		}
	}
}

//绘制制作人员及更多界面
void game_Addition()
{
	while (true)
	{
		//接收消息
		int x = 0;
		int y = 0;
		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				x = msg.x;
				y = msg.y;
			}
		}

		//绘制
		cleardevice();
		setfillcolor(RGB(195, 154, 102));

		putimage(0, 0, img[37]);//背景图

		drawImg(0, 0, img[38]);//制作人员文字图
		//drawImg(0, 0, img[39]);//更多内容文字图
		
		fillroundrect(1154, 642, 1333, 751, 10, 10);
		putimage(1161, 649, img[25]);//返回主界面
		drawImg(1161, 649, img[26]);//退出主界面文字

		FlushBatchDraw();

		//数据处理
		if (in_Button(x, y, 1161, 649, 165, 95))
		{//返回主界面
			Sleep(1000);
			return;
		}
	}
}

