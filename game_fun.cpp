#include "head&func.h"



//游戏界面
void game_View(linkqueue* q_back,int frames, int preframes, int speed, const char* name,
	int width, int height)
{	//frames 表示总帧数，pre_frames表示需要预先加载的帧数,
	//speed表示帧率，name表示文件名
	//width和height与加载函数的x，y相同
	
	srand((unsigned)time(NULL));//种下随机数种子，以便播放落子音效


	//找到两个玩家所选角色的序号
	for (int i = 6; i <= 17; i++)
	{
		if (strcmp(roles[i].name,player1.chara.name) == 0)
		{
			member1 = i;
		}

		if (strcmp(roles[i].name,player2.chara.name) == 0)
		{
			member2 = i;
		}
	}

	//提前加载两个玩家角色的奥义图
	thread load_LastImage1(load_LastPreimage, queue[member1 + 12], 10, player1.chara.name);
	load_LastImage1.detach();
	thread load_LastImage2(load_LastPreimage, queue[member2 + 12], 10, player2.chara.name);
	load_LastImage2.detach();
	Sleep(300);

	bool running = true;//判断是否胜利的标志
	int round = 0;//回合数，用于判断当前回合是哪个玩家下棋

	int time_speed = 1000 / speed;//计算想要控制的每一帧所需时间
	int current_frame1 = 0;//帧索引1(背景图）
	int current_frame2 = 0;//帧索引2（玩家一角色动画）
	int current_frame3 = 0;//帧索引3（玩家二角色动画）

	int frame_start;//表示每一帧开始绘制时的时间
	int	frame_time;//表示每一帧绘制实际所需时间

	//初始化棋盘
	init_Board();

	linkqueue* q_chara;//保存角色的动画的队列
	while (running)
	{
		frame_start = clock();

		int x = 0;
		int y = 0;
		
		//获取鼠标信息	
		if (true)
		{
			while (peekmessage(&msg))
			{
			}
			if (msg.message == WM_LBUTTONDOWN)
			{
				x = msg.x;
				y = msg.y;
				
			}
		}

		//数据处理
		if (true)
		{
			//落子
			if (x > 0 && x <= SPACE + 750 && y > 0 && y <= SPACE + 750)
			{
				drop_Chess(x, y, &round);
			}

			//是否悔棋
			if (in_Button(x, y, 784, 640, 170, 115))
			{
				Sleep(200);
				if (s->next != NULL)
				{
					chess reg_chess = pop();
					int xi = reg_chess.row_ind;
					int yi = reg_chess.col_ind;
					board[xi][yi].color = '-';//将棋子删掉
					round--;//返回上一回合
				}
			}

			//退出游戏设置界面，返回主界面
			if (in_Button(x, y, 1161, 649, 165, 95))
			{
				Sleep(2000);
				return;
			}

			//判断胜负
			char flag = is_Win();
			if (flag == 'b')
			{//黑棋赢了
				//播放胜利奥义图
				draw_WinChara(queue[member1 + 12], player1.chara.name);
				Sleep(2000);
				running = false;
			}
			else if (flag == 'w')
			{//白旗赢了
				//播放胜利奥义图
				draw_WinChara(queue[member2 + 12], player2.chara.name);
				Sleep(2000);
				running = false;
			}

			if (is_draw())
			{//判断平局
				putimage(184, 140, img[50]);
				Sleep(1500);
				running = false;
			}
		}

		//绘制图像
		if (true)
		{
			// 保存背景
			IMAGE* animation1 = new IMAGE();
			*animation1 = dequeue(q_back);//保存出队帧

			// 保存人物的序号
			int roleanim = 0;
			if (round % 2 + 1 == 1)
			{
				roleanim = member1;
			}
			if (round % 2 + 1 == 2)
			{
				roleanim = member2;
			}
			q_chara = queue[roleanim];
			IMAGE* animation2 = new IMAGE();
			*animation2 = dequeue(q_chara);//保存出队帧

			cleardevice();

			putimage(0, 0, animation1);//背景图

			draw_Board();//绘制棋盘
			draw_Chess();//绘制棋子

			setfillcolor(RGB(195, 154, 102));//设置按钮边框颜色

			fillroundrect(777, 633, 961, 762, 10, 10);//绘制按钮边框
			putimage(784, 640, img[43]);//悔棋
			drawImg(784, 640, img[44]);//悔棋文字

			fillroundrect(777, 36, 998, 167, 12, 12);
			putimage(784, 43, img[41]);//当前回合
			drawImg(784, 43, img[42]);//当前回合文字

			fillroundrect(1154, 642, 1333, 751, 10, 10);
			putimage(1161, 649, img[25]);//返回主界面
			drawImg(1161, 649, img[26]);//退出主界面文字

			putimage(784, 185, animation2);//人物图
			FlushBatchDraw();

			delete animation1;//将已经绘制好的图片资源释放掉
			animation1 = NULL;
			delete animation2;//将已经绘制好的图片资源释放掉
			animation2 = NULL;

			//异步加载之后的图片
			current_frame1 = ++current_frame1 % frames;
			thread load1(load_FollowAnim, queue[4], &current_frame1, 519, 20, "游戏背景", 1382, 777);
			load1.detach();

			if (round % 2 + 1 == 1)
			{
				current_frame2 = ++current_frame2 % frames;
				thread load2(load_FollowCharaAnim, queue[roleanim], &current_frame2, roles[roleanim].frames,
					roles[roleanim].preframes, roles[roleanim].name, roles[roleanim].width, roles[roleanim].height);
				load2.detach();
			}
			else
			{
				current_frame3 = ++current_frame3 % frames;
				thread load3(load_FollowCharaAnim, queue[roleanim], &current_frame3, roles[roleanim].frames,
					roles[roleanim].preframes, roles[roleanim].name, roles[roleanim].width, roles[roleanim].height);
				load3.detach();
			}
		}

		//休眠快了的时间以控制帧率
		frame_time = clock() - frame_start;
		int temp = time_speed - frame_time;
		if (temp > 0)
		{
			Sleep(temp);
		}
		if (!running)
		{
			Sleep(3000);
		}
	}

	//释放辅助栈的内存
	snode* p = s->next;
	while (p != NULL)
	{
		snode* outnode = p;
		p = p->next;
		delete outnode;
		outnode = NULL;
	}

	//延迟退出，以便加载完未加载的线程，避免出现错误
	Sleep(1000);
}


//--------------------------------------------------------------------------------------

//初始化棋盘
void init_Board()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j].color = '-';
		}
	}

}

//落子
void drop_Chess(int msg_x, int msg_y,int* round)
{	
	//找出棋子落点
	int center_x, center_y;
	if (true)
	{
		int x1 = ((msg_x - SPACE) / 50) * 50 + SPACE;
		int y1 = ((msg_y - SPACE) / 50) * 50 + SPACE;
		int x2 = x1 + 50;
		int y2 = y1 + 50;
		//计算鼠标点与一个格子中的四个顶点的距离的平方
		int dis[4];
		dis[0] = (msg_x - x1) * (msg_x - x1) + (msg_y - y1) * (msg_y - y1);//到（x1，y1）
		dis[1] = (msg_x - x1) * (msg_x - x1) + (msg_y - y2) * (msg_y - y2);//到（x1，y2）
		dis[2] = (msg_x - x2) * (msg_x - x2) + (msg_y - y1) * (msg_y - y1);//到（x2，y1）
		dis[3] = (msg_x - x2) * (msg_x - x2) + (msg_y - y2) * (msg_y - y2);//到（x2，y2）
		//找出距离最小的，该点就是要下的棋的圆心
		int dis_mini = 0;
		for (int i = 1; i < 4; i++)
		{
			if (dis[i] < dis[dis_mini])
			{
				dis_mini = i;
			}
		}

		switch (dis_mini)
		{
		case 0:
			center_x = (x1 - SPACE) / 50;
			center_y = (y1 - SPACE) / 50;
			break;
		case 1:
			center_x = (x1 - SPACE) / 50;
			center_y = (y2 - SPACE) / 50;
			break;
		case 2:
			center_x = (x2 - SPACE) / 50;
			center_y = (y1 - SPACE) / 50;
			break;
		case 3:
			center_x = (x2 - SPACE) / 50;
			center_y = (y2 - SPACE) / 50;
			break;
		default:
			break;
		}
	}


	//根据flag（回合数）落对应的棋子
	if (board[center_y][center_x].color == '-')
	{//当前点没有棋子，可以下
		if (*round % 2 + 1 == 1)
		{
			board[center_y][center_x].color = player1.color;
			board[center_y][center_x].row_ind = center_y;
			board[center_y][center_x].col_ind = center_x;
			//落子播放音效
			play_CharaVoice(player1.chara.name);
		}
		else
		{
			board[center_y][center_x].color = player2.color;
			board[center_y][center_x].row_ind = center_y;
			board[center_y][center_x].col_ind = center_x;
			//落子播放音效
			play_CharaVoice(player2.chara.name);
		}

		(*round)++;//回合数加一

		//将下的棋子入栈,以便进行悔棋和判断胜负
		push(board[center_y][center_x]);
	}
}

//落子播放人物音效
void play_CharaVoice(const char* name)
{
	int num = rand() % 5 + 1;

	char voice[50];
	memset(voice, '0', sizeof(voice));
	sprintf(voice, "assets/人物音效/%s音效%d.wav", name,num);
	PlaySound(voice, NULL, SND_FILENAME | SND_ASYNC);

}


//--------------------------------------------------------------------------------------

// 绘制棋盘
void draw_Board()
{
	//绘制棋盘背景图
	putimage(SPACE,SPACE,img[40]);
	//绘制棋盘线
	setlinecolor(BLACK);
	for (int i = 0; i < 15; i++)
	{
		line(SPACE, SPACE + i * 50, SPACE + 50 * (15 - 1), SPACE + i * 50);
		line(SPACE + i * 50, SPACE, SPACE + i * 50, SPACE + 50 * (15 - 1));
	}
	//绘制棋盘上的五个关键点
	int r = 5;
	setfillcolor(BLACK);
	solidcircle(30 + 50 * 3, 30 + 50 * 3, r);
	solidcircle(30 + 50 * 11, 30 + 50 * 3, r);
	solidcircle(30 + 50 * 3,30 + 50 * 11, r);
	solidcircle(30 + 50 * 11,30 + 50 * 11 , r);
	solidcircle(30 + 50 * 7,30 + 50 * 7 , r);
}

//绘制已经下了的棋子
void draw_Chess()
{
	//绘制棋子
	int x1, y1;
	for (int i = 0; i < 15; i++)
	{	
		y1 = SPACE + i * 50 ;
		for (int j = 0; j < 15; j++)
		{	
			x1 = SPACE + j * 50 ;
			
			//根据颜色绘制棋子
			if (board[i][j].color != '-')
			{
				if (board[i][j].color == 'b')
				{
					/*setfillcolor(BLACK);
					fillcircle(x1, y1, 25);*/
					//// 创建一个接近圆形形状的矩形剪切区域
					//HRGN hRgn = CreateRoundRectRgn(x1 - 23, y1 - 23, x1 + 23, y1 + 23, 46, 46);
					//setcliprgn(hRgn); // 将矩形剪切区域设置为当前绘图的剪切区域
					//// 在剪切区域内绘制棋子
					//putimage(x1 - 23, y1 - 23,img[member1 + 6]);
					//// 清除剪切区域
					//setcliprgn(NULL);

					setfillcolor(BLACK);
					fillcircle(x1, y1, 24);
					putimage(x1 - 18, y1 - 18, img[member1 + 6]);
				}
				
				else if (board[i][j].color == 'w')
				{
					//setfillcolor(WHITE);
					//fillcircle(x1, y1, 25);
					//// 创建一个接近圆形形状的矩形剪切区域
					//HRGN hRgn = CreateRoundRectRgn(x1 - 23, y1 - 23, x1 + 23, y1 + 23, 46, 46);
					//setcliprgn(hRgn); // 将矩形剪切区域设置为当前绘图的剪切区域
					//// 在剪切区域内绘制棋子
					//putimage(x1 - 23, y1 - 23, img[member2 + 6]);
					//// 清除剪切区域
					//setcliprgn(NULL);

					setfillcolor(WHITE);
					fillcircle(x1, y1, 24);
					putimage(x1 - 18, y1 - 18, img[member2 + 6]);
				}
			}	
		}
	}
}

//-----------------------------------------------------------------------------------------------

//判断胜负
char is_Win()
{
	if (s->next == NULL)
	{//初始时栈空直接返回
		return 0;
	}
	//用栈顶元素作为中心进行遍历
	//最后确定胜利的棋一定是构成五连的关键，最极端的情况就是作为五连的边点，
	// 所以往左边四个，右边四个，上面四个，下面四个，作为起点检查:
	// 从左往右，从上到下，从左上到右下，从左下到右上是否有五连
	chess ch = s->next->data;
	int row = ch.row_ind;
	int col = ch.col_ind;
	int left = col - 4, right = col + 4;
	int up = row - 4, down = row + 4;

	adjust(&left, &right, &up, &down);//将扫描范围放在棋盘，避免数组越界

	for (int i = left; i <= right - 4; i++)
	{//横向
		if (board[row][i].color == board[row][i + 1].color &&
			board[row][i + 1].color == board[row][i + 2].color &&
			board[row][i + 2].color == board[row][i + 3].color &&
			board[row][i + 3].color == board[row][i + 4].color && board[row][i].color != '-')
		{
			return board[row][i].color;
		}
	}
	for (int i = up; i <= down - 4; i++)
	{//纵向
		if (board[i][col].color == board[i + 1][col].color &&
			board[i + 1][col].color == board[i + 2][col].color &&
			board[i + 2][col].color == board[i + 3][col].color &&
			board[i + 3][col].color == board[i + 4][col].color && board[i][col].color != '-')
		{
			return board[i][col].color;
		}
	}


	//斜向
	int count = 0;//每相邻两个棋子颜色相等的时候加1，不相等时归零

	int space1 = col - left;
	int space2 = row - up;
	int space3 = right - col;
	int space4 = down - row;

	//主对角线
	int start1 = (space1 <= space2) ? space1 : space2;
	int end1 = (space3 <= space4) ? space3 : space4;
	int i = row - start1;
	int j = col - start1;
	for (; i <=  row + end1 - 1; i++, j++)
	{
		if (board[i][j].color == board[i + 1][j + 1].color && board[i][j].color != '-')
		{
			count++;
		}
		else
		{
			count = 0;
		}

		if (count == 4)
		{//有四对相同，说明五子成线，玩家胜利
			return board[i][j].color;
		}
	}

	//副对角线
	count = 0;
	int start2 = (space1 <= space4) ? space1 : space4;
	int end2 = (space3 <= space2) ? space3 : space2;
	i = row + start2;
	j = col - start2;
	for (; i >= row - end2 + 1; i--,j++)
	{
		if (board[i][j].color == board[i - 1][j + 1].color && board[i][j].color != '-')
		{
			count++;
		}
		else
		{
			count = 0;
		}

		if (count == 4)
		{//有四对相同，说明五子成线，玩家胜利
			return board[i][j].color;
		}
	}

	return '-';//无人胜利，继续游戏
}

//将扫描范围放在棋盘，避免数组越界
void adjust(int* left, int* right, int* up, int* down)
{
	while(*left < 0)
	{
		(*left)++;
	}
	while(*right > COL - 1)
	{
		(*right)--;
	}
	while(*up < 0)
	{
		(*up)++;
	}
	while(*down > ROW - 1)
	{
		(*down)--;
	}
}

//判断平局
bool is_draw()
{
	int count = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (board[i][j].color != '-')
			{
				count++;
			}
		}
	}
	if (count == 225)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//-----------------------------------------------------------------------------------------------

//加载奥义图前面一部分
void load_LastPreimage(linkqueue* q, int preframes, const char* name)
{

	char path[100]; // 保存文件路径
	for (int i = 0; i < preframes; i++)
	{
		IMAGE* animation = new IMAGE();//创建一个图片变量指针保存一张图片
		memset(path, '0', sizeof(path));
		sprintf(path, "assets/奥义图/%s奥义图/序列 %04d.jpg",
			name, i); // 格式化字符串
		loadimage(animation, path, 1067, 480);//按指定路径和宽，高加载图片
		enqueue(q, *animation);//将图片资源复制一份入队
		delete animation;//释放图片资源,节约内存
	}
}


//绘制人物奥义图动画（胜利动画）
void draw_WinChara(linkqueue* q, const char* name)
{	
	int frames = 65;
	int preframes = 10;
	int speed = 30;
	int x = 157;
	int y = 148;
	int width = 1067;
	int height = 480;
	
	int current_frame = 0;//帧索引
	int time_speed = 1000 / speed;//计算想要控制的每一帧所需时间
	int frame_start;//表示每一帧开始绘制时的时间
	int	frame_time;//表示每一帧绘制实际所需时间
	
	//播放奥义图音效
	char music[50];
	memset(music, '0', sizeof(music));
	sprintf(music, "assets/奥义图音效/%s奥义图音效.wav",name);
	PlaySound(music, NULL, SND_FILENAME | SND_ASYNC);
	Sleep(200);

	for(int i = 0;i < frames;i++)
	{//只播放一遍
		frame_start = clock();

		IMAGE* animation = new IMAGE();
		*animation = dequeue(q);//保存出队帧
		// 绘制图像
		if (q->head->next != NULL)
		{
			putimage(x, y, animation);
			FlushBatchDraw();
		}
		delete animation;//将已经绘制好的图片资源释放掉
		animation = NULL;

		//帧索引改变
		current_frame = ++current_frame % frames;

		//加载之后剩余的图片——每次循环绘制一帧，加载一帧
		char path[100]; // 保存文件路径
		IMAGE* a = new IMAGE();
		memset(path, '0', sizeof(path));
		sprintf(path, "assets/奥义图/%s奥义图/序列 %04d.jpg",
			name, (current_frame + preframes) % frames); // 格式化字符串
		loadimage(a, path, width, height);
		enqueue(q, *a);
		delete a;
		a = NULL;

		//休眠快了的时间以控制帧率
		frame_time = clock() - frame_start;
		int temp = time_speed - frame_time;
		if (temp > 0)
		{
			Sleep(temp);
		}
	}

	//停留在最后一帧等待语音结束
	char path[100]; // 保存文件路径
	IMAGE* last_frame = new IMAGE();
	memset(path, '0', sizeof(path));
	sprintf(path, "assets/奥义图/%s奥义图/序列 %04d.jpg",
		name, 64); // 格式化字符串
	loadimage(last_frame, path, width, height);
	putimage(x, y, last_frame);
	FlushBatchDraw();

	Sleep(500);
	delete last_frame;//将已经绘制好的图片资源释放掉
	last_frame = NULL;
	cleardevice();
}

