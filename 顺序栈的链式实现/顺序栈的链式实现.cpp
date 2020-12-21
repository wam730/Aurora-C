#include<stdio.h>
#include<malloc.h>
typedef char ElemType;

typedef struct linknode
{
	ElemType data;
	struct linknode* next;
}LinkStNode;

void InitStack(LinkStNode*& s)
{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}

void DestroyStack(LinkStNode*& s)
{
	LinkStNode * p = s->next;
	while (s!= NULL)
	{
		free(s);
		s = p;
		if(p!=NULL)
		{
			p = p->next;
		}
	}
}

void Push(LinkStNode*& s, ElemType e)
{
	LinkStNode* p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

bool StackEmpty(LinkStNode* s)
{
	if (s != NULL)
	{
		return (s->next == NULL);
	}
	else
	{
		return true;
	}
}

bool Pop(LinkStNode*& s, ElemType& e)
{
	LinkStNode* p;
	if (s->next == NULL) return false;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}

bool GetTop(LinkStNode* s,ElemType& e)
{
	if (s->next == NULL) return false;
	e = s->next->data;
	return true;
}

bool ShowStack(LinkStNode* s)
{
	LinkStNode* p = s->next;
	if (s->next == NULL) return false;
	else
	{
		printf("输出栈:");
		while (p->next != NULL)
		{
			printf("%3c", p->data);
			p = p->next;
		}
		printf("%3c", p->data);
		return true;
	}
}

void trans(const char* exp,char postexp[])
{
	char e;
	LinkStNode* Optr;
	InitStack(Optr);
	int i = 0;
	while (*exp != '\0')
	{
		switch (*exp)
		{
		case '(':
			Push(Optr, '(');
			exp++;
			break;
		case')':
			Pop(Optr, e);
			while (e!='(')
			{
				postexp[i++] = e;
				Pop(Optr, e);
			}
			exp++;
			break;
		case'+':
		case'-':
			while (!StackEmpty(Optr))
			{
				GetTop(Optr, e);
				if (e != '(')
				{
					postexp[i++] = e;
					Pop(Optr, e);
				}
				else
					break;
			}
			Push(Optr, *exp);
			exp++;
			break;
		case'*':
		case'/':
			while (!StackEmpty(Optr))
			{
				GetTop(Optr, e);
				if (e == '*' || e == '/')
				{
					postexp[i++] = e;
					Pop(Optr, e);
				}
				else
					break;
			}
			Push(Optr, *exp);
			exp++;
			break;
		default:
			while (*exp >= '0' && *exp<= '9')
			{
				postexp[i++] = *exp;
				exp++;
			}
			postexp[i++] = '#';
			break;
		}
	}
	while (!StackEmpty(Optr))
	{
		Pop(Optr, e);
		postexp[i++] = e;
	}
	postexp[i] = '\0';
	DestroyStack(Optr);
}
int main()
{
	LinkStNode* s;
	ElemType e1, e2, e3, eTop;
	ElemType postexp[1000];
	const ElemType* exp="1+3*5*(2+9)/2+5-5*5";
	InitStack(s);
	printf("栈是否为空：%d\n\n", StackEmpty(s));
	printf("先后依次序入栈1 2 3 4 5 6 7 8\n");
	Push(s, '1');
	Push(s, '2');
	Push(s, '3');
	Push(s, '4');
	Push(s, '5');
	Push(s, '6');
	Push(s, '7');
	Push(s, '8');
	ShowStack(s);
	printf("\n\n栈是否为空：%d", StackEmpty(s));
	printf("\n\n先后依次序出栈8 7 6\n");
	Pop(s, e1);
	Pop(s, e2);
	Pop(s, e3);
	ShowStack(s);
	GetTop(s, eTop);
	printf("\n\n栈顶元素是:%c\n", eTop);
	DestroyStack(s);
	printf("\n摧毁栈,栈是否为空：%d\n", StackEmpty(s));
	printf("\n有一个四则运算的表达式‘1+3*5+(2+9)/2+5-5*5’，将求出其后缀表达式：");
	trans(exp, postexp);
	printf("%s", postexp);
	return 0;
}