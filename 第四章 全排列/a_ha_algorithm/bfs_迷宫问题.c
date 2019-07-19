#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct note
{
	int x; //横坐标
	int y; //纵坐标
	int f; //父亲在队列中的编号, 本题不要求输出路径, 可以不需要f;
	int s; //步数
};

int bfs()
{
	struct note que[2501];//因为地图大小不超过50*50, 因此队列不会超过2500个

	int a[51][51] = { 0 };
	int book[51][51] = { 0 };
	//定义一个用于表示走的方向的数组
	int next[4][2] = { {0, 1},{1, 0},{0, -1},{-1, 0} }; // 向右，下，左，上走
	int head, tail;
	int i, j, k, n, m, startx, starty, p, q, tx, ty, flag;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d %d %d %d", &startx, &starty, &p, &q);
	//队列初始化
	head = 1;
	tail = 1;
	//往队列插入迷宫入口坐标
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;
	flag = 0; //用来标记是否到达目标点, 0表示暂时还没有到达, 1表示到达
	//当队列不为空的时候循环
	while (head < tail)
	{
		//枚举4个方向
		for (k = 0; k <= 3; k++)
		{
			//计算下一个点的坐标
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			//判断是否越界
			if (tx < 1 || tx > n || ty < 1 || ty > m)
			{
				continue;
			}
			//判断是否是障碍物或者已经在路径中
			if (a[tx][ty] == 0 && book[tx][ty] == 0)
			{
				//把这个点标记为已经走过
				//注意广度优先搜索每个点只入队一次, 所以和深搜不同, 不需要将book数组还原
				book[tx][ty] = 1;
				//插入新的点到队列中
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;
				//因为这个点是从head扩展出来的, 所以它的父亲是head, 本题不需要求路径,因此省略f;
				que[tail].s = que[head].s + 1; //步数是父亲的步数+1
				tail++;
			}
			//如果到目标点了, 停止扩展, 任务结束, 退出循环
			if (tx == p && ty == q)
			{
				//注意下面两句话的位置千万不要写颠倒
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			break;
		}
		head++;//当一个扩展结束后, head++才能对后面的点在扩展
	}
	//打印队列中末尾最后一个点(目标点)的步数
	//注意tail是指向队列队尾(即最后一位)的下一个位置, 所以这需要-1
	printf("%d", que[tail - 1].s);
	return 0;
}