#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#if 0
int book[101], sum, n, e[101][101];
void dfs(int cur)//cur 是当前所在的顶点编号
{
	int i;
	printf("%d", cur);
	sum++; //每访问一个顶点, sum就加1
	if (sum == n)
	{
		return;//所有的顶点都已经访问过了，退出
	}
	for (i = 1; i <= n; i++)//从1号顶点到n号顶点依次尝试, 看哪些顶点与当前顶点cur有边相连
	{
		//判断当前顶点cur到顶点i是否有边, 并判断顶点i是否已访问过
		if (e[cur][i] == 1 && book[i] == 0)
		{
			book[i] = 1;//标记顶点i已经访问过
			dfs(i);//从顶点i再出发继续遍历
		}
	}
}

int main()
{
	int i, j, m, a, b;
	scanf("%d %d", &n, &m);
	//初始化二维矩阵
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else {
				e[i][j] = 9999999999;//这里假设为正无穷
			}
		}
	}
	//读入顶点之间的边
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1;//这里是无向图, 所以需要将e[b][e]也赋为1
	}
	//从1号城市出发
	book[1] = 1; //标记1号顶点已访问
	dfs(1);//从1号顶点开始遍历
	return 0;
}


int main()
{
	int i, j, n, m, a, b, cur, book[101] = { 0 }, e[101][101];
	int que[10001], head, tail;
	scanf("%d %d", &n, &m);
	//初始化二维矩阵
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else {
				e[i][j] = 9999999; //我们这里假设9999999为正无穷
			}
		}
	}
	//读入顶点之间的边
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		e[a][b] = 1;
		e[b][a] = 1; //这里是无向图, 所以需要将e[b][a]也赋值为1
	}
	//队列初始化
	head = 1;
	tail = 1;
	//从1号顶点出发, 将1号顶点加入队列
	que[tail] = 1;
	tail++;
	book[1] = 1;//标记1号顶点已访问
	//当队列不为空的时候循环
	while (head < tail)
	{
		cur = que[head]; //当前正在访问的顶点编号
		for (i = 1; i <= n; i++)//从1~n依次尝试
		{
			//判断从顶点cur到顶点i是否有边, 并判断顶点i是否已经访问过
			if (e[cur][i] == 1 && book[i] == 0)
			{
				//如果从顶点cur到顶点i有边, 并且顶点i没有被访问过, 将顶点i入队
				que[tail] = i;
				tail++;
				book[i] = 1; //标记顶点i已访问
			}
			//如果tail大于n, 则表明所有顶点都已经被访问过
			if (tail > n)
			{
				break;
			}
		}
		head++;//注意这个地方, 千万不要忘记当一个顶点扩展结束后, head++,然后才能继续往下
	}
	for (i = 1; i < tail; i++)
	{
		printf("%d ", que[i]);
	}
	return 0;
}
#endif
#if 0
int min = 99999999, book[101], n, e[101][101]; //我们这里假设99999999为正无穷
//cur是当前所在的城市编号, dis是当前已经走过的路程

void dfs(int cur, int dis)
{
	int j;
	//如果当前走过的路程已经大于之前找到的最短路, 则没有必要再往下尝试了, 立即返回
	if (dis > min)
	{
		return;
	}
	if (cur == n)//判断是否到达了目标城市
	{
		if (dis < min)
		{
			min = dis;//更新最小值
			return;
		}
	}
	for (j = 1; j <= n; j++)//从1号城市到n号城市依次尝试
	{
		//判断当前城市cur到城市j是否有路, 判断城市j是否在已走过的路径中
		if (e[cur][j] != 99999999 && book[j] == 0)
		{
			book[j] = 1;//标记城市j已经在路径中
			dfs(j, dis + e[cur][j]);//从城市j在出发,继续寻找目标城市
			book[j] = 0;//之前一步探索完毕之后, 取消对城市j的标记
		}
	}
}

int main()
{
	int i, j, m, a, b, c;
	scanf("%d %d", &n, &m);
	//初始化二维矩阵
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = 99999999;
			}
		}
	}
	//读入城市之间的道路
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		e[a][b] = c;
	}
	//从1号城市出发
	book[1] = 1;//标记1号城市已经在路径中
	dfs(1, 0);//1表示当前所在的城市编号,0表示当前已经走过的路程.
	printf("%d", min); //打印1号城市到5号城市的最短路径
	return 0;
}
#endif

//广度优先搜索
struct note
{
	int x;//城市编号
	int s;//转机次数
};

int main()
{
	struct note que[2501];
	int e[51][51] = { 0 };
	int book[51] = { 0 };
	int head, tail;
	int i, j, n, m, a, b, cur, start, end, flag = 0;
	scanf("%d %d %d %d", &n, &m, &start, &end);
	//初始化二维矩阵
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
			{
				e[i][j] = 0;
			}
			else
			{
				e[i][j] = 9999999;
			}
		}
	}
	//读入城市之间的航班
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		//这里是无向图
		e[a][b] = 1;
		e[b][a] = 1;
	}
	//队列初始化
	head = 1;
	tail = 1;
	//从start号城市出发, 将start号城市加入队列
	que[tail].x = start;
	que[tail].s = 0;
	tail++;
	book[1] = start;//标记start号城市已在队列中
	//当队列不为空的时候循环
	while (head < tail)
	{
		cur = que[head].x; //当前队列中首城市的编号
		for (j = 1; j <= n; j++) //从1~n一次尝试
		{
			//从城市cur到城市j是否有航班并且判断城市j是否已经在队列中
			if (e[cur][j] != 99999999 && book[j] == 0)
			{
				//如果从城市cur到城市j有航班并且城市j不在队列中, 则将j号城市入队
				que[tail].x = j;
				que[tail].s = que[head].s + 1; //转机次数+1
				tail++;
				//标记城市j已经在队列中
				book[j] = 1;
			}
			//如果到达目标城市, 停止扩展, 任务结束, 退出循环
			if (que[tail].x == end)
			{
				//注意下面两句话的位置千万不要写颠倒
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}
		head++;//注意这个地方, 千万不要忘记当一个点扩展结束后, head++才能继续扩展
	}
	//打印队列中末尾最后一个(目标城市)的转机次数
	printf("%d", que[tail - 1].s);
	return 0;
}