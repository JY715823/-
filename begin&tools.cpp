#include "head&func.h"

//����ͼƬ��Դ
void load_Image()
{
	//��ʼͼƬ����
	for (int i = 0; i <= 51; i++)
	{
		img[i] = new IMAGE();
	}


	//�������˵���������Ϸ���⡱
	loadimage(img[1], "assets/ͼƬ/��Ϸ��������.png", 123, 147);

	//�������˵���������ʼ��Ϸ����ť
	loadimage(img[2], "assets/ͼƬ/��ʼ��Ϸ.jpg", 169, 289);
	loadimage(img[3], "assets/ͼƬ/��ʼ��Ϸ����.png", 169, 289);

	//�������˵���������Ϸ���á���ť
	loadimage(img[4], "assets/ͼƬ/��Ϸ����.jpg", 230, 142);
	loadimage(img[5], "assets/ͼƬ/��Ϸ��������.png", 230, 142);

	//�������˵���������Ϸ˵������ť
	loadimage(img[6], "assets/ͼƬ/��Ϸ˵��.jpg", 267, 124);
	loadimage(img[7], "assets/ͼƬ/��Ϸ˵������.png", 267, 124);

	//�������˵�������������Ա�����ࡱ
	loadimage(img[8], "assets/ͼƬ/������Ա������.jpg", 279, 172);
	loadimage(img[9], "assets/ͼƬ/������Ա����������.png", 279, 172);

	//�������˵��������˳���Ϸ����ť
	loadimage(img[10], "assets/ͼƬ/�˳���Ϸ.jpg", 298, 170);
	loadimage(img[11], "assets/ͼƬ/�˳���Ϸ����.png", 298, 170);

	int wid = 36;
	int hei = 36;
	loadimage(img[12], "assets/ͼƬ/��������ͷ��.jpg",wid,hei);
	loadimage(img[13], "assets/ͼƬ/���ǲ�����ͷ��.jpg", wid, hei);
	loadimage(img[14], "assets/ͼƬ/��Ұӣͷ��.jpg", wid, hei);
	loadimage(img[15], "assets/ͼƬ/���ǲ���ͷ��.jpg", wid, hei);
	loadimage(img[16], "assets/ͼƬ/���ǲ�����ͷ��.jpg", wid, hei);
	loadimage(img[17], "assets/ͼƬ/���ǲ���ͷ��.jpg", wid, hei);
	loadimage(img[18], "assets/ͼƬ/��ľ������ͷ��.jpg", wid, hei);
	loadimage(img[19], "assets/ͼƬ/���ؿ�ͷ��.jpg", wid, hei);
	loadimage(img[20], "assets/ͼƬ/����Ҳͷ��.jpg", wid, hei);
	loadimage(img[21], "assets/ͼƬ/ǧ������ͷ��.jpg", wid, hei);
	loadimage(img[22], "assets/ͼƬ/ǧ�����ͷ��.jpg", wid, hei);
	loadimage(img[23], "assets/ͼƬ/����ˮ��ͷ��.jpg", wid, hei);

	//���ط��������水ť
	loadimage(img[25], "assets/ͼƬ/�˳���Ϸ.jpg", 165, 95);
	loadimage(img[26], "assets/ͼƬ/��������������.png", 165, 95);

	//��������ѡ��Ͳ���������Դ
	loadimage(img[27], "assets/ͼƬ/����ѡ��.jpg",374 , 217);
	loadimage(img[28], "assets/ͼƬ/����ѡ������.png", 374, 217);
	loadimage(img[29], "assets/ͼƬ/��������.jpg",314 ,294 );
	loadimage(img[30], "assets/ͼƬ/������������.png",314 ,294 );
	loadimage(img[31], "assets/ͼƬ/���������л�����.png",49 ,101 );
	loadimage(img[32], "assets/ͼƬ/�������ֿ�������.png", 115,48 );

	//������Ϸ���ý��汳��ͼ
	loadimage(img[33], "assets/ͼƬ/��Ϸ����.jpg", 1382, 777);
	loadimage(img[34], "assets/ͼƬ/����ѡ��.jpg", 1382, 777);

	//������Ϸ˵������ͼ
	loadimage(img[35], "assets/ͼƬ/��Ϸ˵��.jpg", 1382, 777);
	loadimage(img[36], "assets/ͼƬ/��Ϸ˵������.png", 1382, 777);
	
	//����������Ա�����౳��ͼ
	loadimage(img[37], "assets/ͼƬ/������Ա������.jpg", 1382, 777);
	loadimage(img[38], "assets/ͼƬ/������Ա����������.png", 1382, 777);
	//loadimage(img[39], "assets/ͼƬ/��������.png", 1382, 777); 

	//�������̱���ͼ
	loadimage(img[40], "assets/ͼƬ/���̱���.jpg", 700, 700);

	//���ص�ǰ�غ�ͼ
	loadimage(img[41], "assets/ͼƬ/��ǰ�غ�.jpg",207,117);
	loadimage(img[42], "assets/ͼƬ/��ǰ�غ�����.png", 207,117);

	//���ػ���ͼ
	loadimage(img[43], "assets/ͼƬ/����.jpg", 170,115);
	loadimage(img[44], "assets/ͼƬ/��������.png", 170,115);

	//����׼������ͼ
	loadimage(img[46], "assets/ͼƬ/���һ����.jpg", 160, 293);
	loadimage(img[47], "assets/ͼƬ/���һ��������.png", 160, 293);
	loadimage(img[48], "assets/ͼƬ/��Ҷ�����.jpg", 147, 314);
	loadimage(img[49], "assets/ͼƬ/��Ҷ���������.png", 147, 314);

	//����ƽ�ְ���ͼ
	loadimage(img[50], "assets/ͼƬ/ƽ�ְ���ͼ.jpg", 1055, 511);


	//��ǰ�򿪱��������ļ�
	for (int i = 0; i <= 5; i++)
	{
		char path[100];
		memset(path, 0, sizeof(path));
		sprintf(path, "open assets/��������/bgm%d.mp3", i);
		mciSendString(path, NULL, 0, NULL);
	}
}

//������Ϸ������ͼƬ��Դ
void load_Resource()
{	
	//��ʼ���������
	if (true)
	{
		roles[6].name = "��������"; roles[6].frames = 548; roles[6].preframes = 20;
		roles[6].width = 575, roles[6].height = 323; roles[6].speed = 30;

		roles[7].name = "���ǲ�����"; roles[7].frames = 87; roles[7].preframes = 5;
		roles[7].width = 345, roles[7].height = 345; roles[7].speed = 30;

		roles[8].name = "��Ұӣ"; roles[8].frames = 324; roles[8].preframes = 15;
		roles[8].width = 575, roles[8].height = 323; roles[8].speed = 30;

		roles[9].name = "���ǲ���"; roles[9].frames = 87; roles[9].preframes = 15;
		roles[9].width = 575, roles[9].height = 323; roles[9].speed = 30;

		roles[10].name = "���ǲ�����"; roles[10].frames = 290; roles[10].preframes = 20;
		roles[10].width = 575, roles[10].height = 323; roles[10].speed = 30;

		roles[11].name = "���ǲ���"; roles[11].frames = 292; roles[11].preframes = 20;
		roles[11].width = 575, roles[11].height = 323; roles[11].speed = 30;

		roles[12].name = "��ľ������"; roles[12].frames = 308; roles[12].preframes = 20;
		roles[12].width = 575, roles[12].height = 323; roles[12].speed = 30;

		roles[13].name = "���ؿ�"; roles[13].frames = 596; roles[13].preframes = 20;
		roles[13].width = 575, roles[13].height = 323; roles[13].speed = 30;

		roles[14].name = "����Ҳ"; roles[14].frames = 186; roles[14].preframes = 10;
		roles[14].width = 575, roles[14].height = 323; roles[14].speed = 30;

		roles[15].name = "ǧ������"; roles[15].frames = 221; roles[15].preframes = 20;
		roles[15].width = 575, roles[15].height = 323; roles[15].speed = 30;

		roles[16].name = "ǧ�����"; roles[16].frames = 231; roles[16].preframes = 20;
		roles[16].width = 575, roles[16].height = 323; roles[16].speed = 30;

		roles[17].name = "����ˮ��"; roles[17].frames = 344; roles[17].preframes = 20;
		roles[17].width = 575, roles[17].height = 323; roles[17].speed = 30;
	}

	

	//�߳�1���ؼ��ض���
	threads[1] = thread(load_BPreimage, queue[1], 20, "���ض���", 1382, 777);
	threads[1].detach();

	//�߳�2�����볡����
	threads[2] = thread(load_BPreimage, queue[2], 100, "�볡����", 1382, 777);
	threads[2].detach();

	//�߳�3���ؼ��ض���2
	threads[3] = thread(load_BPreimage, queue[3], 10, "���ض���2", 1382, 777);
	threads[3].detach();

	//�߳�4������Ϸ����
	threads[4] = thread(load_BPreimage, queue[4], 20, "��Ϸ����", 1382, 777);
	threads[4].detach();

	//�߳�5�����������ֽ
	threads[5] = thread(load_BPreimage, queue[5], 10, "�������ֽ", 1382, 777);
	threads[5].detach();
	
	//�߳�0����ͼƬ��Դ
	threads[0] = thread(load_Image);
	threads[0].detach();

	//�߳�6����������������
	threads[6] = thread(load_Preimage, queue[6], roles[6].preframes , roles[6].name, roles[6].width, roles[6].height);
	threads[6].detach();
	
	//�߳�7�������ǲ���������
	threads[7] = thread(load_Preimage, queue[7], roles[7].preframes, roles[7].name, roles[7].width, roles[7].height);
	threads[7].detach();
	
	//�߳�8���ش�Ұӣ����
	threads[8] = thread(load_Preimage, queue[8], roles[8].preframes, roles[8].name, roles[8].width, roles[8].height);
	threads[8].detach();
	
	//�߳�9�������ǲ�������
	threads[9] = thread(load_Preimage, queue[9], roles[9].preframes, roles[9].name, roles[9].width, roles[9].height);
	threads[9].detach();
	
	//�߳�10�������ǲ���������
	threads[10] = thread(load_Preimage, queue[10], roles[10].preframes, roles[10].name, roles[10].width, roles[10].height);
	threads[10].detach();
	
	//�߳�11�������ǲ�������
	threads[11] = thread(load_Preimage, queue[11], roles[11].preframes, roles[11].name, roles[11].width, roles[11].height);
	threads[11].detach();
	
	//�߳�12������ľ������������
	threads[12] = thread(load_Preimage, queue[12], roles[12].preframes, roles[12].name, roles[12].width, roles[12].height);
	threads[12].detach();
	
	//�߳�13�������ؿ�����
	threads[13] = thread(load_Preimage, queue[13], roles[13].preframes, roles[13].name, roles[13].width, roles[13].height);
	threads[13].detach();
	
	//�߳�14��������Ҳ����
	threads[14] = thread(load_Preimage, queue[14], roles[14].preframes, roles[14].name, roles[14].width, roles[14].height);
	threads[14].detach();
	
	//�߳�15����ǧ����������
	threads[15] = thread(load_Preimage, queue[15], roles[15].preframes, roles[15].name, roles[15].width, roles[15].height);
	threads[15].detach();
	
	//�߳�16����ǧ���������
	threads[16] = thread(load_Preimage, queue[16], roles[16].preframes, roles[16].name, roles[16].width, roles[16].height);
	threads[16].detach();
	
	//�߳�17���ز���ˮ������
	threads[17] = thread(load_Preimage, queue[17], roles[17].preframes, roles[17].name, roles[17].width, roles[17].height);
	threads[17].detach();

}


//���ؿ�ʼ���ֶ���ǰ��һ����֡
void load_BPreimage(linkqueue* q, int preframes, const char* name, int x, int y)
{//pre_frames��ʾ��ҪԤ�ȼ��ص�֡����name��ʾ�ļ�����x��y��ʾͼƬ���ô��ڵĿ�͸�

	char path[100]; // �����ļ�·��
	for (int i = 0; i < preframes; i++)
	{
		IMAGE* animation = new IMAGE();//����һ��ͼƬ����ָ�뱣��һ��ͼƬ
		memset(path, '0', sizeof(path));
		sprintf(path, "assets/��ʼ����/%s/���� %04d.jpg",
				name, i); // ��ʽ���ַ���
		loadimage(animation, path, x, y);//��ָ��·���Ϳ��߼���ͼƬ
		enqueue(q, *animation);//��ͼƬ��Դ����һ�����
		delete animation;//�ͷ�ͼƬ��Դ,��Լ�ڴ�
		animation = NULL;
	}
}

//�������ﶯ��ǰ��һ����֡
void load_Preimage(linkqueue* q, int preframes, const char* name, int x, int y)
{//pre_frames��ʾ��ҪԤ�ȼ��ص�֡����name��ʾ�ļ�����x��y��ʾͼƬ���ô��ڵĿ�͸�

	char path[100]; // �����ļ�·��
	for (int i = 0; i < preframes; i++)
	{
		IMAGE* animation = new IMAGE();//����һ��ͼƬ����ָ�뱣��һ��ͼƬ
		memset(path, '0', sizeof(path));
		sprintf(path, "assets/���ﶯ��/%s/���� %04d.jpg",
			name, i); // ��ʽ���ַ���
		loadimage(animation, path, x, y);//��ָ��·���Ϳ��߼���ͼƬ
		enqueue(q, *animation);//��ͼƬ��Դ����һ�����
		delete animation;//�ͷ�ͼƬ��Դ,��Լ�ڴ�
		animation = NULL;
	}
}

//-----------------------------------------------------------------------------------------------

//�첽���ؿ�ʼ����֮��Ķ���
void load_FollowAnim(linkqueue* q, int* current_frame, int frames, int preframes,
	const char* name, int width, int height)//����
{
	//���ر���ͼ֮��ʣ���ͼƬ����ÿ��ѭ������һ֡������һ֡
	char path[100]; // �����ļ�·��
	IMAGE* a = new IMAGE();
	memset(path, '0', sizeof(path));
	sprintf(path, "assets/��ʼ����/%s/���� %04d.jpg",
		name, ((*current_frame) + preframes) % frames); // ��ʽ���ַ���
	loadimage(a, path, width, height);
	enqueue(q, *a);
	delete a;
	a = NULL;
}

//�첽��������֮��Ķ���
void load_FollowCharaAnim(linkqueue* q, int* current_frame, int frames, int preframes,
	const char* name, int width, int height)//����
{
	//���ر���ͼ֮��ʣ���ͼƬ����ÿ��ѭ������һ֡������һ֡
	char path[100]; // �����ļ�·��
	IMAGE* a = new IMAGE();
	memset(path, '0', sizeof(path));
	sprintf(path, "assets/���ﶯ��/%s/���� %04d.jpg",
		name, (*current_frame + preframes) % frames); // ��ʽ���ַ���
	loadimage(a, path, width, height);
	enqueue(q, *a);
	delete a;
	a = NULL;
}

//-----------------------------------------------------------------------------------------------

//�����������ض���
void draw_Animation(linkqueue* q, int frames, int preframes, int speed, const char* name,
				int x, int y, int width, int height)
{	//frames ��ʾ��֡����pre_frames��ʾ��ҪԤ�ȼ��ص�֡��,
	//speed��ʾ֡�ʣ�name��ʾ�ļ�����x��y��ʾͼƬ���Ͻǵĵ���������
	//width��height����غ�����x��y��ͬ

	int time_speed = 1000 / speed;//������Ҫ���Ƶ�ÿһ֡����ʱ��
	int current_frame = 0;//֡����

	int frame_start;//��ʾÿһ֡��ʼ����ʱ��ʱ��
	int	frame_time;//��ʾÿһ֡����ʵ������ʱ��
	
	for(int i = 0;i < frames;i++)
	{//ֻ����һ��
		frame_start = clock();


		IMAGE* animation = new IMAGE();
		*animation = dequeue(q);//�������֡
		// ����ͼ��
		if (q->head->next != NULL)
		{
			cleardevice();
			putimage(x, y, animation);
			FlushBatchDraw();
		}
		delete animation;//���Ѿ����ƺõ�ͼƬ��Դ�ͷŵ�
		animation = NULL;

		//֡�����ı�
		current_frame = ++current_frame % frames;
		
		//����֮��ʣ���ͼƬ����ÿ��ѭ������һ֡������һ֡
		thread load(load_FollowAnim, q, &current_frame,frames, preframes, name, width, height);
		load.detach();

		//���߿��˵�ʱ���Կ���֡��
		frame_time = clock() - frame_start;
		int temp = time_speed - frame_time;
		if (temp > 0)
		{
			Sleep(temp);
		}
	}
	Sleep(500);//�ȴ�δ��ɵ��߳�
}

//�����볡����
void draw_EnterAnimation(linkqueue* q, int frames, int preframes, int speed, const char* name,
	int x, int y, int width, int height)
{
	//���ű�������
	current_music = 0;
	play_Music();
	Sleep(300);

	cleardevice();
	int time_speed = 1000 / speed;//������Ҫ���Ƶ�ÿһ֡����ʱ��
	int current_frame = 0;//֡����

	int frame_start;//��ʾÿһ֡��ʼ����ʱ��ʱ��
	int	frame_time;//��ʾÿһ֡����ʵ������ʱ��

	
	for (int i = 0; i < frames; i++)
	{
		frame_start = clock();

		//���������Ϣ���ж��Ƿ�Ҫ�ж�
		if (true)
		{
			while (peekmessage(&msg))
			{//��ȡ�����Ϣ
				if (msg.message == WM_LBUTTONDOWN)
				{
					return;
				}
			}
		}


		//����ͼ��
		if (true)
		{
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
			thread load(load_FollowAnim, q, &current_frame, frames,preframes, name, width, height);
			load.detach();
		}


		//���߿��˵�ʱ���Կ���֡��
		frame_time = clock() - frame_start;
		int temp = time_speed - frame_time;
		if (temp > 0)
		{
			Sleep(temp);
		}
	}

	IMAGE* temp = new IMAGE();
	loadimage(temp, "assets/��ʼ����/�볡����/���� 7050.jpg", 1382, 777);
	cleardevice();
	putimage(0, 0, temp);
	FlushBatchDraw();
	delete temp;
	temp = NULL;
	Sleep(1500);
}

//-----------------------------------------------------------------------------------------------

//һЩ���ߺ���
//��������
void play_Music()
{
	char path[100];
	memset(path, 0, sizeof(path));
	sprintf(path, "play assets/��������/bgm%d.mp3",current_music);//wav�ļ���֧���ظ�����
	mciSendString(path, NULL, 0, NULL);

	if (current_music != 0)
	{//����һ�㱳�����ֵ�����
		memset(path, 0, sizeof(path));
		sprintf(path, "setaudio assets/��������/bgm%d.mp3 volume to %d",current_music,580);
		mciSendString(path, NULL, 0, NULL);
	}
}

//�ж�����Ƿ���ָ���ľ��ΰ�ť������
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


//PNGͼƬ͸����ͼ���ֳɵģ�
void drawImg(int x, int y, IMAGE* src)
{
	// ������ʼ��
	DWORD* pwin = GetImageBuffer();			//���ڻ�����ָ��
	DWORD* psrc = GetImageBuffer(src);		//ͼƬ������ָ��
	int win_w = getwidth();				//���ڿ��
	int win_h = getheight();
	int src_w = src->getwidth();				//ͼƬ���
	int src_h = src->getheight();

	// ������ͼ��ʵ�ʳ���
	int real_w = (x + src_w > win_w) ? win_w - x : src_w;			// �������ұ߽�
	int real_h = (y + src_h > win_h) ? win_h - y : src_h;			// �������±߽�
	if (x < 0) { psrc += -x;			real_w -= -x;	x = 0; }	// ��������߽�
	if (y < 0) { psrc += (src_w * -y);	real_h -= -y;	y = 0; }	// �������ϱ߽�


	// ������ͼ��ʼλ��
	pwin += (win_w * y + x);

	// ʵ��͸����ͼ
	for (int iy = 0; iy < real_h; iy++)
	{
		for (int ix = 0; ix < real_w; ix++)
		{
			byte a = (byte)(psrc[ix] >> 24);//����͸��ͨ����ֵ[0,256) 0Ϊ��ȫ͸�� 255Ϊ��ȫ��͸��
			if (a > 100)
			{
				pwin[ix] = psrc[ix];
			}
		}
		//������һ��
		pwin += win_w;
		psrc += src_w;
	}
}

//�ͷŶ���
void free_Queue(linkqueue* q)
{
	animQnode* temp1 = q->head->next;
	animQnode* temp2 = NULL;
	while (temp1 != NULL)
	{//�����߳�
		temp2 = temp1;
		temp1 = temp1->next;
		delete temp2;
		temp2 = NULL;
	}
}
