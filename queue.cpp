#include "head&func.h"



//��ʼ������
 void init_Queue(linkqueue* q)
{
	q = new linkqueue();
	q->head = q->rear = new animQnode();
	if (q->head == NULL)
	{
		printf("�ڴ����ʧ��\n");
	}
	q->head->next = NULL;

}

//���
void enqueue(linkqueue* q,IMAGE x)
{
	animQnode* s = new animQnode();
	if (s == NULL)
	{
		printf("�ڴ����ʧ��\n");
		return;
	}
	s->animation = x;
	s->next = NULL;

	q->rear->next = s;
	q->rear = s;
}

//����
//������ֵ���Ա���Ƴ��ӵ�ͼƬ
IMAGE dequeue(linkqueue* q)
{
	IMAGE x;
	if (q->head->next == NULL)
	{
		printf("�ӿ�\n");
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

		//���������һ������Ҫ��βָ��ָ��ͷָ��
		if (q->rear == p)
		{
			q->head = q->rear;
		}

		//�ͷ�p�Ŀռ�
		delete p;
		p = NULL;

		return x;
	}
}