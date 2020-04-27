#include<stdio.h>
#include<cstdlib>
int main()
{
	void move(int array[20], int n, int m);
	int number[200], n, m, i;
	printf("How many numbers? ");
	scanf_s("%d", &n);
	printf("Please input %d numbers: ",n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &number[i]);
	}
	printf("How many places you waht to move? ");
	scanf_s("%d", &m);
	move(number, n, m);
	printf("Now thet are :\n");
	for (i = 0; i < n; i++)
	{
		printf("%d", number[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
void move(int array[20], int n, int m)
{
	int *p, array_end;
	array_end = *(array + n - 1);
	for (p = array + n - 1; p > array; p--)
	{
		*p = *(p - 1);
	}
	*array = array_end;
	m--;
	if (m > 0)
		move(array, n, m);
}