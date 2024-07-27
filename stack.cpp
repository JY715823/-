#include "head&func.h"

//初始化栈
void init_Stack()
{
	//创建一个栈
	s = new snode();
	if (s == NULL)
	{
		printf("内存分配失败\n");
		return;
	}
	s->next = NULL;

}

//入栈
void push(chess x)
{
	//用一个结点保存入栈数据
	snode* pushnode = new snode();
	pushnode->data = x;
	pushnode->next = NULL;

	//将x所在结点进行头插插入栈中
	pushnode->next = s->next;
	s->next = pushnode;
}

////判空
//bool empty()
//{
//	if (s->next == NULL)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

//出栈
//有返回值，保存需要悔棋的棋子
chess pop()
{
	//保存出栈结点数据
	snode* popnode = s->next;
	chess reg_chess = popnode->data;

	//出栈
	s->next = popnode->next;

	//释放出栈结点
	delete popnode;
	popnode = NULL;

	return reg_chess;
}
