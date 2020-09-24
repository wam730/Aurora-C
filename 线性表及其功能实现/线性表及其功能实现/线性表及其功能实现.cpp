#include <stdio.h>
#include <cstdlib>
#define MaxSize 50
typedef int ElemType;

typedef struct
{
	ElemType Data[MaxSize];
	int length;
}SqList;

void CreateList(SqList * &L, ElemType a[], int n)
{
	int i = 0, k = 0;
	L = (SqList*)malloc(sizeof(SqList));
	while (i < n)
	{
		L->Data[k] = a[i];
		k++;
		i++;
	}
	L->length = k;
}

void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}

void DispList(SqList* L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%5d", L->Data[i]);
	}
	printf("\n");
}

void DetroyList(SqList*& L)
{
	free(L);
}

bool IsEmpty(SqList* L)
{
	return(L->length == 0);
}

int ListLength(SqList* L)
{
	return(L->length);
}

bool GetElem(SqList* L, int i, ElemType& e)
{
	if (i<1 || i>L->length)
		return false;
	e = L->Data[i - 1];
	return true;
}

int LocateElem(SqList* L, ElemType e)
{
	int i = 0;
	while (i < L->length && L->Data[i] != e) 
		i++;
	if (i >= L->length) 
		return 0;
	else 
		return i + 1;
}

bool ListInsert(SqList*& L, int i, ElemType e)
{
	int j;
	if (i < 1 || i > L->length + 1 || L->length == MaxSize) 
		return false;
	i--;
	for (j = L->length; j > i; j--) 
		L->Data[j] = L->Data[j - 1];
	L->Data[i] = e;
	L->length++;
	return true;
}

bool ListDelete(SqList*& L, int i, ElemType &e)
{
	int j;
	if (i < 1 || i > L->length) 
		return false;
	i--;
	e = L->Data[i];
	for (j = i; j < L->length - 1; j++) 
		L->Data[j] = L->Data[j + 1];
	L->length--;
	return true;
}

int main()
{
	ElemType a[MaxSize] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	ElemType e1 = 17, e2 = 18, e3;
	SqList* L;
	printf("初始化顺序表\n");
	InitList(L);
	printf("\n判断是否是空表:%d\n",IsEmpty(L));
	printf("\n创建顺序表\n");
	CreateList(L, a, 16);
	printf("打印顺序表\n");
	DispList(L);
	printf("\n判断是否是空表:%d\n", IsEmpty(L));
	printf("\n顺序表长度为:%d\n", ListLength(L));
	printf("\n插入17(e1)到位置1\n");
	ListInsert(L, 1,e1);
	DispList(L);
	printf("\n插入18(e2)到位置2\n");
	ListInsert(L, 2, e2);
	DispList(L);
	printf("\n删除15号位置上的元素\n");
	ListDelete(L, 15, e3);
	DispList(L);
	printf("\n15号位置上的元素是%d\n", e3);
	printf("\n查找元素11,");
	printf("11在的位置是%d\n", LocateElem(L, 11));
	printf("\n查找第10号元素,");
	GetElem(L, 10, e3);
	printf("10号位置上的元素是%d\n", e3);
	printf("\n摧毁顺序表\n");
	printf("判断是否是空表:%d\n", IsEmpty(L));
	system("pause");
	return 0;
}