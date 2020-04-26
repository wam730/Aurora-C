#include<stdio.h>
int main()
{
	int a,b,c;
	double x,y,z;
	printf("Please input a,b,c,x,y and z:\n");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	scanf("%lf",&x);
	scanf("%lf",&y);
	scanf("%lf",&z);
	printf("a = %d b = %d c = %d\nx = %.3lf y = %.3lf z = %.3lf",a,b,c,x,y,z);
	return 0;
 } 
