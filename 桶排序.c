#include <stdio.h>

int bucket()
{
	int book[1001], i, j, t, n;
	for (i = 0; i <= 1000; i++)
	{
		book[i] = 0;
	}
	printf("请输入要排序的总数: ");
	scanf_s("%d", &n); //输入一个数n, 表示接下来有n个数
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &t);
		book[t]++; //进行计数, 对编号为t的桶放一个小旗子
	}
	for (i = 1000; i >= 0; i--)
	{
		for (j = 1; j <= book[i]; j++)
		{
			printf("%d ", i);
		}
	}
	//getchar(); getchar();
	return 0;
}