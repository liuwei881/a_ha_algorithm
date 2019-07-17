#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "head.h"

int main()
{
	//bomb();
	int a, b, c, m = 18, sum = 0;
	//开始枚举a和b
	for (a = 0; a <= 1111; a++)
	{
		for (b = 0; b <= 1111; b++)
		{
			c = a + b;//计算出c
			//当a使用的火柴数 + b使用的火柴数 + c使用的火柴数之和等于m-4, 则成功的找到了一组
			//m-4 就是1 + 2 = 3 中去除 + 两根, = 两根共4根的火柴数
			if (fun(a) + fun(b) + fun(c) == m - 4)
			{
				printf("%d+%d=%d\n", a, b, c);
				sum++;
			}
		}
	}
	printf("一共可以拼出%d个不同的等式", sum);
	return 0;
}