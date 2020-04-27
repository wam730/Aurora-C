#include<stdio.h>
#include<cstdlib>
int main()
{
	void sort(int array[], int n);
	int n,
		i,
		a[100];
	printf("Input n:");
	scanf_s("%d", &n);
	printf("Input array a:\n");
	for (i = 0; i < n; i++)
	{
		//scanf_s("%d", &a[i]);
		a[i] = i;
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	sort(a, n);
	printf("\n\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
void sort(int array[],int n)
{
	int* p1, * p2, temp,i;
	for (i=0;i<n/2;i++)
	{
		p1 = array + i;
		p2 = array + n - 1 - i;
		temp = *p2;
		*p2 = *p1;
		*p1 = temp;
	}
}