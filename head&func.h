#pragma once//ȷ��ͷ�ļ�ֻ����һ��
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"winmm.lib")//��������

using namespace std;

//ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include <graphics.h>
#include <easyx.h>//ͼ�ν���
#include <Windows.h>
#include <mmsystem.h>//��������

#include <thread>//���߳�

//---------------------------------------------------------------------------
//�ṹ������

//���ӵĽṹ������
typedef struct chess
{
	int row_ind;//���ӵ��е��±�
	int col_ind;//���ӵ��е��±�
	char color;//���ӵ���ɫ
}chess;

//ջ���Ľṹ������
typedef struct stackk
{
	chess data;//������
	struct stackk* next;//ָ����һ������ָ����
}snode, *stack;

//���н��Ľṹ������
typedef struct q
{
	IMAGE animation;//�����򡪡���һ֡ͼƬ
	struct q* next;//ָ����һ������ָ��
}animQnode, *animQueue;
//��ʾһ�����еĽṹ�����ͣ�����ֱ�Ӷ���ͷָ���βָ�룩
typedef struct linkqueue
{
	animQueue head, rear;//���е�ͷָ���βָ��
}linkqueue;

//����Ľṹ������
typedef struct role
{
	const char* name;//���������
	int frames;//���ﶯ����֡��
	int preframes;//���ﶯ��Ԥ�ȼ��ص�֡��
	int speed;//���ﶯ����֡��
	int current_frame;//ֻ����Ϸ���ý��桪������ѡ���ʱ��ʹ��
	int width;//���ﶯ���Ŀ��
	int height;//���ﶯ���ĸ߶�
}role;

//��ҵĽṹ������
typedef struct player
{
	role chara;//�����ѡ��ɫ
	char color;//������ӵ���ɫ
}player;
//---------------------------------------------------------------------------

//�ؼ��ı���

#define COL 15//���̵�����
#define ROW 15//���̵�����
#define SPACE 30//�������Ե�ľ���

extern chess board[ROW][COL];//�������е��������ӱ�����һ����ά����֮��

extern ExMessage msg;//������Ϣ�ṹ�������������С��Ϸֻ����������Ϣ��

extern stack s;//���ڴ���ĸ���ջ

extern thread threads[18];//���ڼ�����Դ���߳�����

extern linkqueue* queue[30];//���ڻ��ƶ����ĸ�������

extern IMAGE* img[51];//���ڼ���ͼƬ��Դ������

//����������ر���
extern int current_music;//��ǰ���ŵ�����,��ʼֵΪ4�����볡����������
extern bool is_playmusic;//�ж��Ƿ񲥷�����
extern bool control_single;//���Ʋ��ظ���������

//������صı���
extern role roles[18];//������������
extern player player1, player2;
extern int playercount;//��¼ѡ�������������Ĭ�ϵ�һ��ѡ�������һ�����ӣ�
					//����������ʱ��ѡ������˳�����Ϸ���ý���
extern int member1, member2;//������ҵ������Ӧ���

//---------------------------------------------------------------------------
//��������

//��ʼ
void load_Image();//����ͼƬ��Դ

void load_Resource();//������Ϸ������ͼƬ��Դ

void load_BPreimage(linkqueue* q, int preframes, const char* name, int x, int y);// ���ؿ�ʼ���ֶ���ǰһ����֡

void load_Preimage(linkqueue* q, int preframes, const char* name, int x, int y);//�������ﶯ��ǰһ����֡

void load_FollowAnim(linkqueue* q, int* current_frame, int frames, int preframes,
	const char* name, int width, int height);//�첽����֮��Ķ�������ʼ���֣�

void load_FollowCharaAnim(linkqueue* q, int* current_frame, int frames, int preframes,
	const char* name, int width, int height);//�첽����֮��Ķ��������ﶯ����

void draw_Animation(linkqueue* q, int frames, int preframes, int speed, const char* name,
	int x, int y, int width, int height);//�����������ض���

void draw_EnterAnimation(linkqueue* q, int frames, int preframes, int speed, const char* name,
	int x, int y, int width, int height);//�����볡����

void play_Music();//��������

bool in_Button(int msg_x, int msg_y, int x, int y, int w, int h);//�ж�����Ƿ���һ����ť������

void drawImg(int x, int y, IMAGE* src);//PNGͼƬ͸����ͼ

void free_Queue(linkqueue* q);//�ͷŶ�Ӧ�����ڴ�


//���˵�
int draw_MenuAnimation(linkqueue* q, int frames, int preframes, int speed, const char* name,
	int width, int height);//����������

void draw_MenuButton();//����������İ�ť

int menu_Button(int msg_x, int msg_y);//������������������İ�ť


//��Ϸ���溯��
void game_View(linkqueue* q_back, int frames, int preframes, int speed, const char* name,
	int width, int height);//��Ϸ����

void init_Board();//��ʼ������

void drop_Chess(int msg_x, int msg_y, int* round);//����

void play_CharaVoice(const char* name);//���Ӳ���������Ч

void draw_Board();//��������

void draw_Chess();//�����Ѿ����˵�����

char is_Win();//�ж�ʤ��

void adjust(int* left, int* right, int* up, int* down);//��ɨ�跶Χ�������̣���������Խ��

bool is_draw();//�ж�ƽ��

void load_LastPreimage(linkqueue* q, int preframes, const char* name);//���ذ���ͼǰһ����

void draw_WinChara(linkqueue* q, const char* name);//�����������ͼ����


//��Ϸ����
void game_Setting();//������Ϸ���ý���

void choose_Character();//����ѡ���������

void draw_Charahead(int x, int y, int i);//��������ͷ��

void draw_Character(int x, int y, int click_x, int click_y);//��������ڵ�λ�õ�����������ﶯ��

//void draw_CharaAnim(linkqueue* q, int frames, int preframes, int speed, const char* name,
	//int width, int height, int button_x, int button_y);//�������ﶯ�������ҵ����ѡ������


//��Ϸ˵�����������
void game_Instruction();//��Ϸ˵������

void game_Addition();


//ջ��ز����ĺ���
void init_Stack();//��ʼ��ջ

void push(chess x);//��ջ

chess pop();//��ջ


//������ز����ĺ���
void init_Queue(linkqueue* q);//��ʼ������

void enqueue(linkqueue* q,IMAGE x);//���

IMAGE dequeue(linkqueue* q);//����






