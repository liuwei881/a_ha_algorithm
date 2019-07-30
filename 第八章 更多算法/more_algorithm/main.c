#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define inf 99999999;

#if 0
struct edge
{
	int u;
	int v;
	int w;
}; //为了方便排序, 这里创建了一个结构体用来存储边的关系

struct edge e[10];
int n, m;
int f[7] = { 0 }, sum = 0, count = 0;//并查集需要用到的一些变量
//f数组大小根据实际情况设置, 要比n的最大值大1

void quicksort(int left, int right)
{
	int i, j;
	struct edge t;
	if (left > right)
	{
		return;
	}
	i = left;
	j = right;
	while (i != j)
	{
		//顺序很重要, 要先从右边开始找
		while (e[j].w >= e[left].w && i < j)
		{
			j--;
		}
		//再从左边开始找
		while (e[i].w <= e[left].w && i < j)
		{
			i++;
		}
		//交换
		if (i < j)
		{
			t = e[i];
			e[i] = e[j];
			e[j] = t;
		}
	}
	//最终将基准数归位, 将left和i互换
	t = e[left];
	e[left] = e[i];
	e[i] = t;
	quicksort(left, i - 1);//递归左边处理
	quicksort(i + 1, right);//递归右边处理
	return;
}

//并查集寻找祖先的函数
int getf(int v)
{
	if (f[v] == v)
	{
		return v;
	}
	else
	{
		//这里是路径压缩
		f[v] = getf(f[v]);
		return f[v];
	}
}
//并查集合并两子集合的函数
int merge(int v, int u)
{
	int t1, t2;
	t1 = getf(v);
	t2 = getf(u);
	if (t1 != t2)//判断两个点是否在同一个集合中
	{
		f[t2] = t1;
		return 1;
	}
	return 0;
}

int main()
{
	int i;
	//读入n和m, n表示顶点个数, m表示边的条数
	scanf("%d %d", &n, &m);
	//读入边, 这里用一个结构体来存储边的关系
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	}
	quicksort(1, m); //按照权值从小到大对边进行快速排序
	//并查集初始化
	for (i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	//Kruskal算法核心部分
	for (i = 1; i <= m; i++)//开始从小到大枚举每一条边
	{
		//判断一条边的两个顶点是否已经连通, 即判断是否已在同一个集合中
		if(merge(e[i].u, e[i].v))//如果目前尚未连通, 则选用这条边
		{
			count++;
			sum = sum + e[i].w;
		}
		if (count == n - 1)//直到选用了n-1条边后退出循环
		{
			break;
		}
	}
	printf("%d", sum);
	return 0;
}
#endif
#if 0
//最小生成树
int main()
{
	int n, m, i, j, k, min, t1, t2, t3;
	int e[7][7], dis[7], book[7] = { 0 };//这里对book数组进行了初始化
	int count = 0, sum = 0; //count用来记录生成树种顶点的个数, sum用来存储路径之和

	//读入n和m, n表示顶点个数, m表示边的条数
	scanf("%d %d", &n, &m);
	//初始化
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
				e[i][j] = inf;
			}
		}
	}
	//开始读入边
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		//注意这里是无向图, 所以需要将边反向在存储一遍
		e[t1][t2] = t3;
		e[t2][t1] = t3;
	}
	//初始化dis数组, 这里是1号顶点到各个顶点的初始距离,因为当前生成树中只有1号顶点
	for (i = 1; i <= n; i++)
	{
		dis[i] = e[1][i];
	}
	//Prim核心部分
	//将1号顶点加入生成树
	book[1] = 1;//这里用book来标记一个顶点是否已经加入生成树
	count++;
	while (count < n)
	{
		min = inf;
		for (i = 1; i <= m; i++)
		{
			if (book[i] == 0 && dis[i] < min)
			{
				min = dis[i];
				j = i;
			}
		}
		book[j] = 1;
		count++;
		sum = sum + dis[j];
	}
	//扫描当前顶点j所有的边, 再以j为中间点,更新生成树到每一个非树顶点的距离
	for (k = 1; k <= n; k++)
	{
		if (book[k] == 0 && dis[k] > e[j][k])
		{
			dis[k] = e[j][k];
		}
	}
	printf("%d", sum);
	return 0;
}
#endif
#if 0
//最小堆实现Prim
int dis[7], book[7] = { 0 }; //book数组用来记录哪些顶点已经放入生成树中
int h[7], pos[7], size;//h用来保存堆, pos用来存储每个顶点在堆中的位置,size为堆的大小

//交换函数, 用来交换堆中的两个元素的值
void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	//同步更新pos
	t = pos[h[x]];
	pos[h[x]] = pos[h[y]];
	pos[h[y]] = t;
}
//向下调整函数
void siftdown(int i)//传入一个需要向下调整的结点编号
{
	int t, flag = 0;//flag用来标记是否需要继续向下调整
	while (flag = 0 && 2 * i <= size)
	{
		//比较i和它左儿子i*2在dis中的值, 并用t记录值较小的结点编号
		if (dis[h[i]] > dis[h[i * 2]])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}
		//如果它有右儿子, 再对右儿子进行讨论
		if (i * 2 + 1 <= size)
		{
			//如果右儿子的值更小, 更新较小的结点编号
			if (dis[h[t]] > dis[h[i * 2 + 1]])
			{
				t = i * 2 + 1;
			}
		}
		//如果发现最小的结点编号不是自己, 说明子结点中有比父节点更小的
		if (t != i)
		{
			swap(t, i);//交换他们
			i = t;//更新i为刚才与它交换的儿子节点的编号, 便于接下来继续向下调整
		}
		else
		{
			flag = 1; //否则说明当前的父结点已经比两个接点都要小了, 不需要在进行调整
		}
	}
}

void siftup(int i)//传入一个需要向上调整的结点编号i
{
	int flag = 0;//用来标记是否需要继续向上调整
	if (i == 1)
	{
		return;//如果是堆顶, 就返回, 不需要调整了
	}
	//不在堆顶, 并且当前结点i的值比父结点小的时候继续向上调整
	while (flag = 0 && i != 1)
	{
		//判断是否比父结点小
		if (dis[h[i]] < dis[h[i / 2]])
		{
			swap(i, i / 2);
		}
		else
		{
			flag = 1;
		}
		i = i / 2;
	}
}

//从堆顶取出一个元素
int pop()
{
	int t;
	t = h[1];//用一个临时变量记录堆顶点的值
	pos[t] = 0;//其实这句要不要无所谓
	h[1] = h[size];//将堆的最后一个点赋值到堆顶
	pos[h[1]] = 1;
	size--;//堆的元素减少1
	siftdown(1);//向下调整
	return t;//返回之前记录的堆顶点
}

int main()
{
	int n, m, i, j, k;
	int u[19], v[19], w[19], first[7], next[19];
	int count = 0;
	int sum = 0;//count 用来记录生成树中顶点的个数, sum用来存储路径之和
	//读入n和m, n表示顶点个数, m表示边的条数
	scanf("%d %d", &n, &m);
	//开始读入边
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	}
	//这里是无向图, 所以需要将所有的边再反向存储一次
	for (i = m + 1; i <= 2 * m; i++)
	{
		u[i] = v[i - m];
		v[i] = u[i - m];
		w[i] = w[i - m];
	}
	//开始使用邻接表存储边
	for (i = 1; i <= n; i++)
	{
		first[i] = -1;
	}
	for (i = 1; i <= 2 * m; i++)
	{
		next[i] = first[u[i]];
		first[u[i]] = i;
	}

	//Prim核心部分开始
	//将1号顶点加入生成树
	book[1] = 1;//这里用book来标记一个顶点已经加入生成树
	count++;
	//初始化dis数组, 这里是1号顶点到其余各个顶点的初始距离
	dis[1] = 0;
	for (i = 2; i <= n; i++)
	{
		dis[i] = inf;
	}
	k = first[1];
	while (k != -1)
	{
		dis[v[k]] = w[k];
		k = next[k];
	}
	//初始化堆
	size = n;
	for (i = 1; i <= size; i++)
	{
		h[i] = i;
		pos[i] = i;
	}
	for (i = size / 2; i >= 1; i--)
	{
		siftdown(i);
	}
	pop();//先弹出一个堆顶元素, 因为此时堆顶是1号顶点

	while (count < n)
	{
		j = pop();
		book[j] = 1;
		count++;
		sum = sum + dis[j];
	}
	//扫描当前顶点j所有的边, 在以j为中间结点, 进行松弛
	k = first[j];
	while (k != -1)
	{
		if (book[v[k]] == 0 && dis[v[k]] > w[k])
		{
			dis[v[k]] = w[k]; //更新距离
			siftup(pos[v[k]]); //对该节点在堆中进行向上调整
			//pos[v[k]] 存储的是顶点v[k]在堆中的位置
		}
	}
	k = next[k];
	printf("%d", sum);
	return 0;
}
#endif

#if 0
//求割点
int n, m, e[9][9], root;
int num[9], low[9], flag[9], index;//index用来进行时间戳的递增
//求两个数中较小一个数的函数
int min(int a, int b)
{
	return a < b ? a : b;
}
//割点算法的核心
void dfs(int cur, int father)//需要传入的两个参数, 当前顶点编号和父顶点的编号
{
	int child = 0, i, j; //child用来记录在生成树中当前顶点cur的儿子个数
	index++;//时间戳加1
	num[cur] = index;//当前顶点cur的时间戳
	low[cur] = index;//当前顶点cur能够访问到最早顶点的时间戳, 刚开始当然是自己
	for (i = 1; i <= n; i++)
	{
		//枚举与当前顶点cur有边相连的顶点i
		if (e[cur][i] == 1)
		{
			if (num[i] == 0)
			{
				//如果顶点i的时间戳不为0, 说明顶点i还没有被访问过
				child++;
				dfs(i, cur);//继续往下深度优先遍历
				//更新当前顶点cur能否访问到最早顶点的时间戳
				low[cur] = min(low[cur], low[i]);
				//如果当前顶点不是根结点并且满足low[i] >= num[cur], 则当前顶点为割点
				if (cur != root && low[i] >= num[cur])
				{
					flag[cur] = 1;
				}
				//如果当前顶点是根结点, 在生成树中根结点必须要有两个儿子, 那么这个根结点才是割点
				if (cur == root && child == 2)
				{
					flag[cur] = 1;
				}
			}
			else if (i != father)
			{
				//否则如果顶点i曾经被访问过, 
				//并且这个顶点不是当前顶点cur的父亲, 
				//则需要更新当前结点cur能否访问到最早顶点的时间戳
				low[cur] = min(low[cur], num[i]);
			}
		}
	}
}

int main()
{
	int i, j, x, y;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			e[i][j] = 0;
		}
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &x, &y);
		e[x][y] = 1;
		e[y][x] = 1;
	}
	root = 1;
	dfs(1, root);//从1号顶点开始进行深度优先遍历
	for (i = 1; i <= n; i++)
	{
		if (flag[i] == 1)
		{
			printf("%d ", i);
		}
	}
	return 0;
}
#endif
#if 0
//求割边
int n, m, e[9][9], root;
int num[9], low[9], index;

int min(int a, int b)
{
	return a < b ? a : b;
}

void dfs(int cur, int father)
{
	int i, j;
	index++;
	num[cur] = index;
	low[cur] = index;
	for (i = 1; i <= n; i++)
	{
		if (e[cur][i] == 1)
		{
			if (num[i] == 0)
			{
				dfs(i, cur);
				low[cur] = min(low[i], low[cur]);
				if (low[i] > num[cur])
				{
					printf("%d-%d\n", cur, i);
				}
			}
			else if (i != father)
			{
				low[cur] = min(low[cur], num[i]);
			}
		}
	}
}

int main()
{
	int i, j, x, y;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			e[i][j] = 0;
		}
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &x, &y);
		e[x][y] = 1;
		e[y][x] = 1;
	}
	root = 1;
	dfs(1, root);
	return 0;
}
#endif

//增广路 顶点配对
int e[101][101];
int match[101];
int book[101];
int n, m;

int dfs(int u)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (book[i] == 0 && e[u][i] == 1)
		{
			book[i] = 1;//标记点i已访问过
			//如果点i未被配对或者找到了新的配对
			if (match[i] == 0 || dfs(match[i]))
			{
				//更新配对关系
				match[i] = u;
				match[u] = i;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i, j, t1, t2, sum = 0;
	scanf("%d %d", &n, &m); //n个点m条边

	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &t1, &t2);
		e[t1][t2] = 1;
		e[t2][t1] = 1;//无向图
	}
	for (i = 1; i <= n; i++)
	{
		match[i] = 0;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			book[j] = 0;//清空上次搜索时的标记
			if (dfs(i))
			{
				sum++;//寻找曾广路, 如果找到, 配对数加1
			}
		}
	}
	printf("%d", sum);
	return 0;
}
