/*
 * MaximumLengthChainOfPairs.cpp
 *
 *  Created on: 16-Feb-2019
 *      Author: napster
 */

#if 0
#include <iostream>

struct pair{
	int a, b;
};

int maxChainLength(pair arr[], int N)
{
	int mcl[N], max = 0;

	for(int i=0;i<N;++i)
		mcl[i]=1;

	for(int i =1; i< N; ++i){
		for(int j = 0; j < i; ++j){
			if((arr[i].a > arr[j].b) && mcl[i] < mcl[j] +1)
				mcl[i] = mcl[j] +1;
		}
	}

	for(int i=0; i<N; ++i)
		if(max < mcl[i])
			max = mcl[i];

	return max;
}

/* Driver program to test above function */
int MaximumLengthChainOfPairs()
{
    struct pair arr[] = { {5, 24}, {15, 25},
                          {27, 40}, {50, 60} };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of maximum size chain is %d\n",
           maxChainLength( arr, n ));
    return 0;
}
#endif
