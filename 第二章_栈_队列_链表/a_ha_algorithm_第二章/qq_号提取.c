#include <stdio.h>

int qq_extract()
{
	int q[102] = { 6, 3, 1, 7, 5, 8, 9, 2, 4 }, head, tail;
	int i;
	//��ʼ������
	head = 0;
	tail = 10;//�������Ѿ���9��Ԫ����, tailָ���β�ĺ�һ��λ��
	while (head < tail)
	{
		//��ӡ���ײ������׳���
		printf("%d ", q[head]);
		head++;
		//�Ƚ��¶��׵�����ӵ���β
		q[tail] = q[head];
		tail++;
		//�ٽ����׳���
		head++;
	}
	return 0;
}