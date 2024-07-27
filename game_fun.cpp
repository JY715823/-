#include "head&func.h"



//��Ϸ����
void game_View(linkqueue* q_back,int frames, int preframes, int speed, const char* name,
	int width, int height)
{	//frames ��ʾ��֡����pre_frames��ʾ��ҪԤ�ȼ��ص�֡��,
	//speed��ʾ֡�ʣ�name��ʾ�ļ���
	//width��height����غ�����x��y��ͬ
	
	srand((unsigned)time(NULL));//������������ӣ��Ա㲥��������Ч


	//�ҵ����������ѡ��ɫ�����
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

	//��ǰ����������ҽ�ɫ�İ���ͼ
	thread load_LastImage1(load_LastPreimage, queue[member1 + 12], 10, player1.chara.name);
	load_LastImage1.detach();
	thread load_LastImage2(load_LastPreimage, queue[member2 + 12], 10, player2.chara.name);
	load_LastImage2.detach();
	Sleep(300);

	bool running = true;//�ж��Ƿ�ʤ���ı�־
	int round = 0;//�غ����������жϵ�ǰ�غ����ĸ��������

	int time_speed = 1000 / speed;//������Ҫ���Ƶ�ÿһ֡����ʱ��
	int current_frame1 = 0;//֡����1(����ͼ��
	int current_frame2 = 0;//֡����2�����һ��ɫ������
	int current_frame3 = 0;//֡����3����Ҷ���ɫ������

	int frame_start;//��ʾÿһ֡��ʼ����ʱ��ʱ��
	int	frame_time;//��ʾÿһ֡����ʵ������ʱ��

	//��ʼ������
	init_Board();

	linkqueue* q_chara;//�����ɫ�Ķ����Ķ���
	while (running)
	{
		frame_start = clock();

		int x = 0;
		int y = 0;
		
		//��ȡ�����Ϣ	
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

		//���ݴ���
		if (true)
		{
			//����
			if (x > 0 && x <= SPACE + 750 && y > 0 && y <= SPACE + 750)
			{
				drop_Chess(x, y, &round);
			}

			//�Ƿ����
			if (in_Button(x, y, 784, 640, 170, 115))
			{
				Sleep(200);
				if (s->next != NULL)
				{
					chess reg_chess = pop();
					int xi = reg_chess.row_ind;
					int yi = reg_chess.col_ind;
					board[xi][yi].color = '-';//������ɾ��
					round--;//������һ�غ�
				}
			}

			//�˳���Ϸ���ý��棬����������
			if (in_Button(x, y, 1161, 649, 165, 95))
			{
				Sleep(2000);
				return;
			}

			//�ж�ʤ��
			char flag = is_Win();
			if (flag == 'b')
			{//����Ӯ��
				//����ʤ������ͼ
				draw_WinChara(queue[member1 + 12], player1.chara.name);
				Sleep(2000);
				running = false;
			}
			else if (flag == 'w')
			{//����Ӯ��
				//����ʤ������ͼ
				draw_WinChara(queue[member2 + 12], player2.chara.name);
				Sleep(2000);
				running = false;
			}

			if (is_draw())
			{//�ж�ƽ��
				putimage(184, 140, img[50]);
				Sleep(1500);
				running = false;
			}
		}

		//����ͼ��
		if (true)
		{
			// ���汳��
			IMAGE* animation1 = new IMAGE();
			*animation1 = dequeue(q_back);//�������֡

			// ������������
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
			*animation2 = dequeue(q_chara);//�������֡

			cleardevice();

			putimage(0, 0, animation1);//����ͼ

			draw_Board();//��������
			draw_Chess();//��������

			setfillcolor(RGB(195, 154, 102));//���ð�ť�߿���ɫ

			fillroundrect(777, 633, 961, 762, 10, 10);//���ư�ť�߿�
			putimage(784, 640, img[43]);//����
			drawImg(784, 640, img[44]);//��������

			fillroundrect(777, 36, 998, 167, 12, 12);
			putimage(784, 43, img[41]);//��ǰ�غ�
			drawImg(784, 43, img[42]);//��ǰ�غ�����

			fillroundrect(1154, 642, 1333, 751, 10, 10);
			putimage(1161, 649, img[25]);//����������
			drawImg(1161, 649, img[26]);//�˳�����������

			putimage(784, 185, animation2);//����ͼ
			FlushBatchDraw();

			delete animation1;//���Ѿ����ƺõ�ͼƬ��Դ�ͷŵ�
			animation1 = NULL;
			delete animation2;//���Ѿ����ƺõ�ͼƬ��Դ�ͷŵ�
			animation2 = NULL;

			//�첽����֮���ͼƬ
			current_frame1 = ++current_frame1 % frames;
			thread load1(load_FollowAnim, queue[4], &current_frame1, 519, 20, "��Ϸ����", 1382, 777);
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

		//���߿��˵�ʱ���Կ���֡��
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

	//�ͷŸ���ջ���ڴ�
	snode* p = s->next;
	while (p != NULL)
	{
		snode* outnode = p;
		p = p->next;
		delete outnode;
		outnode = NULL;
	}

	//�ӳ��˳����Ա������δ���ص��̣߳�������ִ���
	Sleep(1000);
}


//--------------------------------------------------------------------------------------

//��ʼ������
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

//����
void drop_Chess(int msg_x, int msg_y,int* round)
{	
	//�ҳ��������
	int center_x, center_y;
	if (true)
	{
		int x1 = ((msg_x - SPACE) / 50) * 50 + SPACE;
		int y1 = ((msg_y - SPACE) / 50) * 50 + SPACE;
		int x2 = x1 + 50;
		int y2 = y1 + 50;
		//����������һ�������е��ĸ�����ľ����ƽ��
		int dis[4];
		dis[0] = (msg_x - x1) * (msg_x - x1) + (msg_y - y1) * (msg_y - y1);//����x1��y1��
		dis[1] = (msg_x - x1) * (msg_x - x1) + (msg_y - y2) * (msg_y - y2);//����x1��y2��
		dis[2] = (msg_x - x2) * (msg_x - x2) + (msg_y - y1) * (msg_y - y1);//����x2��y1��
		dis[3] = (msg_x - x2) * (msg_x - x2) + (msg_y - y2) * (msg_y - y2);//����x2��y2��
		//�ҳ�������С�ģ��õ����Ҫ�µ����Բ��
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


	//����flag���غ��������Ӧ������
	if (board[center_y][center_x].color == '-')
	{//��ǰ��û�����ӣ�������
		if (*round % 2 + 1 == 1)
		{
			board[center_y][center_x].color = player1.color;
			board[center_y][center_x].row_ind = center_y;
			board[center_y][center_x].col_ind = center_x;
			//���Ӳ�����Ч
			play_CharaVoice(player1.chara.name);
		}
		else
		{
			board[center_y][center_x].color = player2.color;
			board[center_y][center_x].row_ind = center_y;
			board[center_y][center_x].col_ind = center_x;
			//���Ӳ�����Ч
			play_CharaVoice(player2.chara.name);
		}

		(*round)++;//�غ�����һ

		//���µ�������ջ,�Ա���л�����ж�ʤ��
		push(board[center_y][center_x]);
	}
}

//���Ӳ���������Ч
void play_CharaVoice(const char* name)
{
	int num = rand() % 5 + 1;

	char voice[50];
	memset(voice, '0', sizeof(voice));
	sprintf(voice, "assets/������Ч/%s��Ч%d.wav", name,num);
	PlaySound(voice, NULL, SND_FILENAME | SND_ASYNC);

}


//--------------------------------------------------------------------------------------

// ��������
void draw_Board()
{
	//�������̱���ͼ
	putimage(SPACE,SPACE,img[40]);
	//����������
	setlinecolor(BLACK);
	for (int i = 0; i < 15; i++)
	{
		line(SPACE, SPACE + i * 50, SPACE + 50 * (15 - 1), SPACE + i * 50);
		line(SPACE + i * 50, SPACE, SPACE + i * 50, SPACE + 50 * (15 - 1));
	}
	//���������ϵ�����ؼ���
	int r = 5;
	setfillcolor(BLACK);
	solidcircle(30 + 50 * 3, 30 + 50 * 3, r);
	solidcircle(30 + 50 * 11, 30 + 50 * 3, r);
	solidcircle(30 + 50 * 3,30 + 50 * 11, r);
	solidcircle(30 + 50 * 11,30 + 50 * 11 , r);
	solidcircle(30 + 50 * 7,30 + 50 * 7 , r);
}

//�����Ѿ����˵�����
void draw_Chess()
{
	//��������
	int x1, y1;
	for (int i = 0; i < 15; i++)
	{	
		y1 = SPACE + i * 50 ;
		for (int j = 0; j < 15; j++)
		{	
			x1 = SPACE + j * 50 ;
			
			//������ɫ��������
			if (board[i][j].color != '-')
			{
				if (board[i][j].color == 'b')
				{
					/*setfillcolor(BLACK);
					fillcircle(x1, y1, 25);*/
					//// ����һ���ӽ�Բ����״�ľ��μ�������
					//HRGN hRgn = CreateRoundRectRgn(x1 - 23, y1 - 23, x1 + 23, y1 + 23, 46, 46);
					//setcliprgn(hRgn); // �����μ�����������Ϊ��ǰ��ͼ�ļ�������
					//// �ڼ��������ڻ�������
					//putimage(x1 - 23, y1 - 23,img[member1 + 6]);
					//// �����������
					//setcliprgn(NULL);

					setfillcolor(BLACK);
					fillcircle(x1, y1, 24);
					putimage(x1 - 18, y1 - 18, img[member1 + 6]);
				}
				
				else if (board[i][j].color == 'w')
				{
					//setfillcolor(WHITE);
					//fillcircle(x1, y1, 25);
					//// ����һ���ӽ�Բ����״�ľ��μ�������
					//HRGN hRgn = CreateRoundRectRgn(x1 - 23, y1 - 23, x1 + 23, y1 + 23, 46, 46);
					//setcliprgn(hRgn); // �����μ�����������Ϊ��ǰ��ͼ�ļ�������
					//// �ڼ��������ڻ�������
					//putimage(x1 - 23, y1 - 23, img[member2 + 6]);
					//// �����������
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

//�ж�ʤ��
char is_Win()
{
	if (s->next == NULL)
	{//��ʼʱջ��ֱ�ӷ���
		return 0;
	}
	//��ջ��Ԫ����Ϊ���Ľ��б���
	//���ȷ��ʤ������һ���ǹ��������Ĺؼ�����˵����������Ϊ�����ıߵ㣬
	// ����������ĸ����ұ��ĸ��������ĸ��������ĸ�����Ϊ�����:
	// �������ң����ϵ��£������ϵ����£������µ������Ƿ�������
	chess ch = s->next->data;
	int row = ch.row_ind;
	int col = ch.col_ind;
	int left = col - 4, right = col + 4;
	int up = row - 4, down = row + 4;

	adjust(&left, &right, &up, &down);//��ɨ�跶Χ�������̣���������Խ��

	for (int i = left; i <= right - 4; i++)
	{//����
		if (board[row][i].color == board[row][i + 1].color &&
			board[row][i + 1].color == board[row][i + 2].color &&
			board[row][i + 2].color == board[row][i + 3].color &&
			board[row][i + 3].color == board[row][i + 4].color && board[row][i].color != '-')
		{
			return board[row][i].color;
		}
	}
	for (int i = up; i <= down - 4; i++)
	{//����
		if (board[i][col].color == board[i + 1][col].color &&
			board[i + 1][col].color == board[i + 2][col].color &&
			board[i + 2][col].color == board[i + 3][col].color &&
			board[i + 3][col].color == board[i + 4][col].color && board[i][col].color != '-')
		{
			return board[i][col].color;
		}
	}


	//б��
	int count = 0;//ÿ��������������ɫ��ȵ�ʱ���1�������ʱ����

	int space1 = col - left;
	int space2 = row - up;
	int space3 = right - col;
	int space4 = down - row;

	//���Խ���
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
		{//���Ķ���ͬ��˵�����ӳ��ߣ����ʤ��
			return board[i][j].color;
		}
	}

	//���Խ���
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
		{//���Ķ���ͬ��˵�����ӳ��ߣ����ʤ��
			return board[i][j].color;
		}
	}

	return '-';//����ʤ����������Ϸ
}

//��ɨ�跶Χ�������̣���������Խ��
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

//�ж�ƽ��
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

//���ذ���ͼǰ��һ����
void load_LastPreimage(linkqueue* q, int preframes, const char* name)
{

	char path[100]; // �����ļ�·��
	for (int i = 0; i < preframes; i++)
	{
		IMAGE* animation = new IMAGE();//����һ��ͼƬ����ָ�뱣��һ��ͼƬ
		memset(path, '0', sizeof(path));
		sprintf(path, "assets/����ͼ/%s����ͼ/���� %04d.jpg",
			name, i); // ��ʽ���ַ���
		loadimage(animation, path, 1067, 480);//��ָ��·���Ϳ��߼���ͼƬ
		enqueue(q, *animation);//��ͼƬ��Դ����һ�����
		delete animation;//�ͷ�ͼƬ��Դ,��Լ�ڴ�
	}
}


//�����������ͼ������ʤ��������
void draw_WinChara(linkqueue* q, const char* name)
{	
	int frames = 65;
	int preframes = 10;
	int speed = 30;
	int x = 157;
	int y = 148;
	int width = 1067;
	int height = 480;
	
	int current_frame = 0;//֡����
	int time_speed = 1000 / speed;//������Ҫ���Ƶ�ÿһ֡����ʱ��
	int frame_start;//��ʾÿһ֡��ʼ����ʱ��ʱ��
	int	frame_time;//��ʾÿһ֡����ʵ������ʱ��
	
	//���Ű���ͼ��Ч
	char music[50];
	memset(music, '0', sizeof(music));
	sprintf(music, "assets/����ͼ��Ч/%s����ͼ��Ч.wav",name);
	PlaySound(music, NULL, SND_FILENAME | SND_ASYNC);
	Sleep(200);

	for(int i = 0;i < frames;i++)
	{//ֻ����һ��
		frame_start = clock();

		IMAGE* animation = new IMAGE();
		*animation = dequeue(q);//�������֡
		// ����ͼ��
		if (q->head->next != NULL)
		{
			putimage(x, y, animation);
			FlushBatchDraw();
		}
		delete animation;//���Ѿ����ƺõ�ͼƬ��Դ�ͷŵ�
		animation = NULL;

		//֡�����ı�
		current_frame = ++current_frame % frames;

		//����֮��ʣ���ͼƬ����ÿ��ѭ������һ֡������һ֡
		char path[100]; // �����ļ�·��
		IMAGE* a = new IMAGE();
		memset(path, '0', sizeof(path));
		sprintf(path, "assets/����ͼ/%s����ͼ/���� %04d.jpg",
			name, (current_frame + preframes) % frames); // ��ʽ���ַ���
		loadimage(a, path, width, height);
		enqueue(q, *a);
		delete a;
		a = NULL;

		//���߿��˵�ʱ���Կ���֡��
		frame_time = clock() - frame_start;
		int temp = time_speed - frame_time;
		if (temp > 0)
		{
			Sleep(temp);
		}
	}

	//ͣ�������һ֡�ȴ���������
	char path[100]; // �����ļ�·��
	IMAGE* last_frame = new IMAGE();
	memset(path, '0', sizeof(path));
	sprintf(path, "assets/����ͼ/%s����ͼ/���� %04d.jpg",
		name, 64); // ��ʽ���ַ���
	loadimage(last_frame, path, width, height);
	putimage(x, y, last_frame);
	FlushBatchDraw();

	Sleep(500);
	delete last_frame;//���Ѿ����ƺõ�ͼƬ��Դ�ͷŵ�
	last_frame = NULL;
	cleardevice();
}

