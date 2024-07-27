#include "head&func.h"

//加载图片资源
void load_Image()
{
	//初始图片变量
	for (int i = 0; i <= 51; i++)
	{
		img[i] = new IMAGE();
	}


	//绘制主菜单——“游戏标题”
	loadimage(img[1], "assets/图片/游戏标题文字.png", 123, 147);

	//绘制主菜单——“开始游戏”按钮
	loadimage(img[2], "assets/图片/开始游戏.jpg", 169, 289);
	loadimage(img[3], "assets/图片/开始游戏文字.png", 169, 289);

	//绘制主菜单——“游戏设置”按钮
	loadimage(img[4], "assets/图片/游戏设置.jpg", 230, 142);
	loadimage(img[5], "assets/图片/游戏设置文字.png", 230, 142);

	//绘制主菜单——“游戏说明”按钮
	loadimage(img[6], "assets/图片/游戏说明.jpg", 267, 124);
	loadimage(img[7], "assets/图片/游戏说明文字.png", 267, 124);

	//绘制主菜单——“制作人员及更多”
	loadimage(img[8], "assets/图片/制作人员及更多.jpg", 279, 172);
	loadimage(img[9], "assets/图片/制作人员及更多文字.png", 279, 172);

	//绘制主菜单——“退出游戏”按钮
	loadimage(img[10], "assets/图片/退出游戏.jpg", 298, 170);
	loadimage(img[11], "assets/图片/退出游戏文字.png", 298, 170);

	int wid = 36;
	int hei = 36;
	loadimage(img[12], "assets/图片/漩涡鸣人头像.jpg",wid,hei);
	loadimage(img[13], "assets/图片/宇智波佐助头像.jpg", wid, hei);
	loadimage(img[14], "assets/图片/春野樱头像.jpg", wid, hei);
	loadimage(img[15], "assets/图片/宇智波鼬头像.jpg", wid, hei);
	loadimage(img[16], "assets/图片/宇智波带土头像.jpg", wid, hei);
	loadimage(img[17], "assets/图片/宇智波斑头像.jpg", wid, hei);
	loadimage(img[18], "assets/图片/旗木卡卡西头像.jpg", wid, hei);
	loadimage(img[19], "assets/图片/迈特凯头像.jpg", wid, hei);
	loadimage(img[20], "assets/图片/自来也头像.jpg", wid, hei);
	loadimage(img[21], "assets/图片/千手柱间头像.jpg", wid, hei);
	loadimage(img[22], "assets/图片/千手扉间头像.jpg", wid, hei);
	loadimage(img[23], "assets/图片/波风水门头像.jpg", wid, hei);

	//加载返回主界面按钮
	loadimage(img[25], "assets/图片/退出游戏.jpg", 165, 95);
	loadimage(img[26], "assets/图片/返回主界面文字.png", 165, 95);

	//加载人物选择和播放音乐资源
	loadimage(img[27], "assets/图片/人物选择.jpg",374 , 217);
	loadimage(img[28], "assets/图片/人物选择文字.png", 374, 217);
	loadimage(img[29], "assets/图片/背景音乐.jpg",314 ,294 );
	loadimage(img[30], "assets/图片/背景音乐文字.png",314 ,294 );
	loadimage(img[31], "assets/图片/背景音乐切换文字.png",49 ,101 );
	loadimage(img[32], "assets/图片/背景音乐开关文字.png", 115,48 );

	//加载游戏设置界面背景图
	loadimage(img[33], "assets/图片/游戏设置.jpg", 1382, 777);
	loadimage(img[34], "assets/图片/人物选择.jpg", 1382, 777);

	//加载游戏说明背景图
	loadimage(img[35], "assets/图片/游戏说明.jpg", 1382, 777);
	loadimage(img[36], "assets/图片/游戏说明内容.png", 1382, 777);
	
	//加载制作人员及更多背景图
	loadimage(img[37], "assets/图片/制作人员及更多.jpg", 1382, 777);
	loadimage(img[38], "assets/图片/制作人员及更多内容.png", 1382, 777);
	//loadimage(img[39], "assets/图片/更多文字.png", 1382, 777); 

	//加载棋盘背景图
	loadimage(img[40], "assets/图片/棋盘背景.jpg", 700, 700);

	//加载当前回合图
	loadimage(img[41], "assets/图片/当前回合.jpg",207,117);
	loadimage(img[42], "assets/图片/当前回合文字.png", 207,117);

	//加载悔棋图
	loadimage(img[43], "assets/图片/悔棋.jpg", 170,115);
	loadimage(img[44], "assets/图片/悔棋文字.png", 170,115);

	//加载准备就绪图
	loadimage(img[46], "assets/图片/玩家一就绪.jpg", 160, 293);
	loadimage(img[47], "assets/图片/玩家一就绪文字.png", 160, 293);
	loadimage(img[48], "assets/图片/玩家二就绪.jpg", 147, 314);
	loadimage(img[49], "assets/图片/玩家二就绪文字.png", 147, 314);

	//加载平局奥义图
	loadimage(img[50], "assets/图片/平局奥义图.jpg", 1055, 511);


	//提前打开背景音乐文件
	for (int i = 0; i <= 5; i++)
	{
		char path[100];
		memset(path, 0, sizeof(path));
		sprintf(path, "open assets/背景音乐/bgm%d.mp3", i);
		mciSendString(path, NULL, 0, NULL);
	}
}

//加载游戏动画和图片资源
void load_Resource()
{	
	//初始化人物变量
	if (true)
	{
		roles[6].name = "漩涡鸣人"; roles[6].frames = 548; roles[6].preframes = 20;
		roles[6].width = 575, roles[6].height = 323; roles[6].speed = 30;

		roles[7].name = "宇智波佐助"; roles[7].frames = 87; roles[7].preframes = 5;
		roles[7].width = 345, roles[7].height = 345; roles[7].speed = 30;

		roles[8].name = "春野樱"; roles[8].frames = 324; roles[8].preframes = 15;
		roles[8].width = 575, roles[8].height = 323; roles[8].speed = 30;

		roles[9].name = "宇智波鼬"; roles[9].frames = 87; roles[9].preframes = 15;
		roles[9].width = 575, roles[9].height = 323; roles[9].speed = 30;

		roles[10].name = "宇智波带土"; roles[10].frames = 290; roles[10].preframes = 20;
		roles[10].width = 575, roles[10].height = 323; roles[10].speed = 30;

		roles[11].name = "宇智波斑"; roles[11].frames = 292; roles[11].preframes = 20;
		roles[11].width = 575, roles[11].height = 323; roles[11].speed = 30;

		roles[12].name = "旗木卡卡西"; roles[12].frames = 308; roles[12].preframes = 20;
		roles[12].width = 575, roles[12].height = 323; roles[12].speed = 30;

		roles[13].name = "迈特凯"; roles[13].frames = 596; roles[13].preframes = 20;
		roles[13].width = 575, roles[13].height = 323; roles[13].speed = 30;

		roles[14].name = "自来也"; roles[14].frames = 186; roles[14].preframes = 10;
		roles[14].width = 575, roles[14].height = 323; roles[14].speed = 30;

		roles[15].name = "千手柱间"; roles[15].frames = 221; roles[15].preframes = 20;
		roles[15].width = 575, roles[15].height = 323; roles[15].speed = 30;

		roles[16].name = "千手扉间"; roles[16].frames = 231; roles[16].preframes = 20;
		roles[16].width = 575, roles[16].height = 323; roles[16].speed = 30;

		roles[17].name = "波风水门"; roles[17].frames = 344; roles[17].preframes = 20;
		roles[17].width = 575, roles[17].height = 323; roles[17].speed = 30;
	}

	

	//线程1加载加载动画
	threads[1] = thread(load_BPreimage, queue[1], 20, "加载动画", 1382, 777);
	threads[1].detach();

	//线程2加载入场动画
	threads[2] = thread(load_BPreimage, queue[2], 100, "入场动画", 1382, 777);
	threads[2].detach();

	//线程3加载加载动画2
	threads[3] = thread(load_BPreimage, queue[3], 10, "加载动画2", 1382, 777);
	threads[3].detach();

	//线程4加载游戏背景
	threads[4] = thread(load_BPreimage, queue[4], 20, "游戏背景", 1382, 777);
	threads[4].detach();

	//线程5加载主界面壁纸
	threads[5] = thread(load_BPreimage, queue[5], 10, "主界面壁纸", 1382, 777);
	threads[5].detach();
	
	//线程0加载图片资源
	threads[0] = thread(load_Image);
	threads[0].detach();

	//线程6加载漩涡鸣人形象
	threads[6] = thread(load_Preimage, queue[6], roles[6].preframes , roles[6].name, roles[6].width, roles[6].height);
	threads[6].detach();
	
	//线程7加载宇智波佐助形象
	threads[7] = thread(load_Preimage, queue[7], roles[7].preframes, roles[7].name, roles[7].width, roles[7].height);
	threads[7].detach();
	
	//线程8加载春野樱形象
	threads[8] = thread(load_Preimage, queue[8], roles[8].preframes, roles[8].name, roles[8].width, roles[8].height);
	threads[8].detach();
	
	//线程9加载宇智波鼬形象
	threads[9] = thread(load_Preimage, queue[9], roles[9].preframes, roles[9].name, roles[9].width, roles[9].height);
	threads[9].detach();
	
	//线程10加载宇智波带土形象
	threads[10] = thread(load_Preimage, queue[10], roles[10].preframes, roles[10].name, roles[10].width, roles[10].height);
	threads[10].detach();
	
	//线程11加载宇智波斑形象
	threads[11] = thread(load_Preimage, queue[11], roles[11].preframes, roles[11].name, roles[11].width, roles[11].height);
	threads[11].detach();
	
	//线程12加载旗木卡卡卡西形象
	threads[12] = thread(load_Preimage, queue[12], roles[12].preframes, roles[12].name, roles[12].width, roles[12].height);
	threads[12].detach();
	
	//线程13加载迈特凯形象
	threads[13] = thread(load_Preimage, queue[13], roles[13].preframes, roles[13].name, roles[13].width, roles[13].height);
	threads[13].detach();
	
	//线程14加载自来也形象
	threads[14] = thread(load_Preimage, queue[14], roles[14].preframes, roles[14].name, roles[14].width, roles[14].height);
	threads[14].detach();
	
	//线程15加载千手柱间形象
	threads[15] = thread(load_Preimage, queue[15], roles[15].preframes, roles[15].name, roles[15].width, roles[15].height);
	threads[15].detach();
	
	//线程16加载千手扉间形象
	threads[16] = thread(load_Preimage, queue[16], roles[16].preframes, roles[16].name, roles[16].width, roles[16].height);
	threads[16].detach();
	
	//线程17加载波风水门形象
	threads[17] = thread(load_Preimage, queue[17], roles[17].preframes, roles[17].name, roles[17].width, roles[17].height);
	threads[17].detach();

}


//加载开始部分动画前面一部分帧
void load_BPreimage(linkqueue* q, int preframes, const char* name, int x, int y)
{//pre_frames表示需要预先加载的帧数，name表示文件名，x，y表示图片放置窗口的宽和高

	char path[100]; // 保存文件路径
	for (int i = 0; i < preframes; i++)
	{
		IMAGE* animation = new IMAGE();//创建一个图片变量指针保存一张图片
		memset(path, '0', sizeof(path));
		sprintf(path, "assets/开始部分/%s/序列 %04d.jpg",
				name, i); // 格式化字符串
		loadimage(animation, path, x, y);//按指定路径和宽，高加载图片
		enqueue(q, *animation);//将图片资源复制一份入队
		delete animation;//释放图片资源,节约内存
		animation = NULL;
	}
}

//加载人物动画前面一部分帧
void load_Preimage(linkqueue* q, int preframes, const char* name, int x, int y)
{//pre_frames表示需要预先加载的帧数，name表示文件名，x，y表示图片放置窗口的宽和高

	char path[100]; // 保存文件路径
	for (int i = 0; i < preframes; i++)
	{
		IMAGE* animation = new IMAGE();//创建一个图片变量指针保存一张图片
		memset(path, '0', sizeof(path));
		sprintf(path, "assets/人物动画/%s/序列 %04d.jpg",
			name, i); // 格式化字符串
		loadimage(animation, path, x, y);//按指定路径和宽，高加载图片
		enqueue(q, *animation);//将图片资源复制一份入队
		delete animation;//释放图片资源,节约内存
		animation = NULL;
	}
}

//-----------------------------------------------------------------------------------------------

//异步加载开始部分之后的动画
void load_FollowAnim(linkqueue* q, int* current_frame, int frames, int preframes,
	const char* name, int width, int height)//背景
{
	//加载背景图之后剩余的图片——每次循环绘制一帧，加载一帧
	char path[100]; // 保存文件路径
	IMAGE* a = new IMAGE();
	memset(path, '0', sizeof(path));
	sprintf(path, "assets/开始部分/%s/序列 %04d.jpg",
		name, ((*current_frame) + preframes) % frames); // 格式化字符串
	loadimage(a, path, width, height);
	enqueue(q, *a);
	delete a;
	a = NULL;
}

//异步加载人物之后的动画
void load_FollowCharaAnim(linkqueue* q, int* current_frame, int frames, int preframes,
	const char* name, int width, int height)//人物
{
	//加载背景图之后剩余的图片——每次循环绘制一帧，加载一帧
	char path[100]; // 保存文件路径
	IMAGE* a = new IMAGE();
	memset(path, '0', sizeof(path));
	sprintf(path, "assets/人物动画/%s/序列 %04d.jpg",
		name, (*current_frame + preframes) % frames); // 格式化字符串
	loadimage(a, path, width, height);
	enqueue(q, *a);
	delete a;
	a = NULL;
}

//-----------------------------------------------------------------------------------------------

//绘制两个加载动画
void draw_Animation(linkqueue* q, int frames, int preframes, int speed, const char* name,
				int x, int y, int width, int height)
{	//frames 表示总帧数，pre_frames表示需要预先加载的帧数,
	//speed表示帧率，name表示文件名，x和y表示图片左上角的点所在坐标
	//width和height与加载函数的x，y相同

	int time_speed = 1000 / speed;//计算想要控制的每一帧所需时间
	int current_frame = 0;//帧索引

	int frame_start;//表示每一帧开始绘制时的时间
	int	frame_time;//表示每一帧绘制实际所需时间
	
	for(int i = 0;i < frames;i++)
	{//只播放一次
		frame_start = clock();


		IMAGE* animation = new IMAGE();
		*animation = dequeue(q);//保存出队帧
		// 绘制图像
		if (q->head->next != NULL)
		{
			cleardevice();
			putimage(x, y, animation);
			FlushBatchDraw();
		}
		delete animation;//将已经绘制好的图片资源释放掉
		animation = NULL;

		//帧索引改变
		current_frame = ++current_frame % frames;
		
		//加载之后剩余的图片——每次循环绘制一帧，加载一帧
		thread load(load_FollowAnim, q, &current_frame,frames, preframes, name, width, height);
		load.detach();

		//休眠快了的时间以控制帧率
		frame_time = clock() - frame_start;
		int temp = time_speed - frame_time;
		if (temp > 0)
		{
			Sleep(temp);
		}
	}
	Sleep(500);//等待未完成的线程
}

//绘制入场动画
void draw_EnterAnimation(linkqueue* q, int frames, int preframes, int speed, const char* name,
	int x, int y, int width, int height)
{
	//播放背景音乐
	current_music = 0;
	play_Music();
	Sleep(300);

	cleardevice();
	int time_speed = 1000 / speed;//计算想要控制的每一帧所需时间
	int current_frame = 0;//帧索引

	int frame_start;//表示每一帧开始绘制时的时间
	int	frame_time;//表示每一帧绘制实际所需时间

	
	for (int i = 0; i < frames; i++)
	{
		frame_start = clock();

		//接受鼠标信息，判断是否要中断
		if (true)
		{
			while (peekmessage(&msg))
			{//获取鼠标信息
				if (msg.message == WM_LBUTTONDOWN)
				{
					return;
				}
			}
		}


		//绘制图像
		if (true)
		{
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
			thread load(load_FollowAnim, q, &current_frame, frames,preframes, name, width, height);
			load.detach();
		}


		//休眠快了的时间以控制帧率
		frame_time = clock() - frame_start;
		int temp = time_speed - frame_time;
		if (temp > 0)
		{
			Sleep(temp);
		}
	}

	IMAGE* temp = new IMAGE();
	loadimage(temp, "assets/开始部分/入场动画/序列 7050.jpg", 1382, 777);
	cleardevice();
	putimage(0, 0, temp);
	FlushBatchDraw();
	delete temp;
	temp = NULL;
	Sleep(1500);
}

//-----------------------------------------------------------------------------------------------

//一些工具函数
//播放音乐
void play_Music()
{
	char path[100];
	memset(path, 0, sizeof(path));
	sprintf(path, "play assets/背景音乐/bgm%d.mp3",current_music);//wav文件不支持重复播放
	mciSendString(path, NULL, 0, NULL);

	if (current_music != 0)
	{//降低一点背景音乐的音量
		memset(path, 0, sizeof(path));
		sprintf(path, "setaudio assets/背景音乐/bgm%d.mp3 volume to %d",current_music,580);
		mciSendString(path, NULL, 0, NULL);
	}
}

//判断鼠标是否在指定的矩形按钮区域内
bool in_Button(int msg_x, int msg_y, int x, int y, int w, int h)
{
	if (msg_x > x && msg_x < x + w && msg_y > y && msg_y < y + h)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//PNG图片透明贴图（现成的）
void drawImg(int x, int y, IMAGE* src)
{
	// 变量初始化
	DWORD* pwin = GetImageBuffer();			//窗口缓冲区指针
	DWORD* psrc = GetImageBuffer(src);		//图片缓冲区指针
	int win_w = getwidth();				//窗口宽高
	int win_h = getheight();
	int src_w = src->getwidth();				//图片宽高
	int src_h = src->getheight();

	// 计算贴图的实际长宽
	int real_w = (x + src_w > win_w) ? win_w - x : src_w;			// 处理超出右边界
	int real_h = (y + src_h > win_h) ? win_h - y : src_h;			// 处理超出下边界
	if (x < 0) { psrc += -x;			real_w -= -x;	x = 0; }	// 处理超出左边界
	if (y < 0) { psrc += (src_w * -y);	real_h -= -y;	y = 0; }	// 处理超出上边界


	// 修正贴图起始位置
	pwin += (win_w * y + x);

	// 实现透明贴图
	for (int iy = 0; iy < real_h; iy++)
	{
		for (int ix = 0; ix < real_w; ix++)
		{
			byte a = (byte)(psrc[ix] >> 24);//计算透明通道的值[0,256) 0为完全透明 255为完全不透明
			if (a > 100)
			{
				pwin[ix] = psrc[ix];
			}
		}
		//换到下一行
		pwin += win_w;
		psrc += src_w;
	}
}

//释放队列
void free_Queue(linkqueue* q)
{
	animQnode* temp1 = q->head->next;
	animQnode* temp2 = NULL;
	while (temp1 != NULL)
	{//可用线程
		temp2 = temp1;
		temp1 = temp1->next;
		delete temp2;
		temp2 = NULL;
	}
}
