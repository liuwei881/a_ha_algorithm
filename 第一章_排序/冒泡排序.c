#include <stdio.h>

int bubbling()
{
	int a[100], i, j, t, n;
	printf("请输入要排序的个数: ");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	for (i = 1; i <= n - 1; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}