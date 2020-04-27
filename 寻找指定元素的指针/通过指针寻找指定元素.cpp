#include<stdio.h>
#define MAX 20
int search(int* apt, int n, int key);
int* find(int* apt, int n, int key);
int a[] = { 90,80,70,60,50,40,30,20,10,9,8,7,6,5,42,40,40,1,2,3 };
int main()
{
	int i, key;
	printf("The elements of array a is:\n");
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\nThe address of a[0] is: %d ", &a[0]);
	puts("\nPlease input the key you want to find:");
	scanf_s("%d", &key);
	i = search(a, sizeof(a) / sizeof(a[0]), key);
	printf("\nThe label number of the key number %d in the array is: %d.", key, i);
	printf("\nThe point value of the key number %d in the array is: %d.", key, find(a, sizeof(a) / sizeof(a[0]), key));
}
int search(int* apt, int n, int key) //apt已知数组，n元素个数，key要查找的元素
{
	int* p;
	for (p = apt; p < apt + n; p++)
	{
		if (*p == key)
		{
			return p - apt;
		}
	}
	return -1;
}
int *find(int* apt, int n, int key)
{
	int* p;
	for (p = apt; p < apt + n; p++)
	{
		if (*p == key)
		{
			return p;
		}
	}
	return NULL;
}