//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include "head.h"

#if 0
struct note
{
	int x;
	int y;
};

struct note que[401];

int main()
{
	scanf("%d", &n);
	dfs(1);
	dfs_match(1);
	printf("total = %d", total / 2);
	int i, j, startx, starty;
	//读入n和m, n为行,m为列
	scanf("%d %d", &n, &m);
	//读入迷宫
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	//读入起点和终点坐标
	scanf("%d %d %d %d", &startx, &starty, &p, &q);
	//从起点开始搜索
	book[startx][startx] = 1;//标记起点已经在路径中, 防止后面重复走
	//第一个参数是起点的x坐标, 第二个参数是起点的y坐标, 第三个参数是初始步数为0
	dfs_maze(startx, starty, 0);
	//输出最短步数
	printf("%d", min);
	bfs();

	int head, tail;
	int book[20][20] = { 0 };//定义一个标记数组并全部初始化为0
	int i, j, k, sum, max = 0;
	int mx, my, n, m, startx, starty, tx, ty;
	//定义一个用于表示走的方向的数组
	int next[4][2] = { {0, 1},{1, 0},{0, -1},{-1, 0} };//向右，下, 左，上走
	//读入n和m, n表示有多少行字符, m表示每行有多少列
	scanf("%d %d %d %d", &n, &m, &startx, &starty);
	//读入n行字符
	for (i = 0; i <= n - 1; i++)
	{
		scanf("%s", a[i]);
	}
	//队列初始化
	head = 1;
	tail = 1;
	//往队列插入小人的起始坐标
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	max = getnum(startx, starty);
	mx = startx;
	my = starty;
	//当队列不为空的时候循环
	while (head < tail)
	{
		//枚举4个方向
		for (k = 0; k <= 3; k++)
		{
			//尝试走的下一个点的坐标
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			//判断是否越界
			if (tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1)
			{
				continue;
			}
			//判断是否为平地或者曾经走过
			if (a[tx][ty] == '.' && book[tx][ty] == 0)
			{
				//每个点只入队一次, 所以需要标记这个点已经走过
				book[tx][ty] = 1;
				//插入新扩展的点到队列中
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
				//统计当前新扩展的点可以消灭的敌人总数
				sum = getnum(tx, ty);
				//更新max的值
				if (sum > max)
				{
					max = sum;
					mx = tx;
					my = ty;
				}
			}
		}
	}
	head++;//对后面的点进行扩展
	//最后输出这个点和最多可以消灭的敌人数
	int i, startx, starty;
	//读入n和m, n表示行, m表示列
	scanf("%d %d %d %d", &n, &m, &startx, &starty);
	//读入n行字符
	for (i = 0; i <= n - 1; i++)
	{
		scanf("%s", a[i]);
	}
	//从小人所站的位置开始尝试
	book[startx][starty] = 1;
	max = getnum(startx, starty);
	mx = startx;
	my = starty;
	dfs(startx, starty);
	printf("将炸弹放置在(%d, %d), 最多可以消灭%d个敌人\n", mx, my, max);
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
#endif