#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

void quicksort(int left, int right)
{
	int i, j, t, temp;
	if (left > right)
		return;
	temp = a[left]; //temp�д�ľ��ǻ�׼��
	i = left;
	j = right;
	while (i != j)
	{
		//˳�����Ҫ, Ҫ�ȴ���������
		while (a[j] >= temp && i < j)
		{
			j--;
		}
		while(a[i] <= temp && i < j)
		{
			i++;
		}
		if (i < j)//���ڱ�i���ڱ�jû������ʱ
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//����׼����λ
	a[left] = a[i];
	a[i] = temp;
	quicksort(left, i - 1);//������ߵ�
	quicksort(i + 1, right);//�����ұߵ�
}