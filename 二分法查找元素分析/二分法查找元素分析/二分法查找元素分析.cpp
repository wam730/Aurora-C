#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LEN 100
#define TYPE int
int main()
{
	TYPE N, temp, a[LEN];
	int i,j;
	srand((unsigned)time(NULL));
	for (i=0;i<LEN;i++)
	{
		a[i] = rand()%150;
		printf("%d ", a[i]);
	}
	printf("\n\n");
	for (i = 0; i < LEN-1; i++)
	{
		for (j = i + 1; j < LEN - 1; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	scanf("%d", &N);
	
	while(1)
	{
		TYPE Middle;
		Middle = int (LEN / 2);
		if (a[Middle]<N)
		{
			Middle = int((LEN + Middle)/ 2);
		}
		else if (a[Middle]>N)
		{
			Middle = int((LEN - Middle) / 2);
		}
		if (a[Middle == N])
		{
			printf("%d is in a", N);
			break;
		}
	}
	system("pause");
}
/*
����һ���������,��С�������������,
��������,һ�ξ��ҵ�Ҫ�ҵ����ֻ���ֱ�ӱȸ��������С��Ҫ��\Сֱ���Ҳ���, T(N) = O(1);
������,T(N) = log2(N),������Ϊ,����������,������Ҫ���ֵ�1�����ҵ�����Ҫ�ҵ���(�����Ҳ�����
���ڷ�Χ��Ҳһ��),����,������1 = LEN * (1/2)^x , ��֮ x = log2(LEN),����ʽ��߲�һ����1,���ܶ���
��2\3\4�ȵ�,����,����x = log2(N),��T(N) = O(log2(N))
�ռ临�ӶȲ���.��Ϊ���ٵĿռ���һ��
*/