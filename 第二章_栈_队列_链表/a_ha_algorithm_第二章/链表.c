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
	printf("请输入链表的长度: ");
	scanf("%d", &n);
	head = NULL;//头指针初始为空
	for (i = 1; i <= n; i++)//循环读入n个数
	{
		scanf("%d", &a);
		//动态申请一个空间, 用来存放一个结点, 并用临时指针p指向这个点
		p = (struct node*)malloc(sizeof(struct node));
		if (p != NULL)
		{
			p->data = a;//将数据存储到当前结点的data域中
			p->next = NULL;//设置当前结点的后继指针指向空, 也就是当前结点的下一个结点为空
		}
		if (head == NULL)
		{
			head = p;//如果这个是第一个创建的结点, 则将头指针指向这个结点
		}
		else
		{
			if (q != NULL)
			{
				q->next = p; //如果不是第一个创建的结点, 则将上一个结点的后继指针指向当前结点
			}
		}
		q = p; //这个是一个循环所以要有这个赋值
	}
	//输出链表中的所有数
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