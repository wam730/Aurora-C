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
	scanf_s("%d", &N);
	
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
对于一组随机给定,有小到大排序的数字,
最好情况下,一次就找到要找的数字或者直接比给定最大最小还要大\小直接找不到, T(N) = O(1);
最坏情况下,T(N) = log2(N),这是因为,在最坏的情况下,我们需要二分到1才能找到我们要找的数(或者找不到但
是在范围内也一样),于是,我们有1 = LEN * (1/2)^x , 解之 x = log2(LEN),而等式左边不一定是1,可能二分
到2\3\4等等,所以,最终x = log2(N),即T(N) = O(log2(N))
空间复杂度不变.因为开辟的空间是一样
*/