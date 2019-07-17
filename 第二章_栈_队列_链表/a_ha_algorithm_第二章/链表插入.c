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
	printf("输入链表的大小: ");
	scanf("%d", &n);
	head = NULL;//头指针初始为空
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
	printf("请输入要插入的数: ");
	t = head;//从链表头部开始遍历
	while (t != NULL)//当没有到达链表尾部的时候循环
	{
		if (t->next->data > a)//如果当前结点下一个结点的值大于待插入的数, 将数插入到中间
		{
			p = (struct node*)malloc(sizeof(struct node));
			p->data = a;
			p->next = t->next;
			t->next = p;
			break;//插入完毕退出
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
