#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[51][51]; //假设土地的大小不超过50*50
int book[51][51], n, m, flag = 0;
struct note
{
	int x;
	int y;
}s[100];
int top = 0;

void dfs_g(int x, int y, int front)
{
	int i;
	//判断是否到达终点, 请注意这里的y的坐标是m+1(因为n, m,是边界，必须m+1才完成全部搜索)
	//另外判断是否到达终点一定要放在越界判断前面
	if (x == n && y == m + 1)
	{
		flag = 1; //找到铺设方案
		return;
	}
	//判断是否越界
	if (x<1 || x>n || y<1 || y>m)
	{
		return;
	}
	//判断这个管道是否在路径中已经使用过
	if (book[x][y] == 1)
	{
		return;
	}
	book[x][y] = 1; //标记使用当前这个管道
	//当前水管是直管的情况
	if (a[x][y] >= 5 && a[x][y] <= 6)
	{
		if (front == 1)//进水口在左边的情况
		{
			dfs_g(x, y + 1, 1); //只能使用5号这种摆放方式
		}
		if (front == 2)//进水口在上边的情况
		{
			dfs_g(x + 1, y, 2);//只能用6号这种摆放方式
		}
		if (front == 3)//进水口在右边的情况
		{
			dfs_g(x, y - 1, 3);//只能使用5号这种摆放方式
		}
		if (front == 4)//进水口在下边的情况
		{
			dfs_g(x - 1, y, 4); //只能使用6号这种摆放方式
		}
	}
	//当前水管是弯管的情况
	if (a[x][y] >= 1 && a[x][y] <= 4)
	{
		if (front == 1)//进水口在左边的情况
		{
			dfs_g(x + 1, y, 3);//3号状态
			dfs_g(x - 1, y, 4);//4号状态
		}
		if (front == 2)//进水口在上边的情况
		{
			dfs_g(x, y + 1, 1);//1号状态
			dfs_g(x, y - 1, 3);//4号状态
		}
		if (front == 3)//进水口在右边的情况
		{
			dfs_g(x - 1, y, 4);//1号状态
			dfs_g(x + 1, y, 2);//2号状态
		}
		if (front == 4)//进水口在下边的情况
		{
			dfs_g(x, y + 1, 1);//2号状态
			dfs_g(x, y - 1, 3);//3号状态
		}
	}
	book[x][y] = 0;//取消标记
}

int main()
{
	int i, j, num = 0;
	scanf("%d %d", &n, &m);
	//读入游戏地图
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	//开始搜索, 从1,1点开始, 进水方向也是1
	dfs_g(1, 1, 1);
	//判断是否找到铺设方案
	if (flag == 0)
	{
		printf("impossible\n");
	}
	else
	{
		printf("找到铺设方案\n");
	}
	return 0;
}