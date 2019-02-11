/*
 * KnapsackProblem.cpp
 *
 *  Created on: 13-Feb-2019
 *      Author: napster
 */
#if 0
#include <stdio.h>
#include <iostream>

using namespace std;

inline int max(int a, int b) { return (a>b)?a:b;}

int knapSackRec(int W, int wt[], int val[], int N)
{
	if((N==0)||(W==0))
		return 0;

	if(wt[N-1]> W)
		return knapSackRec(W, wt, val, N-1);
	else
		return max(val[N-1] + knapSackRec(W-wt[N-1], wt, val, N-1),
				knapSackRec(W, wt, val, N-1));
}

int knapSackDP(int W, int wt[], int val[], int N)
{
	int i, w;
	int K[N+1][W+1];
	for(i = 0; i<=N;++i){
		for(w=0; w<=W; ++w){
			if((i==0)||(w==0))
				K[i][w] = 0;
			else if (wt[i-1] <= w)
				K[i][w] = max(val[i-1]+ K[i-1][w -wt[i-1]],K[i-1][w]);
			else
				K[i][w] = K[i-1][w];
		}
	}
	return K[N][W];
}

// Driver program to test above function
/*
int KnapsackProblem()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d\n", knapSackRec(W, wt, val, n));
    printf("%d", knapSackDP(W, wt, val, n));
    return 0;
}
*/

int KnapsackProblem()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N, W;
		cin >> N >> W;
		int wt[N], val[N];
		for(int i=0;i<N; i++)
			cin >> wt[i];
		for(int i=0;i<N; i++)
			cin >> val[i];

		cout << knapSackDP(W, wt, val, N) << endl;
	}
	return 0;
}
#endif
