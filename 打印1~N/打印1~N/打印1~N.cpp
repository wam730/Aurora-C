#include<stdio.h>
#include<cstdlib>
void PrintN1(int N);
void PrintN2(int N);
int main()
{
	int N;
	scanf_s("%d", &N);
	//PrintN1(N);
	printf("\n");
	PrintN2(N);
	system("pause");
}
void PrintN1(int N)
{
	int i;
	for (i = 1; i <= N; i++)
	{
		printf("%d ", i);
	}
}

void PrintN2(int N)
{
	if (N > 0)
	{
		PrintN2(N - 1);
		printf("%d ", N);
	}
}