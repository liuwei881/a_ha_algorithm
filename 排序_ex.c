#include <stdio.h>

int sort()
{
	int a[11], i, j, t;
	for (i = 0; i <= 10; i++)
	{
		a[i] = 0;
	}
	for (i = 1; i <= 5; i++)
	{
		scanf_s("%d", &t);
		a[t]++;
	}
	for (i = 0; i <= 10; i++)
	{
		for (j = 1; j <= a[i]; j++)
			printf("%d ", i);
	}
	//getchar_s(); getchar_s();
	return 0;
}