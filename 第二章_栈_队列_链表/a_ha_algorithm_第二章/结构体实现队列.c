#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct queue
{
	int data[100]; //���е�����, �����洢����
	int head; //����
	int tail; //��β
};

int struct_queue()
{
	struct queue q;
	int i;
	//��ʼ������
	q.head = 1;
	q.tail = 1;
	for (i = 1; i <= 9; i++)
	{
		//��������в���9����
		scanf("%d", &q.data[q.tail]);
		q.tail++;
	}

	while (q.head < q.tail)
	{
		//�����в�Ϊ�յ�ʱ��ִ��ѭ��
		//��ӡ���ײ������׳���
		printf("%d ", q.data[q.head]);
		q.head++;
		//�Ƚ��¶��׵�����ӵ���β
		q.data[q.tail] = q.data[q.head];
		//�ٽ����׳���
		q.head++;
	}
	return 0;
}