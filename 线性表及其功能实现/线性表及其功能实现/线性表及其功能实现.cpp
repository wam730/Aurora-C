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
	printf("��ʼ��˳���\n");
	InitList(L);
	printf("\n�ж��Ƿ��ǿձ�:%d\n",IsEmpty(L));
	printf("\n����˳���\n");
	CreateList(L, a, 16);
	printf("��ӡ˳���\n");
	DispList(L);
	printf("\n�ж��Ƿ��ǿձ�:%d\n", IsEmpty(L));
	printf("\n˳�����Ϊ:%d\n", ListLength(L));
	printf("\n����17(e1)��λ��1\n");
	ListInsert(L, 1,e1);
	DispList(L);
	printf("\n����18(e2)��λ��2\n");
	ListInsert(L, 2, e2);
	DispList(L);
	printf("\nɾ��15��λ���ϵ�Ԫ��\n");
	ListDelete(L, 15, e3);
	DispList(L);
	printf("\n15��λ���ϵ�Ԫ����%d\n", e3);
	printf("\n����Ԫ��11,");
	printf("11�ڵ�λ����%d\n", LocateElem(L, 11));
	printf("\n���ҵ�10��Ԫ��,");
	GetElem(L, 10, e3);
	printf("10��λ���ϵ�Ԫ����%d\n", e3);
	printf("\n�ݻ�˳���\n");
	printf("�ж��Ƿ��ǿձ�:%d\n", IsEmpty(L));
	system("pause");
	return 0;
}