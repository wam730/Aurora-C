#include <stdio.h>
#include <cstdlib>
int main(){
	int i1 = 1 , i2 = 2 , i3 = 3;
	int const *p1;//��˵*p1��ָ��ĵ�ַ�����õģ�ֻ��ָ��i1����������ָ���������� 
	const int *p2 = &i2;
	int *const p3 = &i3;
	p1 = &i1;
	p1 = &i2;
	printf("%d",*(p1+1));
//	p1 = &i2; 
//	p1++;
}
