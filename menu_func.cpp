#include "head&func.h"


//����������
int draw_MenuAnimation(linkqueue* q, int frames, int preframes, int speed, const char* name,
	int width, int height)
{	//frames ��ʾ��֡����pre_frames��ʾ��ҪԤ�ȼ��ص�֡��,
	//speed��ʾ֡�ʣ�name��ʾ�ļ�����x��y��ʾͼƬ���Ͻǵĵ���������
	//width��height����غ�����x��y��ͬ

	int time_speed = 1000 / speed;//������Ҫ���Ƶ�ÿһ֡����ʱ��
	int current_frame = 0;//֡����

	int frame_start;//��ʾÿһ֡��ʼ����ʱ��ʱ��
	int	frame_time;//��ʾÿһ֡����ʵ������ʱ��

	while (true)
	{
		frame_start = clock();

		int x = 0;
		int y = 0;
		//���������Ϣ
		if (true)
		{
			//��ȡ�����Ϣ	
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
			IMAGE* animation = new IMAGE();
			*animation = dequeue(q);//�������֡
			if (q->head->next != NULL)
			{

				putimage(0, 0, animation);
			}
			delete animation;//���Ѿ����ƺõ�ͼƬ��Դ�ͷŵ�
			animation = NULL;

			draw_MenuButton();//���ư�ť

			//֡�����ı�
			current_frame = ++current_frame % frames;

			//���ر���ͼ֮��ʣ���ͼƬ����ÿ��ѭ������һ֡������һ֡
			thread load(load_FollowAnim, q, &current_frame, frames, preframes, name, width, height);
			load.detach();
		}


		//���ݴ���
		if (true)
		{
			//�������һ����ť�������������ƣ���ת��ť��Ӧ����
			if (x > 605 && x < 774 && y > 153 && y < 442 ||
				x > 577 && x < 807 && y > 464 && y < 606 ||
				x > 557 && x < 824 && y > 632 && y < 756 ||
				x > 2 && x < 281 && y > 578 && y < 750 ||
				x > 1080 && x < 1378 && y > 592 && y < 762)
			{
				return menu_Button(x, y);//���ص���İ�ť
			}
		}


		//���߿��˵�ʱ���Կ���֡��
		frame_time = clock() - frame_start;
		int temp = time_speed - frame_time;
		if (temp > 0)
		{
			Sleep(temp);
		}
	}
	Sleep(300);
}


//����������İ�ť
void draw_MenuButton()
{	
	//�������˵���������Ϸ���⡱
	drawImg(805, 15, img[1]);

	setfillcolor(RGB(195,154,102));
	//�������˵���������ʼ��Ϸ����ť
	fillroundrect(598, 146, 781, 449,10,10);
	putimage(605,153 ,img[2]);
	drawImg(605,153, img[3]);

	//�������˵���������Ϸ���á���ť
	fillroundrect(570, 457, 814, 613, 10, 10);
	putimage(577, 464, img[4]);
	drawImg(577, 464, img[5]);

	//�������˵���������Ϸ˵������ť
	fillroundrect(550, 625, 831, 763, 10, 10);
	putimage(557, 632, img[6]);
	drawImg(557, 632, img[7]);

	//�������˵�������������Ա�����ࡱ
	fillroundrect(5, 571, 298, 757, 10, 10);
	putimage(12, 578, img[8]);
	drawImg(12,578, img[9]);

	//�������˵��������˳���Ϸ����ť
	fillroundrect(1063, 585, 1375, 769, 10, 10);
	putimage(1070, 592, img[10]);
	drawImg(1070, 592, img[11]);

	FlushBatchDraw();
}


//������������˵�����İ�ť
int menu_Button(int msg_x, int msg_y)
{
	if (in_Button(msg_x,msg_y,605,153,169,289))
	{//1������Ϸ����
		return 1;
	}	
	if (in_Button(msg_x, msg_y, 577,464,230,142))
	{//2������Ϸ����
		return 2;
	}	
	if (in_Button(msg_x, msg_y, 557,632,267,124))
	{//3������Ϸ˵��
		return 3;
	}	
	if (in_Button(msg_x, msg_y, 2,578,279,172))
	{//4���뿪����Ա������
		return 4;
	}	
	if (in_Button(msg_x, msg_y, 1080,592,298,170))
	{//5�˳���Ϸ
		return 5;
	}

	return  0;
}



