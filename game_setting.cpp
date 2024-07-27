#include "head&func.h"

//游戏设置界面
void game_Setting()
{
	while (true)
	{
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

		
		//绘制图像
		if (true)
		{
			cleardevice();
			setfillcolor(RGB(195, 154, 102));

			putimage(0, 0, img[33]);//背景图

			fillroundrect(470, 32, 858, 263, 10, 10);
			putimage(477, 39, img[27]);//人物选择
			drawImg(477, 39, img[28]);//人物选择文字

			fillroundrect(491, 289, 819, 597, 10, 10);
			putimage(498, 296, img[29]);//背景音乐图
			drawImg(498, 296, img[30]);//背景音乐文字
			drawImg(25 + 498, 182 + 296, img[31]);//切换背景音乐文字
			drawImg(199 + 498, 211 + 296, img[32]);//开关背景音乐文字

			fillroundrect(1154, 642, 1333, 751, 10, 10);
			putimage(1161, 649, img[25]);//返回主界面
			drawImg(1161, 649, img[26]);//退出主界面文字

			FlushBatchDraw();

		}


		//数据处理
		if (true)
		{
			if (in_Button(x, y, 477, 39, 374, 217))
			{//进入人物选择界面
				choose_Character();
				playercount = 0;//将玩家数归零，以便后续再次选择人物
			}
			else if (in_Button(x, y, 25 + 498, 182 + 296, 49, 101))
			{//切换音乐
				//先停止当前音乐
				char music[50];
				memset(music, '0', sizeof(music));
				sprintf(music, "close assets/背景音乐/bgm%d.mp3", current_music);//关闭音乐
				mciSendString(music, NULL, 0, NULL);
				Sleep(300);
				current_music = current_music % 5 + 1;//更新当前音乐，切换到下一首
				play_Music();//播放下一首
			}
			else if (in_Button(x, y, 199 + 498, 211 + 296, 115, 48))
			{//暂停/播放 音乐
				if (is_playmusic)
				{//如果正在播放就暂停
					char music[50];
					memset(music, '0', sizeof(music));
					sprintf(music, "pause assets/背景音乐/bgm%d.mp3", current_music);//暂停音乐
					mciSendString(music, NULL, 0, NULL);
					is_playmusic = false;
					Sleep(200);
				}
				else
				{//如果在暂停就播放
					play_Music();
					is_playmusic = true;
					Sleep(200);
				}
			}
			else if (in_Button(x, y,1161,649,165,95))
			{//退出游戏设置界面，返回主界面
				Sleep(300);
				return;
			}
		}
	}
}

//----------------------------------------------------------------------------------

//人物选择界面
void choose_Character()
{
	int frame_start;//表示每一帧开始绘制时的时间
	int	frame_time;//表示每一帧绘制实际所需时间
	int time_speed = 1000 / 30;//计算想要控制的每一帧所需时间

	playercount = 0;
	int flag = 0;
	for (int i = 6; i <= 17; i++)
	{//将每个角色的当前帧初始化为0
		roles[i].current_frame = 0;
	}


	while (true)
	{
		frame_start = clock();

		int x = 0;
		int y = 0;
		int click_x = 0;
		int click_y = 0;
		//获取鼠标信息
		if (true)
		{
			while (peekmessage(&msg))
			{
			}

			x = msg.x;
			y = msg.y;

			if (msg.message == WM_LBUTTONDOWN)
			{
				click_x = x;
				click_y = y;
			}
		}


		//绘制图像
		if (true)
		{
			cleardevice();
			setfillcolor(RGB(195, 154, 102));

			putimage(0, 0, img[34]);//背景图

			fillroundrect(1154, 642, 1333, 751, 10, 10);
			putimage(1161, 649, img[25]);//返回主界面
			drawImg(1161, 649, img[26]);//返回主界面文字
			//人物头像
			draw_Charahead(886, 28, 12);
			draw_Charahead(789, 56, 13);
			draw_Charahead(691, 102, 14);
			draw_Charahead(614, 152, 15);
			draw_Charahead(517, 203, 16);
			draw_Charahead(442, 272, 17);
			draw_Charahead(540, 309, 18);
			draw_Charahead(617, 346, 19);
			draw_Charahead(719, 317, 20);
			draw_Charahead(792, 263, 21);
			draw_Charahead(766, 174, 22);
			draw_Charahead(668, 225, 23);

			//绘制鼠标所在人物的动画，并且根据点击的位置确定人物
			draw_Character(x, y, click_x, click_y);

			//绘制玩家就绪图
			if (playercount >= 1)
			{
				putimage(1200, 340, img[46]);
				drawImg(1200, 340, img[47]);
			}
			if (playercount == 2)
			{
				putimage(34, 320, img[48]);
				drawImg(34, 320, img[49]);
			}

			FlushBatchDraw();
		}


		//数据处理	
		if (in_Button(click_x, click_y, 1161, 649, 165, 95))
		{//退出游戏设置界面，返回主界面
			Sleep(500);
			return;
		}
		

		//休眠快了的时间以控制帧率
		frame_time = clock() - frame_start;
		int temp = time_speed - frame_time;
		if (temp > 0)
		{
			Sleep(temp);
		}
	}
}

//绘制人物头像
void draw_Charahead(int x, int y,int i)
{
	////绘制背景圆形
	//setfillcolor(WHITE);
	//solidcircle(x + 23, y + 23, 27);
	////创建一个接近圆形形状的矩形剪切区域
	//HRGN hRgn = CreateRoundRectRgn(x, y, x + 46, y + 46, 46, 46);
	//setcliprgn(hRgn); // 将矩形剪切区域设置为当前绘图的剪切区域
	//// 在剪切区域内绘制图形或图片
	//putimage(x, y, img[i]);
	//// 清除剪切区域
	//setcliprgn(NULL);

	setfillcolor(WHITE);
	solidcircle(x + 18, y + 18, 26);
	putimage(x, y, img[i]);

}

//根据鼠标在的位置的人物绘制人物动画
void draw_Character(int x, int y, int click_x, int click_y)
{
	int chara_num = 0;
	
	//找到鼠标所在人物的序号
	if (true)
	{
		if (in_Button(x, y, 886, 28,46,46))
		{//漩涡鸣人
			chara_num = 6;
		}
		else if (in_Button(x, y, 789, 56, 46, 46))
		{//宇智波佐助
			chara_num = 7;
		}
		else if (in_Button(x, y, 691, 102, 46, 46))
		{//春野樱
			chara_num = 8;
		}
		else if (in_Button(x, y, 614, 152, 46, 46))
		{//宇智波鼬
			chara_num = 9;
		}
		else if (in_Button(x, y, 517, 203, 46, 46))
		{//宇智波带土
			chara_num = 10;
		}
		else if (in_Button(x, y, 442, 272, 46, 46))
		{//宇智波斑
			chara_num = 11;
		}
		else if (in_Button(x, y, 540, 309, 46, 46))
		{//旗木卡卡西
			chara_num = 12;
		}
		else if (in_Button(x, y, 617, 346, 46, 46))
		{//迈特凯
			chara_num = 13;
		}
		else if (in_Button(x, y, 719, 317, 46, 46))
		{//自来也
			chara_num = 14;
		}
		else if (in_Button(x, y, 792, 263, 46, 46))
		{//千手柱间
			chara_num = 15;
		}
		else if (in_Button(x, y, 766, 174, 46, 46))
		{//千手扉间
			chara_num = 16;
		}
		else if (in_Button(x, y, 668, 225, 46, 46))
		{//波风水门
			chara_num = 17;
		}
		else
		{
			return;
		}
	}

	//当鼠标点击人物的时候，选择人物，玩家数加1
	if (click_x == x && click_y == y)
	{
		playercount++;
		if (playercount == 1)
		{
			player1.chara = roles[chara_num];
			Sleep(300);
		}
		
		else if (playercount == 2)
		{
			player2.chara = roles[chara_num];
			Sleep(300);
		}
	}


	roles[chara_num].current_frame++;
	IMAGE* animation = new IMAGE();
	*animation = dequeue(queue[chara_num]);//保存出队帧
	// 绘制图像
	if (queue[chara_num]->head->next != NULL)
	{
		putimage(403, 323 + 80, animation);
	}
	delete animation;//将已经绘制好的图片资源释放掉
	animation = NULL;

	thread load(load_FollowCharaAnim, queue[chara_num], &roles[chara_num].current_frame,
		roles[chara_num].frames, roles[chara_num].preframes, roles[chara_num].name,
		roles[chara_num].width, roles[chara_num].height);
	load.detach();

}

//废弃的绘制人物动画函数
////绘制人物动画
//void draw_CharaAnim(linkqueue* q, int frames, int preframes, int speed, const char* name,
//	int width, int height,int button_x,int button_y)
//{	//frames 表示总帧数，pre_frames表示需要预先加载的帧数,
//	//speed表示帧率，name表示文件名，x和y表示图片左上角的点所在坐标
//	//width和height与加载函数的x，y相同
//
//	int time_speed = 1000 / speed;//计算想要控制的每一帧所需时间
//	int current_frame = 0;//帧索引
//
//	int frame_start;//表示每一帧开始绘制时的时间
//	int	frame_time;//表示每一帧绘制实际所需时间
//
//
//	int rolenum = 6;
//	for (int i = 6; i <= 17; i++)
//	{
//		if (strcmp(name,roles[i].name) == 0)
//		{
//			rolenum = i;
//			break;
//		}
//	}
//
//	while (true)
//	{
//		frame_start = clock();
//
//		//接受信息
//		int xi = 0;
//		int yi = 0;
//		while (peekmessage(&msg))
//		{}
//
//		if (msg.message == WM_LBUTTONDOWN &&
//			in_Button(xi, yi, button_x, button_y, 50, 50))
//		{//若点击人物头像，则进行人物选择
//			playercount++;
//			if (playercount == 1)
//			{
//				player1.chara = roles[rolenum];
//			}
//			else if (playercount == 2)
//			{
//				player2.chara = roles[rolenum];
//			}
//
//			if (playercount == 2)
//			{
//				cleardevice();
//				return;
//			}
//		}
//		else
//		{
//			xi = msg.x;
//			yi = msg.y;
//			if (!in_Button(xi, yi, button_x, button_y, 50, 50))
//			{
//				return;
//			}
//		}
//		
//
//		// 绘制图像
//		IMAGE* animation = new IMAGE();
//		*animation = dequeue(q);//保存出队帧
//		if (q->head->next != NULL)
//		{
//			putimage(403, 323+30, animation);
//			//FlushBatchDraw();
//		}
//		delete animation;//将已经绘制好的图片资源释放掉
//
//		//帧索引改变
//		current_frame = ++current_frame % frames;
//
//		//加载之后剩余的图片——每次循环绘制一帧，加载一帧
//		//char path[100]; // 保存文件路径
//		//IMAGE* a = new IMAGE();
//		//memset(path, '0', sizeof(path));
//		//sprintf(path, "assets/人物动画/%s/序列 %04d.jpg",
//		//	name, (current_frame + preframes) % frames); // 格式化字符串
//		//loadimage(a, path, width, height);
//		//enqueue(q, *a);
//		//delete a;
//		
//		thread loadfollow(load_FollowCharaAnim,q, &current_frame, roles[rolenum].frames,
//			roles[rolenum].preframes,roles[rolenum].name,roles[rolenum].width, roles[rolenum].height);
//		loadfollow.detach();
//
//		//休眠快了的时间以控制帧率
//		frame_time = clock() - frame_start;
//		int temp = time_speed - frame_time;
//		if (temp > 0)
//		{
//			Sleep(temp);
//		}
//	}
//	Sleep(300);
//
//}
