#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char a[20][21];
int book[20][20], max, mx, my, n, m;

int getnum(int i, int j)
{
	int sum, x, y;
	sum = 0;//sum��������(��������ĵ�����),������Ҫ��ʼ��Ϊ0
	//������i, j���Ƶ������±���x,y�У��Ա�֮�������������ĸ�����ͳ�ƿ�������ĵ�����
	//����ͳ�ƿ�������ĵ�����
	x = i; y = j;
	while (a[x][y] != '#')//�жϵĵ��ǲ���ǽ, �������ǽ�ͼ���
	{
		//�����ǰ���ǵ���, �����
		if (a[x][y] == 'G')
		{
			sum++;
		}
		x--;
	}
	//����ͳ�ƿ������������
	x = i; y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		x++;
	}
	//����ͳ�ƿ�������ĵ�����
	x = i; y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		y--;
	}
	//����ͳ�ƿ�������ĵ�����
	x = i; y = j;
	while (a[x][y] != '#')
	{
		if (a[x][y] == 'G')
		{
			sum++;
		}
		y++;
	}
	return sum;
}

void dfs(int x, int y)
{
	//����
	int next[4][2] = { {0, 1},{1, 0},{0, -1},{-1, 0} };
	int k, sum, tx, ty;
	//���㵱ǰ������������ĵ�������
	sum = getnum(x, y);
	//����max��ֵ
	if (sum > max)
	{
		max = sum;
		mx = x;
		my = y;
	}
	//ö��4������
	for (k = 0; k <= 3; k++)
	{
		//��һ����������
		tx = x + next[k][0];
		ty = y + next[k][1];
		//�ж��Ƿ�Խ��
		if (tx < 0 || tx > n - 1 || ty < 0 || ty >m - 1)
		{
			continue;
		}
		//�ж��Ƿ�Χǽ�����Ѿ��߹�
		if (a[tx][ty] == '.' && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;//���������Ѿ��߹�
			dfs(tx, ty);//��ʼ������һ����
		}
	}
}
#endif