#include "head&func.h"
 
 
//������Ϸ˵������
void game_Instruction()
{
	while (true)
	{
		//������Ϣ
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

		//����
		cleardevice();
		setfillcolor(RGB(195, 154, 102));

		putimage(0, 0, img[35]);//����ͼ
		drawImg(0, 0, img[36]);//��Ϸ˵������

		fillroundrect(1154, 642, 1333, 751, 10, 10);
		putimage(1161, 649, img[25]);//����������
		drawImg(1161, 649, img[26]);//�˳�����������
		FlushBatchDraw();

		//���ݴ���
		if (in_Button(x, y, 1161, 649, 165, 95))
		{//����������
			Sleep(1000);
			return;
		}
	}
}

//����������Ա���������
void game_Addition()
{
	while (true)
	{
		//������Ϣ
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

		//����
		cleardevice();
		setfillcolor(RGB(195, 154, 102));

		putimage(0, 0, img[37]);//����ͼ

		drawImg(0, 0, img[38]);//������Ա����ͼ
		//drawImg(0, 0, img[39]);//������������ͼ
		
		fillroundrect(1154, 642, 1333, 751, 10, 10);
		putimage(1161, 649, img[25]);//����������
		drawImg(1161, 649, img[26]);//�˳�����������

		FlushBatchDraw();

		//���ݴ���
		if (in_Button(x, y, 1161, 649, 165, 95))
		{//����������
			Sleep(1000);
			return;
		}
	}
}

