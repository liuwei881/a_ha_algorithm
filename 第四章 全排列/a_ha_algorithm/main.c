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
	//����n��m, nΪ��,mΪ��
	scanf("%d %d", &n, &m);
	//�����Թ�
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	//���������յ�����
	scanf("%d %d %d %d", &startx, &starty, &p, &q);
	//����㿪ʼ����
	book[startx][startx] = 1;//�������Ѿ���·����, ��ֹ�����ظ���
	//��һ������������x����, �ڶ�������������y����, �����������ǳ�ʼ����Ϊ0
	dfs_maze(startx, starty, 0);
	//�����̲���
	printf("%d", min);
	bfs();

	int head, tail;
	int book[20][20] = { 0 };//����һ��������鲢ȫ����ʼ��Ϊ0
	int i, j, k, sum, max = 0;
	int mx, my, n, m, startx, starty, tx, ty;
	//����һ�����ڱ�ʾ�ߵķ��������
	int next[4][2] = { {0, 1},{1, 0},{0, -1},{-1, 0} };//���ң���, ������
	//����n��m, n��ʾ�ж������ַ�, m��ʾÿ���ж�����
	scanf("%d %d %d %d", &n, &m, &startx, &starty);
	//����n���ַ�
	for (i = 0; i <= n - 1; i++)
	{
		scanf("%s", a[i]);
	}
	//���г�ʼ��
	head = 1;
	tail = 1;
	//�����в���С�˵���ʼ����
	que[tail].x = startx;
	que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	max = getnum(startx, starty);
	mx = startx;
	my = starty;
	//�����в�Ϊ�յ�ʱ��ѭ��
	while (head < tail)
	{
		//ö��4������
		for (k = 0; k <= 3; k++)
		{
			//�����ߵ���һ���������
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			//�ж��Ƿ�Խ��
			if (tx < 0 || tx > n - 1 || ty < 0 || ty > m - 1)
			{
				continue;
			}
			//�ж��Ƿ�Ϊƽ�ػ��������߹�
			if (a[tx][ty] == '.' && book[tx][ty] == 0)
			{
				//ÿ����ֻ���һ��, ������Ҫ���������Ѿ��߹�
				book[tx][ty] = 1;
				//��������չ�ĵ㵽������
				que[tail].x = tx;
				que[tail].y = ty;
				tail++;
				//ͳ�Ƶ�ǰ����չ�ĵ��������ĵ�������
				sum = getnum(tx, ty);
				//����max��ֵ
				if (sum > max)
				{
					max = sum;
					mx = tx;
					my = ty;
				}
			}
		}
	}
	head++;//�Ժ���ĵ������չ
	//����������������������ĵ�����
	int i, startx, starty;
	//����n��m, n��ʾ��, m��ʾ��
	scanf("%d %d %d %d", &n, &m, &startx, &starty);
	//����n���ַ�
	for (i = 0; i <= n - 1; i++)
	{
		scanf("%s", a[i]);
	}
	//��С����վ��λ�ÿ�ʼ����
	book[startx][starty] = 1;
	max = getnum(startx, starty);
	mx = startx;
	my = starty;
	dfs(startx, starty);
	printf("��ը��������(%d, %d), ����������%d������\n", mx, my, max);
	int i, j, num = 0;
	scanf("%d %d", &n, &m);
	//������Ϸ��ͼ
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	//��ʼ����, ��1,1�㿪ʼ, ��ˮ����Ҳ��1
	dfs_g(1, 1, 1);
	//�ж��Ƿ��ҵ����跽��
	if (flag == 0)
	{
		printf("impossible\n");
	}
	else
	{
		printf("�ҵ����跽��\n");
	}
	return 0;
}
#endif