#include "head&func.h"

//��ʼ��ջ
void init_Stack()
{
	//����һ��ջ
	s = new snode();
	if (s == NULL)
	{
		printf("�ڴ����ʧ��\n");
		return;
	}
	s->next = NULL;

}

//��ջ
void push(chess x)
{
	//��һ����㱣����ջ����
	snode* pushnode = new snode();
	pushnode->data = x;
	pushnode->next = NULL;

	//��x���ڽ�����ͷ�����ջ��
	pushnode->next = s->next;
	s->next = pushnode;
}

////�п�
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

//��ջ
//�з���ֵ��������Ҫ���������
chess pop()
{
	//�����ջ�������
	snode* popnode = s->next;
	chess reg_chess = popnode->data;

	//��ջ
	s->next = popnode->next;

	//�ͷų�ջ���
	delete popnode;
	popnode = NULL;

	return reg_chess;
}
