//应该将名字修改为“最大连续子列和的四种算法的比较.cpp”，才更加严谨。
#include<stdio.h>
#include<time.h>
#include<cstdlib>
#define N 1000
int ThisNum,MaxNum,i,j;
int Subseq[N];
void inputNumber()
{
	srand((unsigned)time(NULL));
	for (i = 0; i < N; i++)
	{
		Subseq[i] = 1;//rand() % 10;
	}
}

int MaxSubseqSum0(int x[])//it's a bad way. N = 10000 makes it not work.  
{

	int k;
	for (i=0;i<N;i++)
	{
		for (j=i;j<N;j++)
		{
			ThisNum = 0;
			for (k=i;k<=j;k++)
			{
				ThisNum += x[k];
				if (ThisNum > MaxNum)
					MaxNum = ThisNum;
			}
		}
	}
	return MaxNum;
}

int MaxSubseqSum1(int x[])//Exhaustive method
{
	ThisNum = 0;
    MaxNum = 0;
	for (i = 0; i < N; i++)
	{
        ThisNum = 0;
		for (j = i; j < N; j++)
		{
			ThisNum += x[j];
			if (ThisNum > MaxNum)
                MaxNum = ThisNum;
		}
	}
	return MaxNum;
}

int Max(int A, int B, int C)
{
	return A > B ? A > C ? A : C : B > C ? B : C;
}

int DivideAndConquer(int List[], int left, int right)
{
    int MaxLeftSum, MaxRightSum; 
    int MaxLeftBorderSum, MaxRightBorderSum; 
    int LeftBorderSum, RightBorderSum;
    int center;

    if (left == right) { 
        if (List[left] > 0)  return List[left];
        else return 0;
    }

    center = (left + right) / 2; 
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, right);

    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for (i = center; i >= left; i--) {
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for (i = center + 1; i <= right; i++) {
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }
    return Max(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubseqSum2(int x[])//Divide and rule
{
    return DivideAndConquer(Subseq, 0, N - 1);
}

int MaxSubseqSum3(int x[])//Online processing
{
    ThisNum = 0;
    MaxNum = 0;
    for (i = 0; i < N; i++)
    {
        ThisNum += x[i];
        if (ThisNum > MaxNum) 
            MaxNum = ThisNum;
        if (ThisNum < 0) 
            ThisNum = 0;
    }
    return MaxNum;
}

double Time(int x[] ,int (*p)(int []))
{
    clock_t Start;
    Start = clock();
    p(x);
    double duration = ((double)clock() - (double)Start) / CLK_TCK;
    return duration;
}

int main()
{
	inputNumber();
  //printf("The largest continuous sub-column sum is %10d, and it takes %10lf to run MaxSubseqSum0 for %d times. \n", MaxSubseqSum0(Subseq),Time(Subseq,MaxSubseqSum0),N);
	printf("The largest continuous sub-column sum is %10d, and it takes %10lf to run MaxSubseqSum1 for %d times. \n", MaxSubseqSum1(Subseq),Time(Subseq,MaxSubseqSum1),N);
    printf("The largest continuous sub-column sum is %10d, and it takes %10lf to run MaxSubseqSum2 for %d times. \n", MaxSubseqSum2(Subseq), Time(Subseq, MaxSubseqSum2), N);
    printf("The largest continuous sub-column sum is %10d, and it takes %10lf to run MaxSubseqSum3 for %d times. \n", MaxSubseqSum3(Subseq), Time(Subseq, MaxSubseqSum3), N);
    system("pause");
}
