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

void CopyStr(LinkStrNode* t, LinkStrNode*& s)//t是被复制的串，s是复制进入的串
{
	LinkStrNode* p = t->next, * q, * r;
	s = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	r = s;
	while (p != NULL)//扫描t的所有结点
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q;
		r = q;
		p = p->next;
	}
	/*建立新的结点q，将p的值给q，再把q接在r之后，再让r移动，指向q，再让p移动变为p->next*/
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
	while (p != NULL)			//将s的所有节点复制到str
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data;
		r->next = q; r = q;
		p = p->next;
	}
	p = t->next;
	while (p != NULL)			//将t的所有节点复制到str
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
	printf("打印串s：");
	DispStr(s);
	CopyStr(s, t);
	printf("将s复制到t，并打印t：");
	DispStr(t);
	printf("串s长度为：%d", LengthStr(s));
	printf("\n串s前5个字符为：");
	DispStr(SubStr(s,1,5));
	printf("连接串s，t：");
	DispStr(Concat(s, t));
	printf("在串s第6个位置插入串t：");
	DispStr(InsStr(s, 6, t));
	printf("删除串s的第6,7,8位：");
	DispStr(DelStr(s,6,3));
	printf("将串s的1-3替换为t：");
	DispStr(RepStr(s, 1, 3, t)); 	
	printf("销毁s，t");
	DestroyStr(s);
	DestroyStr(t);
	return 0;
}