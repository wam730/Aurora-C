#include<stdio.h>
#include<stdlib.h>

typedef struct snode
{
	char data;
	struct snode* next;
}LinkStrNode;

void InitStr(LinkStrNode*& s)
{
	s = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	s->next = NULL;
}

bool InsertStr(LinkStrNode*&s,char e,int i)
{
	;
	int j = 0;
	LinkStrNode* p = s, * l;
	if (i <= 0) return false;
	while (j < i-1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else 
	{
		l = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		l->data = e;
		l->next = p->next;
		p->next = l;
		return true;
	}
}

void DestroyStr(LinkStrNode*& s)
{
	LinkStrNode* pre = s, * p = s->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

void CopyStr(LinkStrNode* t, LinkStrNode*& s)//t�Ǳ����ƵĴ���s�Ǹ��ƽ���Ĵ�
{
	LinkStrNode* p = t->next, * q, * r;
	s = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	r = s;
	while (p != NULL)//ɨ��t�����н��
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	/*�����µĽ��q����p��ֵ��q���ٰ�q����r֮������r�ƶ���ָ��q������p�ƶ���Ϊp->next*/
	r->next = NULL;
}

bool EqualStr(LinkStrNode* s, LinkStrNode* t)
{
	LinkStrNode* p = s->next, * q = t->next;
	while (p != NULL && q != NULL && p->next == q->next)
	{
		p = p->next;
		q = q->next;
	}
	if (p == NULL && q == NULL)
		return true;
	else
		return false;
}

int LengthStr(LinkStrNode* s)
{
	int i = 0;
	LinkStrNode* p = s->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

LinkStrNode* Concat(LinkStrNode* s, LinkStrNode* t)
{
	LinkStrNode* str, * p = s->next, * q, * r;
	str = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	r = str;
	while (p != NULL)			//��s�����нڵ㸴�Ƶ�str
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q; r = q;
		p = p->next;
	}
	p = t->next;
	while (p != NULL)			//��t�����нڵ㸴�Ƶ�str
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q; r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

LinkStrNode* SubStr(LinkStrNode* s, int i, int j)
{
	int k;
	LinkStrNode* str, * p = s->next, * q, * r;
	str = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	str->next = NULL;
	r = str;						
	if (i <= 0 || i > LengthStr(s) || j<0 || i + j - 1>LengthStr(s))
		return str;				
	for (k = 0; k < i - 1; k++)
		p = p->next;
	for (k = 1; k <= j; k++) 		
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q; r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

LinkStrNode* InsStr(LinkStrNode* s, int i, LinkStrNode* t)
{
	int k;
	LinkStrNode* str, * p = s->next, * p1 = t->next, * q, * r;
	str = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	str->next = NULL;
	r = str;								
	if (i <= 0 || i > LengthStr(s) + 1)		
		return str;
	for (k = 1; k < i; k++)					
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q; r = q;
		p = p->next;
	}
	while (p1 != NULL)
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p1->data;
		r->next = q; r = q;
		p1 = p1->next;
	}
	while (p != NULL)					
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q; r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

LinkStrNode* DelStr(LinkStrNode*& s, int i, int j)
{
	int k;
	LinkStrNode* str, * p = s->next, * q, * r;
	str = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	str->next = NULL;
	r = str;						
	if (i <= 0 || i > LengthStr(s) || j<0 || i + j - 1>LengthStr(s))
		return str;				
	for (k = 0; k < i - 1; k++)			
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q; r = q;
		p = p->next;
	}
	for (k = 0; k < j; k++)
		p = p->next;
	while (p != NULL)				
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q; r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

LinkStrNode* RepStr(LinkStrNode* s, int i, int j, LinkStrNode* t)
{
	int k;
	LinkStrNode* str, * p = s->next, * p1 = t->next, * q, * r;
	str = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	str->next = NULL;
	r = str;							
	if (i <= 0 || i > LengthStr(s) || j<0 || i + j - 1>LengthStr(s))
		return str;		 		
	for (k = 0; k < i - 1; k++)  			
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data; q->next = NULL;
		r->next = q; r = q;
		p = p->next;
	}
	for (k = 0; k < j; k++)			
		p = p->next;
	while (p1 != NULL)			
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p1->data; q->next = NULL;
		r->next = q; r = q;
		p1 = p1->next;
	}
	while (p != NULL)					
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data; q->next = NULL;
		r->next = q; r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

void DispStr(LinkStrNode* s)
{
	LinkStrNode* p = s->next;
	while (p != NULL)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	LinkStrNode* s, * t, * p;
	InitStr(s);
	InitStr(p);
	InitStr(t);
	InsertStr(s, 'h', 1);
	InsertStr(s, 'e', 2);
	InsertStr(s, 'l', 3);
	InsertStr(s, 'l', 4);
	InsertStr(s, 'o', 5);
	InsertStr(s, ',', 6);
	InsertStr(s, 'w', 7);
	InsertStr(s, 'o', 8);
	InsertStr(s, 'r', 9);
	InsertStr(s, 'l', 10);
	InsertStr(s, 'd', 11);
	printf("��ӡ��s��");
	DispStr(s);
	CopyStr(s, t);
	printf("��s���Ƶ�t������ӡt��");
	DispStr(t);
	printf("��s����Ϊ��%d", LengthStr(s));
	printf("\n��sǰ5���ַ�Ϊ��");
	DispStr(SubStr(s,1,5));
	printf("���Ӵ�s��t��");
	DispStr(Concat(s, t));
	printf("�ڴ�s��6��λ�ò��봮t��");
	DispStr(InsStr(s, 6, t));
	printf("ɾ����s�ĵ�6,7,8λ��");
	DispStr(DelStr(s,6,3));
	printf("����s��1-3�滻Ϊt��");
	DispStr(RepStr(s, 1, 3, t)); 	
	printf("����s��t");
	DestroyStr(s);
	DestroyStr(t);
	return 0;
}