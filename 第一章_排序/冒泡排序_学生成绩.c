#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	char* name;
	int score;
};

int bubbling_student()
{
	struct student a[100], t;
	int i, j, n;
	printf("请输入学生的数量: ");
	scanf("%d", &n);

	for (i = 0; i <= n; i++)
	{
		printf("请输入名字: ");
		a[i].name = (char*)malloc(sizeof(4));
		scanf("%s", a[i].name);
		printf("请输入成绩: ");
		scanf("%d", &a[i].score);
	}

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n - i; j++)
		{
			if (a[j].score < a[j + 1].score)
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	for (i = 0; i <= n; i++)
	{
		printf("%s: %d\n", a[i].name, a[i].score);
	}

	for (i = 0; i <= n; i++)
	{
		if (a[i].name != NULL)
		{
			free(a[i].name);
			a[i].name = NULL;
		}
	}
	return 0;
}