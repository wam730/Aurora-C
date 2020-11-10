#include<stdio.h>
#include<malloc.h>
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LinkNode;

void InitList(LinkNode*& L)
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}

void DestroyList(LinkNode*& L)
{
	LinkNode* pre = L, * p = L->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

bool ListInsert(LinkNode*& L, int i, ElemType e)
{
	int j = 0;
	LinkNode* p = L;
	LinkNode* s;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL) return false;
	else
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

int ListLength(LinkNode* L)
{
	int i = 0;
	LinkNode* p = L;
	while (p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

bool ListOutput(LinkNode* L)
{
	LinkNode* p = L->next;				//�ӵ�һ����㿪ʼ��ӡ,��Ϊͷ���û������,�������ʾ;
	if (p == NULL) return false;
	while (p != NULL)					//ֻҪp����һ���ս��ʹ�ӡ��dataֵ;
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
	return true;
}

bool ListDelete(LinkNode*& L,int i,ElemType & e)
{
	int j = 0;
	LinkNode* p = L, * q;			
	while (j < i - 1 && p != NULL)	
	{
		j++;
		p = p->next;
	}
	if(p == NULL) return false;
	else						
	{
		q = p->next;			
		if (q == NULL)	return false;
		e = q->data;
		p->next = q->next;		
		free(q);			
		return true;			
	}
}

int GetElem(LinkNode* L, int i,ElemType &e)
{
	int j, length;
	LinkNode* p = L;
	length = ListLength(L);
	if (i < 1 || i > length)
		return -1;
	else
	{
		for (j = 1; j <= i; j++)
		{
			p = p->next;
		}
		e = p->data;
		return e;
	}
}

void InvertList(LinkNode*& L)			//��ʵ��һ���ٵĵ���,һ��ʼ���뷨������Ļ�ϵ��ô�ӡ
{										//�����µ�����M,�����õķ����µ���,�ٸ�ֵL = M
	LinkNode* p = L, *q , *M;
	InitList(M);
	q = M;
	int k = 1;
	for (int i = ListLength(L); i > 0; i--)
	{
		
		for (int j = 1; j <= i; j++)
		{
			p = p->next;
		}
		//printf("%d\t", p->data);
		ListInsert(M, k, p->data);
		k++;
		p = L;
	}
	L = M;
}

int main()
{
	LinkNode* L, * M;
	ElemType e = 5,e1,e2,e3;
	InitList(L);
	InitList(M);
	printf("1.���β���Ԫ��1,2,3,4,5,6,7,8,9,��");
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 3);
	ListInsert(L, 4, 4);
	ListInsert(L, 5, 5);
	ListInsert(L, 6, 6);
	ListInsert(L, 7, 7);
	ListInsert(L, 8, 8);
	ListInsert(L, 9, 9);
	printf("������Ա�:");
	ListOutput(L);
	printf("2.ɾ��5��λ���ϵ�Ԫ��5,��������Ա�:");
	ListDelete(L, 5, e);
	ListOutput(L);
	GetElem(L, 3, e2);
	printf("3.λ��0(�����ڣ�����-1),3,5�ϵ�Ԫ����:%d,%d,%d",GetElem(L,0,e1),e2,GetElem(L,5,e3));
	printf("\n4.���Ա���Ϊ:%d",ListLength(L));
	printf("\n5.���ô�ӡ���Ա�:");
	InvertList(L);
	//printf("\n");
	ListOutput(L);
	getchar();
	return 0;
}