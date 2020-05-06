#include <stdio.h>
int main()
{
	typedef int i;	
	i l = 0;
	printf("%d\n%p\n%d",&l,&l,sizeof(l));
}
