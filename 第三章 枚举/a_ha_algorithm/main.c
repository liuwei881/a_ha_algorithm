#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "head.h"

int main()
{
	//bomb();
	int a, b, c, m = 18, sum = 0;
	//��ʼö��a��b
	for (a = 0; a <= 1111; a++)
	{
		for (b = 0; b <= 1111; b++)
		{
			c = a + b;//�����c
			//��aʹ�õĻ���� + bʹ�õĻ���� + cʹ�õĻ����֮�͵���m-4, ��ɹ����ҵ���һ��
			//m-4 ����1 + 2 = 3 ��ȥ�� + ����, = ������4���Ļ����
			if (fun(a) + fun(b) + fun(c) == m - 4)
			{
				printf("%d+%d=%d\n", a, b, c);
				sum++;
			}
		}
	}
	printf("һ������ƴ��%d����ͬ�ĵ�ʽ", sum);
	return 0;
}