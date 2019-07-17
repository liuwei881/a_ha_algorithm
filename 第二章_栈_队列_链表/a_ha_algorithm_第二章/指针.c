#include <stdio.h>

int pointer()
{
	int a = 10;
	int* p;
	p = &a;
	printf("%d", *p);
	return 0;
}