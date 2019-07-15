#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int bucket_sort()
{
	int a[1001], n, i, t;
	for (i = 1; i <= 1000; i++)
	{
		a[i] = 0;//初始化
	}
	printf("请输入要排序的大小: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) //循环读入n个图书的ISBN号
	{
		scanf("%d", &t);
		a[t] = 1; //标记出现过的ISBN号
	}

	for (i = 1; i <= 1000; i++)
	{
		if (a[i] == 1)
			printf("%d ", i);
	}
	return 0;
}