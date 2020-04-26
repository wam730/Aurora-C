#include<stdio.h>
#include<cstdlib>
#include<string.h>
#define N sizeof a/sizeof a[0]
int main()
{
	int j,
		*p;
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	printf("N = %d\n", N);
	for (j = 0; j < N; j++)
	{
		printf("a[%d] = %d\n", j, a[j]);
	}
	for(p=a;p<a+N;p++)
	{ 
		printf("*p\t=%d\n", *p);
	}
	for (p = a, j = 0; p + j < a + N; j++)
	{
		printf("*(p+%d)\t= %d\n",j,*(p+j));
	}
	for (p = a + N - 1, j = N - 1; j >= 0; j--)
	{
		printf("p[-%d]\t= %d\n",j,p[-j]);
	}
	system("pause");
	return 0;
}