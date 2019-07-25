#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define inf 99999999

#if 0
int main()
{
	int e[10][10], k, i, j, n, m, t1, t2, t3;
	int inf = 99999999; //��inf(infinity��д)�洢һ��������Ϊ��������ֵ
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
	//�����
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		e[t1][t3] = t3;
	}
	//Floyd-Warshall����
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (e[i][j] > e[i][k] + e[k][j])
				{
					e[i][j] = e[i][k] + e[k][j];
				}
			}
		}
	}
	//������ս��
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%10d", e[i][j]);
		}
		printf("\n");
	}
	return 0;
}
#endif

#if 0
//Dijkstra�㷨
int main()
{
	int e[10][10], dis[10], book[10], i, j, n, m, t1, t2, t3, u, v, min;
	int inf = 99999999; //��inf �洢һ��������Ϊ��������ֵ
	//����n��m, n��ʾ�������, m��ʾ�������
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
	//�����
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		e[t1][t2] = t3;
	}
	//��ʼ��dis����, ������1�Ŷ��㵽�����������ĳ�ʼ·��
	for (i = 1; i <= n; i++)
	{
		dis[i] = e[1][i];
	}
	//book�����ʼ��
	for (i = 1; i <= n; i++)
	{
		book[i] = 0;
	}
	book[1] = 1;
	//Dijkstra�㷨�������
	for (i = 1; i <= n - 1; i++)
	{
		//�ҵ���1�Ŷ�������Ķ���
		min = inf;
		for (j = 1; j <= n; j++)
		{
			if (book[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
	}
	book[u] = 1;
	for (v = 1; v <= n; v++)
	{
		if (e[u][v] < inf)
		{
			if (dis[v] > dis[u] + e[u][v])
			{
				dis[v] = dis[u] + e[u][v];
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		printf("%d ", dis[i]);
	}
	return 0;
}
#endif
#if 0
int main()
{
	int dis[10], i, k, n, m, u[10], v[10], w[10];
	int inf = 99999999;
	//����n��m, n��ʾ�������, m��ʾ�ߵ�����
	scanf("%d %d", &n, &m);
	//�����
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
	}
	//��ʼ��dis����, ������1�Ŷ��㵽�����������ĳ�ʼ·��
	for (i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}
	dis[1] = 0;
	//Bellman-Ford�㷨�������
	for (k = 1; k <= n - 1; k++)
	{
		for (i = 1; i <= m; i++)
		{
			if (dis[v[i]] > dis[u[i]] + w[i])
			{
				dis[v[i]] = dis[u[i]] + w[i];
			}
		}
	}
	//������ս��
	for (i = 1; i <= n; i++)
	{
		printf("%d ", dis[i]);
	}
	return 0;
}
#endif
//���з�ʽbellman-ford�㷨
int main()
{
	int n, m, i, j, k;
	//u, v��w�������СҪ����ʵ�����������, Ҫ��m�����ֵ��1
	int u[8], v[8], w[8];
	//firstҪ��n�����ֵ��1, nextҪ��m�����ֵҪ��1
	int first[6], next[8];
	int dis[6] = { 0 }, book[6] = { 0 };//book����������¼��Щ�����Ѿ��ڶ�����
	int que[101] = { 0 }, head = 1, tail = 1;//����һ������, ����ʼ������
	//����n��m, n��ʾ�������, m��ʾ�ߵ�����
	scanf("%d %d", &n, &m);

	//��ʼ��dis����, ����1�Ŷ��㵽�����������ĳ�ʼ·��
	for (i = 1; i <= n; i++)
	{
		dis[i] = inf;
	}
	dis[1] = 0;
	//��ʼ��book����, ��ʼ��Ϊ0, �տ�ʼ�����ڶ�����
	for (i = 1; i <= n; i++)
	{
		book[i] = 0;
	}
	//��ʼ��first�����±�1~n��ֵΪ-1, ��ʾ1~n������ʱ��û�б�
	for (i = 1; i <= n; i++)
	{
		first[i] = -1;
	}
	for (i = 1; i <= m; i++)
	{
		//����ÿһ����
		scanf("%d %d %d", &u[i], &v[i], &w[i]);
		//���������ǽ����ڽӱ�Ĺؼ�
		//���������ǽ����ڽӱ�Ĺؼ�
		next[i] = first[u[i]];
		first[u[i]] = i;
	}
	//1�Ŷ������
	que[tail] = 1;
	tail++;
	book[1] = 1;//���1�Ŷ����Ѿ����
	while (head < tail)
	{
		//���в�Ϊ�յ�ʱ��ѭ��
		k = first[que[head]];//��ǰ��Ҫ����Ķ��׶���
		while (k != -1)
		{
			//ɨ�赱ǰ�������еı�
			if (dis[v[k]] > dis[u[k]] + w[k])//�ж��Ƿ��ɳڳɹ�
			{
				dis[v[k]] = dis[u[k]] + w[k];//���¶���1������v[k]��·��
				//���book���������ж϶���v[k]�Ƿ��ڶ�����
				//�����ʹ��һ����������ǵĻ�, 
				//�ж�һ�������Ƿ��ڶ�����ÿ�ζ���Ҫ�Ӷ��е�head��tailɨһ��
				if (book[v[k]] == 0)//0��ʾ���ڶ�����, ������v[k]���������
				{
					//������������Ӳ���
					que[tail] = v[k];
					tail++;
					book[v[k]] = 1;//������
				}
			}
			k = next[k];
		}
		//����
		book[que[head]] = 0;
		head++;
	}
	//���1�Ŷ��㵽���������������·��
	for (i = 1; i <= n; i++)
	{
		printf("%d ", dis[i]);
	}
	return 0;
}