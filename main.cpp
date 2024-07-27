#include "head&func.h"

//���������������йؼ��ı�������ͷ�ļ���������ʵ���������ļ���ʹ����Щ����

#define COL 15//���̵�����
#define ROW 15//���̵�����
#define SPACE 30//�������Ե�ľ���

chess board[ROW][COL] = { 0 };//�������е��������ӱ�����һ����ά����֮��

ExMessage msg = { 0 };//������Ϣ�ṹ�������������С��Ϸֻ����������Ϣ��

stack s;//���ڴ���ĸ���ջ

thread threads[18];//���ڼ��ض�����Դ���߳�����

linkqueue* queue[30];//���ڻ��ƶ����ĸ�������

IMAGE* img[51];//���ڼ���ͼƬ��Դ������

//����������ر���
int current_music;//��ǰ���ŵ�����,��ʼֵΪ4�����볡����������
bool is_playmusic = true;//�ж��Ƿ񲥷�����
bool control_single = true;//���Ʋ��ظ���������

//������صı���
role roles[18];
player player1, player2;
int playercount = 0;//��¼ѡ�������������Ĭ�ϵ�һ��ѡ�������һ�����ӣ�
//����������ʱ��ѡ������˳�����Ϸ���ý���
int member1 = 0, member2 = 0;//������ҵ������Ӧ���

//-------------------------------------------------------------------------------------------


int main()
{
	//�������˵�ǰ��׼��
	if (true)
	{
		//�������Ķ��г�ʼ��
		for (int i = 0; i < 30; i++)
		{
			queue[i] = new linkqueue();
			queue[i]->head = queue[i]->rear = new animQnode();
			if (queue[i]->head == NULL)
			{
				printf("�ڴ����ʧ��\n");
				continue;
			}
			queue[i]->head->next = NULL;
		}

		//���س�ʼ��Դ
		load_Resource();


		//��ͼ�ν���
		initgraph(1383, 780);
		Sleep(1000);//�ȴ�������Դ


		//˫�����ͼ��ʼ
		BeginBatchDraw();

		//���Ƽ��ض���
		draw_Animation(queue[1], 385, 30, 60, "���ض���", 0, 0, 1382, 777);

		IMAGE* temp = new IMAGE();
		loadimage(temp, "assets/��ʼ����/���ض���/���� 0384.jpg", 1382, 777);
		//��������볡����
		while (true)
		{
			//�����ض���1�����һ֡ͣ����ֱ���������ʼ��Ϸ���򲥷ż��ض���2
			cleardevice();
			putimage(0, 0, temp);
			FlushBatchDraw();

			//��ȡ��Ϣ
			while (peekmessage(&msg))
			{
			}
			int x = 0;
			int y = 0;
			//�жϰ�����Ϣ
			if (msg.message == WM_LBUTTONDOWN)
			{//������ʱ����
				x = msg.x;
				y = msg.y;
				if (in_Button(x, y, 543, 639, 827 - 543, 705 - 639))
				{
					//���Ƶ����ʼ��Ϸ����Ķ���
					draw_Animation(queue[3], 80, 10, 15, "���ض���2", 0, 0, 1382, 777);

					//�����ض���2���һ֡ͣ�����볡������ʼ
					IMAGE* temp2 = new IMAGE();
					loadimage(temp2, "assets/��ʼ����/���ض���2/���� 0079.jpg", 1382, 777);
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
		//�ͷŲ�����Ҫ�Ķ��е��ڴ�
		free_Queue(queue[1]);
		free_Queue(queue[3]);


		//���ƽ�����Ϸ����
		cleardevice();
		draw_EnterAnimation(queue[2], 7051, 100, 30, "�볡����", 0, 0, 1382, 777);
		mciSendString("close assets/��������/bgm0.mp3", NULL, 0, NULL);//�˳��볡��������ͣ�볡������Ƶ
		free_Queue(queue[2]);//�ͷŵ��볡�����Ķ��е��ڴ�


		//��������ҳ�ʼ������Ĭ�����һΪ�������ˣ���Ҷ�Ϊ���ǲ�����
		player1.color = 'b';
		player1.chara = roles[6];
		player2.color = 'w';
		player2.chara = roles[7];
	}



	bool end = false;//�ж��Ƿ��˳��ı�־
	//������Ϸ������
	while (!end)
	{
		if (control_single)
		{
			current_music = 1;//Ĭ�ϴӵ�һ��bgm��ʼ
			play_Music();
			is_playmusic = true;
			control_single = false;//��ֹ�ظ�����
		}

		cleardevice();

		//����������
		int choice = draw_MenuAnimation(queue[5], 167, 15, 30, "�������ֽ", 1382, 775);

		//���ݲ�ͬ��choice���벻ͬ�Ľ���
		switch (choice)
		{
		case 1:
			init_Stack();//��ʼ��������ջ
			Sleep(300);
			game_View(queue[4], 519, 20, 30, "��Ϸ����", 1382, 777);
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
	
	//�ͷſռ�
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


	EndBatchDraw();//����˫�����ͼ
	closegraph();//�ر�ͼ�ν���

	return 0;
}