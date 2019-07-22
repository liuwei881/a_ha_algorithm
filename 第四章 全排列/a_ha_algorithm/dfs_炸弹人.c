#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char a[20][21];
int book[20][20], max, mx, my, n, m;

int getnum(int i, int j)
{
	int sum, x, y;
	sum = 0;//sum用来计数(可以消灭的敌人数),所以需要初始化为0
	//将坐标i, j复制到两个新变量x,y中，以便之后向上下左右四个方向统计可以消灭的敌人数
	//向上统计可以消灭的敌人数
	x = i; y = j;
	while (a[x][y] != '#')//判断的点是不是墙, 如果不是墙就继续
	{
		//如果当前点是敌人, 则计数
		if (a[x][y] == 'G')
		{
			sum++;
		}
		x--;
	}
	//向下统计可以消灭敌人数
	x = i; y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		x++;
	}
	//向左统计可以消灭的敌人数
	x = i; y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		y--;
	}
	//向右统计可以消灭的敌人数
	x = i; y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		y++;
	}
	return sum;
}

void dfs(int x, int y)
{
	//方向
	int next[4][2] = { {0, 1},{1, 0},{0, -1},{-1, 0} };
	int k, sum, tx, ty;
	//计算当前这个点可以消灭的敌人总数
	sum = getnum(x, y);
	//更新max的值
	if (sum > max)
	{
		max = sum;
		mx = x;
		my = y;
	}
	//枚举4个方向
	for (k = 0; k <= 3; k++)
	{
		//下一个结点的坐标
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if (tx < 0 || tx > n - 1 || ty < 0 || ty >m - 1)
		{
			continue;
		}
		//判断是否围墙或者已经走过
		if (a[tx][ty] == '.' && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;//标记这个点已经走过
			dfs(tx, ty);//开始尝试下一个点
		}
	}
}
#endif