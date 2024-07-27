#include "head&func.h"

//在主函数定义所有关键的变量，在头文件中声明，实现在所有文件里使用这些变量

#define COL 15//棋盘的列数
#define ROW 15//棋盘的行数
#define SPACE 30//棋盘离边缘的距离

chess board[ROW][COL] = { 0 };//把棋盘中的所有棋子保存在一个二维数组之中

ExMessage msg = { 0 };//定义消息结构体变量（五子棋小游戏只需接受鼠标信息）

stack s;//用于存棋的辅助栈

thread threads[18];//用于加载动画资源的线程数组

linkqueue* queue[30];//用于绘制动画的辅助队列

IMAGE* img[51];//用于加载图片资源的数组

//播放音乐相关变量
int current_music;//当前播放的音乐,初始值为4播放入场动画的音乐
bool is_playmusic = true;//判断是否播放音乐
bool control_single = true;//控制不重复播放音乐

//人物相关的变量
role roles[18];
player player1, player2;
int playercount = 0;//记录选择人物的数量，默认第一个选的是玩家一（黑子）
//当到达两个时即选好人物，退出到游戏设置界面
int member1 = 0, member2 = 0;//两个玩家的人物对应编号

//-------------------------------------------------------------------------------------------


int main()
{
	//进入主菜单前的准备
	if (true)
	{
		//将辅助的队列初始化
		for (int i = 0; i < 30; i++)
		{
			queue[i] = new linkqueue();
			queue[i]->head = queue[i]->rear = new animQnode();
			if (queue[i]->head == NULL)
			{
				printf("内存分配失败\n");
				continue;
			}
			queue[i]->head->next = NULL;
		}

		//加载初始资源
		load_Resource();


		//打开图形界面
		initgraph(1383, 780);
		Sleep(1000);//等待加载资源


		//双缓冲绘图开始
		BeginBatchDraw();

		//绘制加载动画
		draw_Animation(queue[1], 385, 30, 60, "加载动画", 0, 0, 1382, 777);

		IMAGE* temp = new IMAGE();
		loadimage(temp, "assets/开始部分/加载动画/序列 0384.jpg", 1382, 777);
		//点击进入入场动画
		while (true)
		{
			//将加载动画1的最后一帧停留，直到鼠标点击开始游戏区域播放加载动画2
			cleardevice();
			putimage(0, 0, temp);
			FlushBatchDraw();

			//获取消息
			while (peekmessage(&msg))
			{
			}
			int x = 0;
			int y = 0;
			//判断按键消息
			if (msg.message == WM_LBUTTONDOWN)
			{//左击鼠标时进入
				x = msg.x;
				y = msg.y;
				if (in_Button(x, y, 543, 639, 827 - 543, 705 - 639))
				{
					//绘制点击开始游戏过后的动画
					draw_Animation(queue[3], 80, 10, 15, "加载动画2", 0, 0, 1382, 777);

					//将加载动画2最后一帧停留至入场动画开始
					IMAGE* temp2 = new IMAGE();
					loadimage(temp2, "assets/开始部分/加载动画2/序列 0079.jpg", 1382, 777);
					cleardevice();
					putimage(0, 0, temp2);
					FlushBatchDraw();
					delete temp2;
					temp2 = NULL;

					Sleep(1500);
					break;
				}
			}
		}
		delete temp;
		temp = NULL;
		//释放不再需要的队列的内存
		free_Queue(queue[1]);
		free_Queue(queue[3]);


		//绘制进入游戏动画
		cleardevice();
		draw_EnterAnimation(queue[2], 7051, 100, 30, "入场动画", 0, 0, 1382, 777);
		mciSendString("close assets/背景音乐/bgm0.mp3", NULL, 0, NULL);//退出入场动画后暂停入场动画音频
		free_Queue(queue[2]);//释放掉入场动画的队列的内存


		//将两名玩家初始化——默认玩家一为漩涡鸣人，玩家二为宇智波佐助
		player1.color = 'b';
		player1.chara = roles[6];
		player2.color = 'w';
		player2.chara = roles[7];
	}



	bool end = false;//判断是否退出的标志
	//进入游戏主界面
	while (!end)
	{
		if (control_single)
		{
			current_music = 1;//默认从第一首bgm开始
			play_Music();
			is_playmusic = true;
			control_single = false;//防止重复播放
		}

		cleardevice();

		//进入主界面
		int choice = draw_MenuAnimation(queue[5], 167, 15, 30, "主界面壁纸", 1382, 775);

		//根据不同的choice进入不同的界面
		switch (choice)
		{
		case 1:
			init_Stack();//初始化辅助的栈
			Sleep(300);
			game_View(queue[4], 519, 20, 30, "游戏背景", 1382, 777);
			delete s;
			s = NULL;
			break;
		case 2:
			Sleep(500);
			game_Setting();
			break;
		case 3:
			Sleep(500);
			game_Instruction();
			break;
		case 4:
			Sleep(500);
			game_Addition();
			break;
		case 5:
			Sleep(500);
			end = true;
			break;
		}
	}
	
	//释放空间
	if (true)
	{
		for (int i = 0; i <= 30; i++)
		{
			free_Queue(queue[i]);
			delete queue[i];
			queue[i] = NULL;
		}
		for (int i = 0; i < 51; i++)
		{
			delete img[i];
			img[i] = NULL;
		}
		if (s != NULL)
		{
			delete s;
			s = NULL;
		}
	}


	EndBatchDraw();//结束双缓冲绘图
	closegraph();//关闭图形界面

	return 0;
}