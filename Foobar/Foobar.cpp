// Foobar.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


extern int* GenRandNumbers(int* A, int len, int range_max, int range_min);
extern int MaxSubArray1(int* A, int len);
extern int MaxSubArray2(int* A, int len);
extern int MaxSubArray4(int* A, int len);

int main()
{
	int *A, n = 3000, sum;
	clock_t start, finish;
	A = (int*)malloc(sizeof(int*) * (n+1));
	A = GenRandNumbers(A, n+1, 10, -5);
	
	start = clock();
	sum = MaxSubArray1(A, n);
	finish = clock();
	printf("Time cost: %2.3f, %d\n", (double)(finish - start) / CLOCKS_PER_SEC, sum);

	start = clock();
	sum = MaxSubArray2(A, n);
	finish = clock();
	printf("Time cost: %2.3f, %d\n", (double)(finish - start) / CLOCKS_PER_SEC, sum);

	start = clock();
	sum = MaxSubArray4(A, n);
	finish = clock();
	printf("Time cost: %2.3f, %d\n", (double)(finish - start) / CLOCKS_PER_SEC, sum);
    return 0;
}

