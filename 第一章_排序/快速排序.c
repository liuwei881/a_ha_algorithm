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
	temp = a[left]; //temp中存的就是基准数
	i = left;
	j = right;
	while (i != j)
	{
		//顺序很重要, 要先从右往左找
		while (a[j] >= temp && i < j)
		{
			j--;
		}
		while(a[i] <= temp && i < j)
		{
			i++;
		}
		if (i < j)//当哨兵i和哨兵j没有相遇时
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//将基准数归位
	a[left] = a[i];
	a[i] = temp;
	quicksort(left, i - 1);//处理左边的
	quicksort(i + 1, right);//处理右边的
}