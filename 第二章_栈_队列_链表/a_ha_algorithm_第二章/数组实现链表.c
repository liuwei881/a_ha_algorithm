#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int list_linked()
{
	int data[101], right[101];
	int i, n, t, len;
	printf("输入数组的大小: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &data[i]);
	}
	len = n;
	//初始化数组right
	for (i = 1; i <= n; i++)
	{
		if (i != n)
		{
			right[i] = i + 1;
		}
		else
		{
			right[i] = 0;
		}
	}
	//直接在数组data的末尾增加一个数
	len++;
	scanf("%d", &data[len]);
	//从链表的头部开始遍历
	t = 1;
	while (t != 0)
	{
		if (data[right[t]] > data[len])//如果当前结点下一个结点的值大于待插入的数, 将数插入中间
		{
			right[len] = right[t];//新插入数的下一个结点标号等于当前结点的下一个结点编号
			right[t] = len;//当前结点的下一个结点编号就是新插入数的编号
			break;//插入完成跳出循环
		}
		t = right[t];
	}
	//输出链表中所有的数
	t = 1;
	while (t != 0)
	{
		printf("%d ", data[t]);
		t = right[t];
	}
	return 0;
}