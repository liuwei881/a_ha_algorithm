#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int bucket_sort()
{
	int a[1001], n, i, t;
	for (i = 1; i <= 1000; i++)
	{
		a[i] = 0;//��ʼ��
	}
	printf("������Ҫ����Ĵ�С: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) //ѭ������n��ͼ���ISBN��
	{
		scanf("%d", &t);
		a[t] = 1; //��ǳ��ֹ���ISBN��
	}

	for (i = 1; i <= 1000; i++)
	{
		if (a[i] == 1)
			printf("%d ", i);
	}
	return 0;
}