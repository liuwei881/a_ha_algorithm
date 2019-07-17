#include <stdio.h>
#include <stdlib.h>

int pointer_malloc()
{
	int* p;
	p = (int*)malloc(sizeof(int));
	if (p != NULL)
	{
		*p = 10;
		printf("%d", *p);
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
	return 0;
}