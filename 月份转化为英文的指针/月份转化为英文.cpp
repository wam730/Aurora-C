#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
int main()
{
	const char* english(int);
	int month;
	printf("Please input month: ");
	scanf("%d", &month);
	printf("The English name of %d is %s", month, english(month));
}
const char* english(int month)
{
	const char* m[13]= { "X","Jan.","Feb.","Mar.","Apr.","May.","Jun.","Jul.","Aug.","Sept",
		"Oct.","Nov.","Dec." };
	if ((month >= 1) && (month <= 12)) return m[month];
	else return m[0];
}
