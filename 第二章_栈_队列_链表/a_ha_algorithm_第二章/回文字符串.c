#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int plalindrome()
{
	char a[101], s[101];
	int i, len, mid, next, top;
	gets(a); //读入一行字符串
	len = strlen(a); //求字符串长度
	mid = len / 2 - 1; //求字符串的中点 abcba, abba
	top = 0; //栈的初始化
	//将mid前的字符依次入栈
	for (i = 0; i <= mid; i++)
	{
		s[++top] = a[i];
	}
	//判断字符串的长度是奇数还是偶数, 并找出需要进行字符匹配的起始下标
	if (len % 2 == 0)
	{
		next = mid + 1;
	}
	else
	{
		next = mid + 2;
	}
	//开始匹配
	for (i = next; i <= len - 1; i++)
	{
		if (a[i] != s[top])
		{
			break;
		}
		top--;
	}
	//如果top值为0,则全部匹配了
	if (top == 0)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
	//{}([)], [(]}, [{}()[]]
}