#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sort_out()
{
	int a[101], n, i, j, t;
	printf("请输入要排序的大小: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)//
	{
		scanf("%d", &a[i]);
	}
	//开始冒泡排序
	for (i = 1; i <= n - 1; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			if (a[j] > a[j+1])
			{
				t = a[j];
				a[i] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	printf("%d ", a[1]);
	for (i = 2; i <= n; i++)
	{
		if (a[i] != a[i - 1])
			printf("%d ", a[i]);
	}
	return 0;
}