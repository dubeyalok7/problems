/*
 * EggDrop.cpp
 *
 *  Created on: 10-Feb-2019
 *      Author: napster
 */
#if 0
#include <iostream>
#include <limits.h>

using namespace std;

int max(int a, int b) { return a>b?a:b; }

int eggDropRec(int n, int k)
{
	if(k==1 || k==0)
	return k;

	if(n == 1)
		return k;

	int min = INT_MAX, x, res;

	for(x = 1; x<= k; x++)
	{
		res = max(eggDropRec(n-1, x-1), eggDropRec(n, k-x));
		if(res < min)
			min = res;
	}
	return min +1;
}

int eggDropDP(int n, int k)
{
	int eggFloor[n+1][k+1];
	int res;
	int i, j, x;

	for(i = 1; i<= n; ++i)
	{
		eggFloor[i][1] = 1;
		eggFloor[i][0] = 0;
	}

	for(j=1; j<=k; ++j)
		eggFloor[1][j]= j;

	for(i=2; i<= n; ++i)
	{
		for(j=2;j<=k; ++j)
		{
			eggFloor[i][j] = INT_MAX;
			for(x =1; x<= j; ++x)
			{
				res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
				if(res < eggFloor[i][j])
					eggFloor[i][j] = res;
			}

		}
	}
	return eggFloor[n][k];
}

/* Driver program to test to pront printDups*/
int EggDrop()
{
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		printf("\nMinimum number of trials in worst case with %d eggs and "
				"%d floors is %d \n", n, k, eggDropRec(n, k));
		printf("\nMinimum number of trials in worst case with %d eggs and "
				"%d floors is %d \n", n, k, eggDropDP(n, k));
	}
    return 0;
}
#endif
