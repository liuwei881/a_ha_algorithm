#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

int linked()
{
	struct node* head, * p, * q, * t;
	int i, n, a;
	printf("����������ĳ���: ");
	scanf("%d", &n);
	head = NULL;//ͷָ���ʼΪ��
	for (i = 1; i <= n; i++)//ѭ������n����
	{
		scanf("%d", &a);
		//��̬����һ���ռ�, �������һ�����, ������ʱָ��pָ�������
		p = (struct node*)malloc(sizeof(struct node));
		if (p != NULL)
		{
			p->data = a;//�����ݴ洢����ǰ����data����
			p->next = NULL;//���õ�ǰ���ĺ��ָ��ָ���, Ҳ���ǵ�ǰ������һ�����Ϊ��
		}
		if (head == NULL)
		{
			head = p;//�������ǵ�һ�������Ľ��, ��ͷָ��ָ��������
		}
		else
		{
			if (q != NULL)
			{
				q->next = p; //������ǵ�һ�������Ľ��, ����һ�����ĺ��ָ��ָ��ǰ���
			}
		}
		q = p; //�����һ��ѭ������Ҫ�������ֵ
	}
	//��������е�������
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