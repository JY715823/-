#include "head&func.h"

//��Ϸ���ý���
void game_Setting()
{
	while (true)
	{
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

		
		//����ͼ��
		if (true)
		{
			cleardevice();
			setfillcolor(RGB(195, 154, 102));

			putimage(0, 0, img[33]);//����ͼ

			fillroundrect(470, 32, 858, 263, 10, 10);
			putimage(477, 39, img[27]);//����ѡ��
			drawImg(477, 39, img[28]);//����ѡ������

			fillroundrect(491, 289, 819, 597, 10, 10);
			putimage(498, 296, img[29]);//��������ͼ
			drawImg(498, 296, img[30]);//������������
			drawImg(25 + 498, 182 + 296, img[31]);//�л�������������
			drawImg(199 + 498, 211 + 296, img[32]);//���ر�����������

			fillroundrect(1154, 642, 1333, 751, 10, 10);
			putimage(1161, 649, img[25]);//����������
			drawImg(1161, 649, img[26]);//�˳�����������

			FlushBatchDraw();

		}


		//���ݴ���
		if (true)
		{
			if (in_Button(x, y, 477, 39, 374, 217))
			{//��������ѡ�����
				choose_Character();
				playercount = 0;//����������㣬�Ա�����ٴ�ѡ������
			}
			else if (in_Button(x, y, 25 + 498, 182 + 296, 49, 101))
			{//�л�����
				//��ֹͣ��ǰ����
				char music[50];
				memset(music, '0', sizeof(music));
				sprintf(music, "close assets/��������/bgm%d.mp3", current_music);//�ر�����
				mciSendString(music, NULL, 0, NULL);
				Sleep(300);
				current_music = current_music % 5 + 1;//���µ�ǰ���֣��л�����һ��
				play_Music();//������һ��
			}
			else if (in_Button(x, y, 199 + 498, 211 + 296, 115, 48))
			{//��ͣ/���� ����
				if (is_playmusic)
				{//������ڲ��ž���ͣ
					char music[50];
					memset(music, '0', sizeof(music));
					sprintf(music, "pause assets/��������/bgm%d.mp3", current_music);//��ͣ����
					mciSendString(music, NULL, 0, NULL);
					is_playmusic = false;
					Sleep(200);
				}
				else
				{//�������ͣ�Ͳ���
					play_Music();
					is_playmusic = true;
					Sleep(200);
				}
			}
			else if (in_Button(x, y,1161,649,165,95))
			{//�˳���Ϸ���ý��棬����������
				Sleep(300);
				return;
			}
		}
	}
}

//----------------------------------------------------------------------------------

//����ѡ�����
void choose_Character()
{
	int frame_start;//��ʾÿһ֡��ʼ����ʱ��ʱ��
	int	frame_time;//��ʾÿһ֡����ʵ������ʱ��
	int time_speed = 1000 / 30;//������Ҫ���Ƶ�ÿһ֡����ʱ��

	playercount = 0;
	int flag = 0;
	for (int i = 6; i <= 17; i++)
	{//��ÿ����ɫ�ĵ�ǰ֡��ʼ��Ϊ0
		roles[i].current_frame = 0;
	}


	while (true)
	{
		frame_start = clock();

		int x = 0;
		int y = 0;
		int click_x = 0;
		int click_y = 0;
		//��ȡ�����Ϣ
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


		//����ͼ��
		if (true)
		{
			cleardevice();
			setfillcolor(RGB(195, 154, 102));

			putimage(0, 0, img[34]);//����ͼ

			fillroundrect(1154, 642, 1333, 751, 10, 10);
			putimage(1161, 649, img[25]);//����������
			drawImg(1161, 649, img[26]);//��������������
			//����ͷ��
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

			//���������������Ķ��������Ҹ��ݵ����λ��ȷ������
			draw_Character(x, y, click_x, click_y);

			//������Ҿ���ͼ
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


		//���ݴ���	
		if (in_Button(click_x, click_y, 1161, 649, 165, 95))
		{//�˳���Ϸ���ý��棬����������
			Sleep(500);
			return;
		}
		

		//���߿��˵�ʱ���Կ���֡��
		frame_time = clock() - frame_start;
		int temp = time_speed - frame_time;
		if (temp > 0)
		{
			Sleep(temp);
		}
	}
}

//��������ͷ��
void draw_Charahead(int x, int y,int i)
{
	////���Ʊ���Բ��
	//setfillcolor(WHITE);
	//solidcircle(x + 23, y + 23, 27);
	////����һ���ӽ�Բ����״�ľ��μ�������
	//HRGN hRgn = CreateRoundRectRgn(x, y, x + 46, y + 46, 46, 46);
	//setcliprgn(hRgn); // �����μ�����������Ϊ��ǰ��ͼ�ļ�������
	//// �ڼ��������ڻ���ͼ�λ�ͼƬ
	//putimage(x, y, img[i]);
	//// �����������
	//setcliprgn(NULL);

	setfillcolor(WHITE);
	solidcircle(x + 18, y + 18, 26);
	putimage(x, y, img[i]);

}

//��������ڵ�λ�õ�����������ﶯ��
void draw_Character(int x, int y, int click_x, int click_y)
{
	int chara_num = 0;
	
	//�ҵ����������������
	if (true)
	{
		if (in_Button(x, y, 886, 28,46,46))
		{//��������
			chara_num = 6;
		}
		else if (in_Button(x, y, 789, 56, 46, 46))
		{//���ǲ�����
			chara_num = 7;
		}
		else if (in_Button(x, y, 691, 102, 46, 46))
		{//��Ұӣ
			chara_num = 8;
		}
		else if (in_Button(x, y, 614, 152, 46, 46))
		{//���ǲ���
			chara_num = 9;
		}
		else if (in_Button(x, y, 517, 203, 46, 46))
		{//���ǲ�����
			chara_num = 10;
		}
		else if (in_Button(x, y, 442, 272, 46, 46))
		{//���ǲ���
			chara_num = 11;
		}
		else if (in_Button(x, y, 540, 309, 46, 46))
		{//��ľ������
			chara_num = 12;
		}
		else if (in_Button(x, y, 617, 346, 46, 46))
		{//���ؿ�
			chara_num = 13;
		}
		else if (in_Button(x, y, 719, 317, 46, 46))
		{//����Ҳ
			chara_num = 14;
		}
		else if (in_Button(x, y, 792, 263, 46, 46))
		{//ǧ������
			chara_num = 15;
		}
		else if (in_Button(x, y, 766, 174, 46, 46))
		{//ǧ�����
			chara_num = 16;
		}
		else if (in_Button(x, y, 668, 225, 46, 46))
		{//����ˮ��
			chara_num = 17;
		}
		else
		{
			return;
		}
	}

	//������������ʱ��ѡ������������1
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
	*animation = dequeue(queue[chara_num]);//�������֡
	// ����ͼ��
	if (queue[chara_num]->head->next != NULL)
	{
		putimage(403, 323 + 80, animation);
	}
	delete animation;//���Ѿ����ƺõ�ͼƬ��Դ�ͷŵ�
	animation = NULL;

	thread load(load_FollowCharaAnim, queue[chara_num], &roles[chara_num].current_frame,
		roles[chara_num].frames, roles[chara_num].preframes, roles[chara_num].name,
		roles[chara_num].width, roles[chara_num].height);
	load.detach();

}

//�����Ļ������ﶯ������
////�������ﶯ��
//void draw_CharaAnim(linkqueue* q, int frames, int preframes, int speed, const char* name,
//	int width, int height,int button_x,int button_y)
//{	//frames ��ʾ��֡����pre_frames��ʾ��ҪԤ�ȼ��ص�֡��,
//	//speed��ʾ֡�ʣ�name��ʾ�ļ�����x��y��ʾͼƬ���Ͻǵĵ���������
//	//width��height����غ�����x��y��ͬ
//
//	int time_speed = 1000 / speed;//������Ҫ���Ƶ�ÿһ֡����ʱ��
//	int current_frame = 0;//֡����
//
//	int frame_start;//��ʾÿһ֡��ʼ����ʱ��ʱ��
//	int	frame_time;//��ʾÿһ֡����ʵ������ʱ��
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
//		//������Ϣ
//		int xi = 0;
//		int yi = 0;
//		while (peekmessage(&msg))
//		{}
//
//		if (msg.message == WM_LBUTTONDOWN &&
//			in_Button(xi, yi, button_x, button_y, 50, 50))
//		{//���������ͷ�����������ѡ��
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
//		// ����ͼ��
//		IMAGE* animation = new IMAGE();
//		*animation = dequeue(q);//�������֡
//		if (q->head->next != NULL)
//		{
//			putimage(403, 323+30, animation);
//			//FlushBatchDraw();
//		}
//		delete animation;//���Ѿ����ƺõ�ͼƬ��Դ�ͷŵ�
//
//		//֡�����ı�
//		current_frame = ++current_frame % frames;
//
//		//����֮��ʣ���ͼƬ����ÿ��ѭ������һ֡������һ֡
//		//char path[100]; // �����ļ�·��
//		//IMAGE* a = new IMAGE();
//		//memset(path, '0', sizeof(path));
//		//sprintf(path, "assets/���ﶯ��/%s/���� %04d.jpg",
//		//	name, (current_frame + preframes) % frames); // ��ʽ���ַ���
//		//loadimage(a, path, width, height);
//		//enqueue(q, *a);
//		//delete a;
//		
//		thread loadfollow(load_FollowCharaAnim,q, &current_frame, roles[rolenum].frames,
//			roles[rolenum].preframes,roles[rolenum].name,roles[rolenum].width, roles[rolenum].height);
//		loadfollow.detach();
//
//		//���߿��˵�ʱ���Կ���֡��
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
