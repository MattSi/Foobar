#include "stdafx.h"
#include <stdlib.h>
#include <assert.h>
#include <time.h>


int* GenRandNumbers(int* A, int len, int range_max, int range_min) {
	assert(A != NULL);
	srand((unsigned)time(NULL));

	for (int i = 0; i < len; i++) {
		A[i] = (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
	}

	return A;
}

int MaxSubArray1(int* A, int len /* Index starts from 1 */) {
	int maxSum;
	assert(A != NULL );

	maxSum = A[1];
	for (int i = 1; i <= len; i++) {
		for (int j = i; j <= len; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += A[k];
			}
			if (sum > maxSum) maxSum = sum;
		}
	}
	return maxSum;	
}

int MaxSubArray2(int* A, int len /* Index starts from 1 */) {
	int maxSum, *S;
	S = (int*)malloc(sizeof(int*) * (len+1));

	assert(A!= NULL && S != NULL);

	S[0] = 0;
	maxSum = A[1];
	for (int i = 1; i <= len; i++) {
		S[i] = S[i - 1] + A[i];
	}
	for (int i = 1; i <= len; i++) {
		for (int j = i; j <= len; j++) {
			maxSum = __max(maxSum, S[j] - S[i-1]);
		}
	}
	free(S);
	return maxSum;
}

int MaxSubArray3(int *A, int left, int right) {
	int v, L, R, maxSum;
	if (right - left == 1) return A[left];

	int m = left + (right - left) / 2;
	//int maxs = MaxSubArray3(A, )
	return 0;
}

int MaxSubArray4(int *A, int n /* Index starts from 1 */) {
	assert(A != NULL);
	int maxsofar = 0, maxrightend = 0;

	for (int i = 1; i <= n; i++) {
		maxrightend += A[i];
		if (maxrightend < 0)maxrightend = 0;
		maxsofar = __max(maxsofar, maxrightend);
	}
	return maxsofar;
}










