#include <stdio.h>

int bucket()
{
	int book[1001], i, j, t, n;
	for (i = 0; i <= 1000; i++)
	{
		book[i] = 0;
	}
	printf("������Ҫ���������: ");
	scanf_s("%d", &n); //����һ����n, ��ʾ��������n����
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &t);
		book[t]++; //���м���, �Ա��Ϊt��Ͱ��һ��С����
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