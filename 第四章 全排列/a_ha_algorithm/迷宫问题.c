#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, p, q, k, min = 999999999;
int a[51][51], book[51][51];

void dfs_maze(int x, int y, int step)
{
	int next[4][2] = { {0, 1},{1, 0},{0, -1},{-1, 0} }; //向右走,向下走,向左走,向上走
	int tx, ty, t;
	//判断是否到达小哈的位置
	if (x == p && y == q)
	{
		//更新最小值
		if (step < min)
		{
			min = step;
		}
		return;//请注意这里的返回很重要
	}
	//枚举4种走法
	for (k = 0; k <= 3; k++)
	{
		//计算下一个点的坐标
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if (tx<1 || tx>n || ty<1 || ty>m)
		{
			continue;
		}
		//判断该点是否为障碍物或者已经在路径中
		if (a[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;//标记这个点已经走过
			dfs_maze(tx, ty, step + 1);//开始尝试下一个点
			book[tx][ty] = 0;//尝试结束,取消这个点标记
		}
	}
	return;
}
