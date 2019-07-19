#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, p, q, k, min = 999999999;
int a[51][51], book[51][51];

void dfs_maze(int x, int y, int step)
{
	int next[4][2] = { {0, 1},{1, 0},{0, -1},{-1, 0} }; //������,������,������,������
	int tx, ty, t;
	//�ж��Ƿ񵽴�С����λ��
	if (x == p && y == q)
	{
		//������Сֵ
		if (step < min)
		{
			min = step;
		}
		return;//��ע������ķ��غ���Ҫ
	}
	//ö��4���߷�
	for (k = 0; k <= 3; k++)
	{
		//������һ���������
		tx = x + next[k][0];
		ty = y + next[k][1];
		//�ж��Ƿ�Խ��
		if (tx<1 || tx>n || ty<1 || ty>m)
		{
			continue;
		}
		//�жϸõ��Ƿ�Ϊ�ϰ�������Ѿ���·����
		if (a[tx][ty] == 0 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;//���������Ѿ��߹�
			dfs_maze(tx, ty, step + 1);//��ʼ������һ����
			book[tx][ty] = 0;//���Խ���,ȡ���������
		}
	}
	return;
}
