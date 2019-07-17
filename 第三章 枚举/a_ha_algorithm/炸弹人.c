#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int bomb()
{
	char a[20][20];
	int i, j, sum, map = 0, p, q, x, y, n, m;
	//读入n和m, n表示有多少行字符, m表示每行有多少列
	scanf("%d %d", &n, &m);

	//读入n行字符
	for (i = 0; i <= n - 1; i++)
	{
		scanf("%s", a[i]);
	}
	//用两重循环枚举地图中的每个点
	for (i = 0; i <= n - 1; i++)
	{
		for (j = 0; j <= m - 1; j++)
		{
			//首先判断这个点是不是平地, 是平地才可以被放置炸弹
			if (a[i][j] == '.')
			{
				sum = 0;//sum用来计数(可以消灭敌人数), 初始化为0
				//将当前坐标i, j复制到两个新变量x, y中,以便向上下左右四个方向
				//分别统计可以消灭的敌人数
				//向上统计可以消灭的敌人数
				x = i; y = j;
				while (a[x][y] != '#')//判断是不是墙,如果不会墙就继续
				{
					//如果当前点是敌人, 则进行计数
					if (a[x][y] == 'G')
					{
						sum++;
					}
					x--;
				}
				//向下统计可以消灭的敌人数
				x = i; y = j;
				while (a[x][y] != '#')
				{
					if (a[x][y] == 'G')
					{
						sum++;
					}
					//向下统计
					x++;
				}
				//向左统计可以消灭敌人数
				x = i; y = j;
				while (a[x][y] != '#')
				{
					if (a[x][y] == 'G')
					{
						sum++;
					}
					//向左统计
					y--;
				}
				//向右统计可以消灭敌人数
				x = i; y = j;
				while (a[x][y] != '#')
				{
					if (a[x][y] == 'G')
					{
						sum++;
					}
					//向右统计
					y++;
				}
				if (sum > map)
				{
					//如果当前点所能消灭的敌人总数大于map, 则更新map
					map = sum;
					//并用p和q记录当前点的坐标
					p = i;
					q = j;
				}
			}
		}
	}
	printf("将炸弹放置在(%d, %d), 最多可以消灭%d个敌人\n", p, q, map);
	return 0;
}