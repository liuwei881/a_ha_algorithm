#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[10], book[10], n;

void dfs(int step)//step表示现在站在第几个盒子面前
{
	int i;
	if (step == n + 1)//如果站在第n+1个盒子面前, 则表示前n个盒子已经放好扑克牌
	{
		//输出一种排列(1~n号盒子中的扑克牌)
		for (i = 1; i <= n; i++)
		{
			printf("%d", a[i]);
		}
		printf("\n");
	}
	//此时站在第step个盒子面前, 应该放哪张牌呢?
	//按照1,2,3...n的顺序一一尝试
	for (i = 1; i <= n; i++)
	{
		//判断扑克牌i是否还在手上
		if (book[i] == 0)//表示扑克牌在手上
		{
			//开始尝试使用扑克牌
			a[step] = i;
			book[i] = i; //牌不在手上
			//第step个盒子已经放好扑克牌, 接下来要走到下一盒子前
			dfs(step + 1);//递归到下一个盒子
			book[i] = 0;//要取回扑克牌才能进行下一步
		}
	}
}