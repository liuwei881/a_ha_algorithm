#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

int linked_insert()
{
	struct node* head, * p, * q, * t;
	int i, n, a;
	printf("��������Ĵ�С: ");
	scanf("%d", &n);
	head = NULL;//ͷָ���ʼΪ��
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		p = (struct node *)malloc(sizeof(struct node));
		p->data = a;
		p->next = NULL;
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			q->next = p;
		}
		q = p;
	}
	printf("������Ҫ�������: ");
	t = head;//������ͷ����ʼ����
	while (t != NULL)//��û�е�������β����ʱ��ѭ��
	{
		if (t->next->data > a)//�����ǰ�����һ������ֵ���ڴ��������, �������뵽�м�
		{
			p = (struct node*)malloc(sizeof(struct node));
			p->data = a;
			p->next = t->next;
			t->next = p;
			break;//��������˳�
		}
		t = t->next;
	}
	t = head;
	while (t != NULL)
	{
		printf("%d ", t->data);
		t = t->next;
	}

	p = head;
	struct node* tmp;
	while (p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
		tmp = NULL;
	}
	return 0;
}
