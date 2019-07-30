#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define inf 99999999;

#if 0
struct edge
{
	int u;
	int v;
	int w;
}; //Ϊ�˷�������, ���ﴴ����һ���ṹ�������洢�ߵĹ�ϵ

struct edge e[10];
int n, m;
int f[7] = { 0 }, sum = 0, count = 0;//���鼯��Ҫ�õ���һЩ����
//f�����С����ʵ���������, Ҫ��n�����ֵ��1

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
		//˳�����Ҫ, Ҫ�ȴ��ұ߿�ʼ��
		while (e[j].w >= e[left].w && i < j)
		{
			j--;
		}
		//�ٴ���߿�ʼ��
		while (e[i].w <= e[left].w && i < j)
		{
			i++;
		}
		//����
		if (i < j)
		{
			t = e[i];
			e[i] = e[j];
			e[j] = t;
		}
	}
	//���ս���׼����λ, ��left��i����
	t = e[left];
	e[left] = e[i];
	e[i] = t;
	quicksort(left, i - 1);//�ݹ���ߴ���
	quicksort(i + 1, right);//�ݹ��ұߴ���
	return;
}

//���鼯Ѱ�����ȵĺ���
int getf(int v)
{
	if (f[v] == v)
	{
		return v;
	}
	else
	{
		//������·��ѹ��
		f[v] = getf(f[v]);
		return f[v];
	}
}
//���鼯�ϲ����Ӽ��ϵĺ���
int merge(int v, int u)
{
	int t1, t2;
	t1 = getf(v);
	t2 = getf(u);
	if (t1 != t2)//�ж��������Ƿ���ͬһ��������
	{
		f[t2] = t1;
		return 1;
	}
	return 0;
}

int main()
{
	int i;
	//����n��m, n��ʾ�������, m��ʾ�ߵ�����
	scanf("%d %d", &n, &m);
	//�����, ������һ���ṹ�����洢�ߵĹ�ϵ
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	}
	quicksort(1, m); //����Ȩֵ��С����Ա߽��п�������
	//���鼯��ʼ��
	for (i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	//Kruskal�㷨���Ĳ���
	for (i = 1; i <= m; i++)//��ʼ��С����ö��ÿһ����
	{
		//�ж�һ���ߵ����������Ƿ��Ѿ���ͨ, ���ж��Ƿ�����ͬһ��������
		if(merge(e[i].u, e[i].v))//���Ŀǰ��δ��ͨ, ��ѡ��������
		{
			count++;
			sum = sum + e[i].w;
		}
		if (count == n - 1)//ֱ��ѡ����n-1���ߺ��˳�ѭ��
		{
			break;
		}
	}
	printf("%d", sum);
	return 0;
}
#endif
#if 0
//��С������
int main()
{
	int n, m, i, j, k, min, t1, t2, t3;
	int e[7][7], dis[7], book[7] = { 0 };//�����book��������˳�ʼ��
	int count = 0, sum = 0; //count������¼�������ֶ���ĸ���, sum�����洢·��֮��

	//����n��m, n��ʾ�������, m��ʾ�ߵ�����
	scanf("%d %d", &n, &m);
	//��ʼ��
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
	//��ʼ�����
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		//ע������������ͼ, ������Ҫ���߷����ڴ洢һ��
		e[t1][t2] = t3;
		e[t2][t1] = t3;
	}
	//��ʼ��dis����, ������1�Ŷ��㵽��������ĳ�ʼ����,��Ϊ��ǰ��������ֻ��1�Ŷ���
	for (i = 1; i <= n; i++)
	{
		dis[i] = e[1][i];
	}
	//Prim���Ĳ���
	//��1�Ŷ������������
	book[1] = 1;//������book�����һ�������Ƿ��Ѿ�����������
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
	//ɨ�赱ǰ����j���еı�, ����jΪ�м��,������������ÿһ����������ľ���
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
//��С��ʵ��Prim
int dis[7], book[7] = { 0 }; //book����������¼��Щ�����Ѿ�������������
int h[7], pos[7], size;//h���������, pos�����洢ÿ�������ڶ��е�λ��,sizeΪ�ѵĴ�С

//��������, �����������е�����Ԫ�ص�ֵ
void swap(int x, int y)
{
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	//ͬ������pos
	t = pos[h[x]];
	pos[h[x]] = pos[h[y]];
	pos[h[y]] = t;
}
//���µ�������
void siftdown(int i)//����һ����Ҫ���µ����Ľ����
{
	int t, flag = 0;//flag��������Ƿ���Ҫ�������µ���
	while (flag = 0 && 2 * i <= size)
	{
		//�Ƚ�i���������i*2��dis�е�ֵ, ����t��¼ֵ��С�Ľ����
		if (dis[h[i]] > dis[h[i * 2]])
		{
			t = i * 2;
		}
		else
		{
			t = i;
		}
		//��������Ҷ���, �ٶ��Ҷ��ӽ�������
		if (i * 2 + 1 <= size)
		{
			//����Ҷ��ӵ�ֵ��С, ���½�С�Ľ����
			if (dis[h[t]] > dis[h[i * 2 + 1]])
			{
				t = i * 2 + 1;
			}
		}
		//���������С�Ľ���Ų����Լ�, ˵���ӽ�����бȸ��ڵ��С��
		if (t != i)
		{
			swap(t, i);//��������
			i = t;//����iΪ�ղ����������Ķ��ӽڵ�ı��, ���ڽ������������µ���
		}
		else
		{
			flag = 1; //����˵����ǰ�ĸ�����Ѿ��������ӵ㶼ҪС��, ����Ҫ�ڽ��е���
		}
	}
}

void siftup(int i)//����һ����Ҫ���ϵ����Ľ����i
{
	int flag = 0;//��������Ƿ���Ҫ�������ϵ���
	if (i == 1)
	{
		return;//����ǶѶ�, �ͷ���, ����Ҫ������
	}
	//���ڶѶ�, ���ҵ�ǰ���i��ֵ�ȸ����С��ʱ��������ϵ���
	while (flag = 0 && i != 1)
	{
		//�ж��Ƿ�ȸ����С
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

//�ӶѶ�ȡ��һ��Ԫ��
int pop()
{
	int t;
	t = h[1];//��һ����ʱ������¼�Ѷ����ֵ
	pos[t] = 0;//��ʵ���Ҫ��Ҫ����ν
	h[1] = h[size];//���ѵ����һ���㸳ֵ���Ѷ�
	pos[h[1]] = 1;
	size--;//�ѵ�Ԫ�ؼ���1
	siftdown(1);//���µ���
	return t;//����֮ǰ��¼�ĶѶ���
}

int main()
{
	int n, m, i, j, k;
	int u[19], v[19], w[19], first[7], next[19];
	int count = 0;
	int sum = 0;//count ������¼�������ж���ĸ���, sum�����洢·��֮��
	//����n��m, n��ʾ�������, m��ʾ�ߵ�����
	scanf("%d %d", &n, &m);
	//��ʼ�����
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	}
	//����������ͼ, ������Ҫ�����еı��ٷ���洢һ��
	for (i = m + 1; i <= 2 * m; i++)
	{
		u[i] = v[i - m];
		v[i] = u[i - m];
		w[i] = w[i - m];
	}
	//��ʼʹ���ڽӱ�洢��
	for (i = 1; i <= n; i++)
	{
		first[i] = -1;
	}
	for (i = 1; i <= 2 * m; i++)
	{
		next[i] = first[u[i]];
		first[u[i]] = i;
	}

	//Prim���Ĳ��ֿ�ʼ
	//��1�Ŷ������������
	book[1] = 1;//������book�����һ�������Ѿ�����������
	count++;
	//��ʼ��dis����, ������1�Ŷ��㵽�����������ĳ�ʼ����
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
	//��ʼ����
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
	pop();//�ȵ���һ���Ѷ�Ԫ��, ��Ϊ��ʱ�Ѷ���1�Ŷ���

	while (count < n)
	{
		j = pop();
		book[j] = 1;
		count++;
		sum = sum + dis[j];
	}
	//ɨ�赱ǰ����j���еı�, ����jΪ�м���, �����ɳ�
	k = first[j];
	while (k != -1)
	{
		if (book[v[k]] == 0 && dis[v[k]] > w[k])
		{
			dis[v[k]] = w[k]; //���¾���
			siftup(pos[v[k]]); //�Ըýڵ��ڶ��н������ϵ���
			//pos[v[k]] �洢���Ƕ���v[k]�ڶ��е�λ��
		}
	}
	k = next[k];
	printf("%d", sum);
	return 0;
}
#endif

#if 0
//����
int n, m, e[9][9], root;
int num[9], low[9], flag[9], index;//index��������ʱ����ĵ���
//���������н�Сһ�����ĺ���
int min(int a, int b)
{
	return a < b ? a : b;
}
//����㷨�ĺ���
void dfs(int cur, int father)//��Ҫ�������������, ��ǰ�����ź͸�����ı��
{
	int child = 0, i, j; //child������¼���������е�ǰ����cur�Ķ��Ӹ���
	index++;//ʱ�����1
	num[cur] = index;//��ǰ����cur��ʱ���
	low[cur] = index;//��ǰ����cur�ܹ����ʵ����綥���ʱ���, �տ�ʼ��Ȼ���Լ�
	for (i = 1; i <= n; i++)
	{
		//ö���뵱ǰ����cur�б������Ķ���i
		if (e[cur][i] == 1)
		{
			if (num[i] == 0)
			{
				//�������i��ʱ�����Ϊ0, ˵������i��û�б����ʹ�
				child++;
				dfs(i, cur);//��������������ȱ���
				//���µ�ǰ����cur�ܷ���ʵ����綥���ʱ���
				low[cur] = min(low[cur], low[i]);
				//�����ǰ���㲻�Ǹ���㲢������low[i] >= num[cur], ��ǰ����Ϊ���
				if (cur != root && low[i] >= num[cur])
				{
					flag[cur] = 1;
				}
				//�����ǰ�����Ǹ����, ���������и�������Ҫ����������, ��ô����������Ǹ��
				if (cur == root && child == 2)
				{
					flag[cur] = 1;
				}
			}
			else if (i != father)
			{
				//�����������i���������ʹ�, 
				//����������㲻�ǵ�ǰ����cur�ĸ���, 
				//����Ҫ���µ�ǰ���cur�ܷ���ʵ����綥���ʱ���
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
	dfs(1, root);//��1�Ŷ��㿪ʼ����������ȱ���
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
//����
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

//����· �������
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
			book[i] = 1;//��ǵ�i�ѷ��ʹ�
			//�����iδ����Ի����ҵ����µ����
			if (match[i] == 0 || dfs(match[i]))
			{
				//������Թ�ϵ
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
	scanf("%d %d", &n, &m); //n����m����

	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &t1, &t2);
		e[t1][t2] = 1;
		e[t2][t1] = 1;//����ͼ
	}
	for (i = 1; i <= n; i++)
	{
		match[i] = 0;
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			book[j] = 0;//����ϴ�����ʱ�ı��
			if (dfs(i))
			{
				sum++;//Ѱ������·, ����ҵ�, �������1
			}
		}
	}
	printf("%d", sum);
	return 0;
}
