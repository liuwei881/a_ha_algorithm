#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#if 0
//满二叉树, 高度为h, 节点为2^h - 1;
//完全二叉树, 除了h层外, 结点达到最大个数, 左边完全, 右边少
//建堆和堆排序的代码

int h[101];//用来存放堆的数组
int n; //用来存储堆中的元素的个数, 也就是堆的大小
//交换函数, 用来交换堆中的两个元素的值
void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
}
//向下调整函数
void siftdown(int i)//传入一个需要向下调整的结点编号i, 这里传入1, 即从堆的顶点开始向下调整
{
	int t, flag = 0;//flag用来标记是否需要继续向下调整
	//当i结点有儿子(其实至少有左儿子)并且有需要继续调整的时候循环就执行
	while (2 * i <= n && flag == 0)
	{
		//首先判断它和左儿子的关系, 并用t记录值较小的结点编号
		if (h[i] > h[2 * i])
		{
			t = 2 * i;
		}
		else
		{
			t = i;
		}
		//如果他有右儿子, 在堆右儿子进行讨论
		if (2 * i + 1 <= n)
		{
			//如果右儿子的值更小, 更新较小的结点编号
			if (h[t] > h[2 * i + 1])
			{
				t = 2 * i + 1;
			}
		}
		//如果发现最小的结点编号不是自己, 说明子结点中有比父节点更小的
		if (t != i)
		{
			swap(t, i);//交换他们
			i = t;//更新i为刚才与它交换的儿子结点编号,便于接下来继续向下调整
		}
		else
		{
			flag = 1;//否则说明当前的父节点已经比两个子结点都要小了,不需要在进行调整了
		}
	}
}

//建立堆的函数
void create()
{
	int i;
	//从最后一个非叶结点到第1个节点依次进行向上调整
	for (i = n / 2; i >= 1; i--)
	{
		siftdown(i);
	}
}

//删除最大的元素
int deletemax()
{
	int t;
	t = h[1];//用一个临时变量记录堆顶点的值
	h[1] = h[n];//将堆的最后一个点赋值到堆顶
	n--;//堆的元素减少1
	siftdown(1);//向下调整
	return t;//返回之前记录的堆的顶点的最大值
}

int main()
{
	int i, num;
	//读入要排序的数字的个数
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		scanf("%d", &h[i]);
	}
	n = num;
	//建堆
	create();
	//删除顶部元素, 连续删除n次, 其实也就是从大到小把数输出来
	for (i = 1; i <= num; i++)
	{
		printf("%d ", deletemax());
	}
	return 0;
}
#endif

#if 0
int h[101];//用来存放堆的数组
int n;//用来存储堆中元素的个数, 也就是堆的大小

void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
}

//向下调整函数
void siftdown(int i)
{
	int t, flag = 0;
	while (2 * i <= n && flag == 0)
	{
		if (h[i] < h[2 * i])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}
		if (i * 2 + 1 <= n)
		{
			if (h[t] < h[i * 2 + 1])
			{
				t = i * 2 + 1;
			}
		}
		if (t != i)
		{
			swap(t, i);
			i = t;
		}
		else
		{
			flag = 1;
		}
	}
}

void create()
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		siftdown(i);
	}
}

//堆排序
void heapsort()
{
	while (n > 1)
	{
		swap(1, n);
		n--;
		siftdown(1);
	}
}

int main()
{
	int i, num;
	//读入n个数
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		scanf("%d", &h[i]);
	}
	n = num;
	//建堆
	create();
	//堆排序
	heapsort();
	//输出
	for (i = 1; i <= num; i++)
	{
		printf("%d ", h[i]);
	}
	return 0;
}
#endif

int f[1000] = { 0 }, n, m, k, sum = 0;
//初始化, 非常重要, 数组里面存的是自己数组下标的编号就好了
void init()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		f[i] = i;
	}
}

//这是找爹的递归函数, 不停地去找爹, 直到找到祖宗为止, 其实就是最高领导人
//"擒贼先擒王"
int getf(int v)
{
	if (f[v] == v)
	{
		return v;
	}
	else
	{
		//这里是路径压缩, 每次在函数返回的时候, 顺带把路上遇到的人的"BOSS"改为最后找到的祖宗编号
		//也就是犯罪团伙的最高领导人编号. 这样可以提高今后找到犯罪团伙的最高领导人(其实就是树的祖先)
		//的速度
		f[v] = getf(f[v]);
		return f[v];
	}
}

//这里是合并两子集合的函数
void merge(int v, int u)
{
	int t1, t2;
	t1 = getf(v);
	t2 = getf(u);
	if (t1 != t2)
	{
		//判断两个结点是否在同一个集合中, 即是否为同一个祖先
		f[t2] = t1;
		//"靠左"原则, 左边变成右边的boss, 把右边的集合, 作为左边集合的子集合
		//经过路径压缩后, 将f[u]的根的值也赋值为v的祖先f[t1]
	}
}

//请从此处开始阅读程序, 从主函数开始阅读程序是一个好程序
int main()
{
	int i, x, y;
	scanf("%d %d", &n, &m);

	//初始化是必须的
	init();
	for (i = 1; i <= m; i++)
	{
		//开始合并犯罪团伙
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	//最后扫描有多少个独立的犯罪团伙
	for (i = 1; i <= n; i++)
	{
		if (f[i] == i)
		{
			sum++;
		}
	}
	printf("%d\n", sum);
	return 0;
}