#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
int main()
{
	char ch;
	while(ch = getchar())
	{
		if (ch == '\n') break;
		while (ch >= '0' && ch <= '9') {
			putchar(ch);
			ch = getchar();
		}
		if (ch == '\n') break;
	}
	return 0;
}
