#include<stdio.h>
#include<math.h>
#include<time.h>
#include<cstdlib>
#define MAX 100
#define RUNS 1000000
#define X 1.1



double Time(double x, double n, double (*p)(double, double))
{
	clock_t start = clock();
	for (int i = 0; i < RUNS; i++)
	{
		p(x, n);
	}
	double duration = (double)(clock() - start) / CLK_TCK;
	return duration;
}

//functions below are to calculate the value of f(x)
// when x is assigned as a certain number
// f(x) = 1 + x + x^2/2 + ... + x^100/100

double Function1(double x, double n)
{
	double f = 1;
	for (int i = 1; i <= n; i++)
	{
		f += pow(x, i) / i;
	}
	return f;
}
double coefs[MAX+1];
double Function2(double x, double n) 
{
	double f = 1;
	for (int i = 1; i <= n; i++)
	{
		f += coefs[i] * pow(x, i);
	}
	return f;
}
double Function3(double x, double n) //Qin Jiushao
{
	double sum = 1.0 / n;
	for (int i = n; i > 0; i--)
	{
		sum = coefs[i - 1] + x * sum;
	}
	return sum;
}
int main()
{
	coefs[0] = 1.0;
	for (int i = 1; i < MAX + 1; i++)
	{
		coefs[i] = 1.0 / i;
	}
	printf("Result1: %lf.\n", Function1(X, MAX));
	printf("Result2: %lf.\n", Function2(X, MAX));
	printf("Result3: %lf.\n", Function3(X, MAX));
	printf("It takes %lf to run func1 for %ld times.\n", Time(X, MAX, Function1), RUNS);
	printf("It takes %lf to run func2 for %ld times.\n", Time(X, MAX, Function2), RUNS);
	printf("It takes %lf to run func2 for %ld times.\n", Time(X, MAX, Function3), RUNS);
	system("pause");
	return 0;
}
