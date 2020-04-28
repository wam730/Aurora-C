#include<stdio.h>
#include<cstdlib>
int main()
{
	int english(int);
	int mouth;
	printf("Please input mouth: ");
	scanf_s("%d", &mouth);
	printf("The English name of %d is %c", mouth, english(mouth));
}
char english(int mouth)
{
	char* pm;
	char m[130] = { 'X','Jan.','Feb.','Mar.','Apr.','May.','Jun.','Jul.','Aug.','Sept',
		'Oct.','Nov.','Dec.' };
	pm = m;
	if ((mouth >= 1) && (mouth <= 12))
		return *(pm + mouth);
	else
		return *pm;
}