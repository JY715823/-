#pragma once//确保头文件只编译一次
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"winmm.lib")//播放音乐

using namespace std;

//头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include <graphics.h>
#include <easyx.h>//图形界面
#include <Windows.h>
#include <mmsystem.h>//播放音乐

#include <thread>//多线程

//---------------------------------------------------------------------------
//结构体类型

//棋子的结构体类型
typedef struct chess
{
	int row_ind;//棋子的行的下标
	int col_ind;//棋子的列的下标
	char color;//棋子的颜色
}chess;

//栈结点的结构体类型
typedef struct stackk
{
	chess data;//数据域
	struct stackk* next;//指向下一个结点的指针域
}snode, *stack;

//队列结点的结构体类型
typedef struct q
{
	IMAGE animation;//数据域——存一帧图片
	struct q* next;//指向下一个结点的指针
}animQnode, *animQueue;
//表示一个队列的结构体类型（可以直接定义头指针和尾指针）
typedef struct linkqueue
{
	animQueue head, rear;//队列的头指针和尾指针
}linkqueue;

//人物的结构体类型
typedef struct role
{
	const char* name;//人物的名字
	int frames;//人物动画的帧数
	int preframes;//人物动画预先加载的帧数
	int speed;//人物动画的帧率
	int current_frame;//只在游戏设置界面——人物选择的时候使用
	int width;//人物动画的宽度
	int height;//人物动画的高度
}role;

//玩家的结构体类型
typedef struct player
{
	role chara;//玩家所选角色
	char color;//玩家棋子的颜色
}player;
//---------------------------------------------------------------------------

//关键的变量

#define COL 15//棋盘的列数
#define ROW 15//棋盘的行数
#define SPACE 30//棋盘离边缘的距离

extern chess board[ROW][COL];//把棋盘中的所有棋子保存在一个二维数组之中

extern ExMessage msg;//定义消息结构体变量（五子棋小游戏只需接受鼠标信息）

extern stack s;//用于存棋的辅助栈

extern thread threads[18];//用于加载资源的线程数组

extern linkqueue* queue[30];//用于绘制动画的辅助队列

extern IMAGE* img[51];//用于加载图片资源的数组

//播放音乐相关变量
extern int current_music;//当前播放的音乐,初始值为4播放入场动画的音乐
extern bool is_playmusic;//判断是否播放音乐
extern bool control_single;//控制不重复播放音乐

//人物相关的变量
extern role roles[18];//保存所有人物
extern player player1, player2;
extern int playercount;//记录选择人物的数量，默认第一个选的是玩家一（黑子）
					//当到达两个时即选好人物，退出到游戏设置界面
extern int member1, member2;//两个玩家的人物对应编号

//---------------------------------------------------------------------------
//函数声明

//开始
void load_Image();//加载图片资源

void load_Resource();//加载游戏动画和图片资源

void load_BPreimage(linkqueue* q, int preframes, const char* name, int x, int y);// 加载开始部分动画前一部分帧

void load_Preimage(linkqueue* q, int preframes, const char* name, int x, int y);//加载人物动画前一部分帧

void load_FollowAnim(linkqueue* q, int* current_frame, int frames, int preframes,
	const char* name, int width, int height);//异步加载之后的动画（开始部分）

void load_FollowCharaAnim(linkqueue* q, int* current_frame, int frames, int preframes,
	const char* name, int width, int height);//异步加载之后的动画（人物动画）

void draw_Animation(linkqueue* q, int frames, int preframes, int speed, const char* name,
	int x, int y, int width, int height);//绘制两个加载动画

void draw_EnterAnimation(linkqueue* q, int frames, int preframes, int speed, const char* name,
	int x, int y, int width, int height);//绘制入场动画

void play_Music();//播放音乐

bool in_Button(int msg_x, int msg_y, int x, int y, int w, int h);//判断鼠标是否在一个按钮区域内

void drawImg(int x, int y, IMAGE* src);//PNG图片透明贴图

void free_Queue(linkqueue* q);//释放对应队列内存


//主菜单
int draw_MenuAnimation(linkqueue* q, int frames, int preframes, int speed, const char* name,
	int width, int height);//绘制主界面

void draw_MenuButton();//绘制主界面的按钮

int menu_Button(int msg_x, int msg_y);//保存鼠标在主界面点击的按钮


//游戏界面函数
void game_View(linkqueue* q_back, int frames, int preframes, int speed, const char* name,
	int width, int height);//游戏界面

void init_Board();//初始化棋盘

void drop_Chess(int msg_x, int msg_y, int* round);//落子

void play_CharaVoice(const char* name);//落子播放人物音效

void draw_Board();//绘制棋盘

void draw_Chess();//绘制已经下了的棋子

char is_Win();//判断胜负

void adjust(int* left, int* right, int* up, int* down);//将扫描范围放在棋盘，避免数组越界

bool is_draw();//判断平局

void load_LastPreimage(linkqueue* q, int preframes, const char* name);//加载奥义图前一部分

void draw_WinChara(linkqueue* q, const char* name);//绘制人物奥义图动画


//游戏设置
void game_Setting();//绘制游戏设置界面

void choose_Character();//绘制选择人物界面

void draw_Charahead(int x, int y, int i);//绘制人物头像

void draw_Character(int x, int y, int click_x, int click_y);//根据鼠标在的位置的人物绘制人物动画

//void draw_CharaAnim(linkqueue* q, int frames, int preframes, int speed, const char* name,
	//int width, int height, int button_x, int button_y);//绘制人物动画，并且点击可选择人物


//游戏说明及更多界面
void game_Instruction();//游戏说明界面

void game_Addition();


//栈相关操作的函数
void init_Stack();//初始化栈

void push(chess x);//入栈

chess pop();//出栈


//队列相关操作的函数
void init_Queue(linkqueue* q);//初始化队列

void enqueue(linkqueue* q,IMAGE x);//入队

IMAGE dequeue(linkqueue* q);//出队






