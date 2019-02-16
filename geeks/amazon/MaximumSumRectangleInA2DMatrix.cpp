/*
 * MaximumSumRectangleInA2DMatrix.cpp
 *
 *  Created on: 16-Feb-2019
 *      Author: napster
 */
#if 0
#include <iostream>
#include <limits.h>
#include <string.h>

#define ROW 4
#define COL 5

using namespace std;

int kadane(int arr[], int *start, int *finish, int N)
{
	int sum = 0, maxSum = INT_MIN, i;
	*finish = -1;

	int local_start = 0;

	for(i = 0; i< N; ++i)
	{
		sum +=arr[i];
		if(sum < 0)
		{
			sum = 0;
			local_start = i +1;
		}
		else if(sum > maxSum)
		{
			maxSum = sum;
			*start = local_start;
			*finish = i;
		}
	}

	if (*finish != -1)
		return maxSum;

	maxSum = arr[0];
	*start = *finish = 0;

	for (i = 1; i < N; ++i) {
		if (arr[i] > maxSum) {
			maxSum = arr[i];
			*start = *finish = i;
		}
	}
	return maxSum;
}

void findMaxSum(int M[][COL])
{
	int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;

	int left, right;
	int temp[ROW], sum, start, finish;

	for(left = 0; left < COL; ++left)
	{
		memset(temp, 0, sizeof(temp));
		for(right = left; right < COL; ++right)
		{
			for(int i = 0 ;i < ROW; ++i)
				temp[i] += M[i][right];

			sum = kadane(temp, &start, &finish, ROW);

			if(sum > maxSum)
			{
				maxSum = sum;
				finalLeft = left;
				finalRight = right;
				finalTop = start;
				finalBottom = finish;
			}
		}
	}

	printf("(Top, Left) [%d, %d]\n",finalTop, finalLeft);
	printf("(Bottom, Right) [%d, %d]\n", finalBottom, finalRight);
	printf("SUM: %d\n", maxSum);
}

// Driver program to test above functions
int MaximumSumRectangleInA2DMatrix()
{
    int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };

    findMaxSum(M);

    return 0;
}
#endif
