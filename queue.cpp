#include "head&func.h"



//初始化队列
 void init_Queue(linkqueue* q)
{
	q = new linkqueue();
	q->head = q->rear = new animQnode();
	if (q->head == NULL)
	{
		printf("内存分配失败\n");
	}
	q->head->next = NULL;

}

//入队
void enqueue(linkqueue* q,IMAGE x)
{
	animQnode* s = new animQnode();
	if (s == NULL)
	{
		printf("内存分配失败\n");
		return;
	}
	s->animation = x;
	s->next = NULL;

	q->rear->next = s;
	q->rear = s;
}

//出队
//带返回值，以便绘制出队的图片
IMAGE dequeue(linkqueue* q)
{
	IMAGE x;
	if (q->head->next == NULL)
	{
		printf("队空\n");
		return 0;
	}
	else
	{
		animQnode* p = q->head->next;
		x = p->animation;
		if (p->next == NULL)
		{
			q->head->next = NULL;
		}
		else
		{
			q->head->next = p->next;
		}

		//当出队最后一个结点后要把尾指针指回头指针
		if (q->rear == p)
		{
			q->head = q->rear;
		}

		//释放p的空间
		delete p;
		p = NULL;

		return x;
	}
}