#include <stdio.h>
#include <cstdlib>
int main(){
	int i1 = 1 , i2 = 2 , i3 = 3;
	int const *p1;//是说*p1所指向的地址是永久的，只能指向i1，而不能再指向其他的数 
	const int *p2 = &i2;
	int *const p3 = &i3;
	p1 = &i1;
	p1 = &i2;
	printf("%d",*(p1+1));
//	p1 = &i2; 
//	p1++;
}
