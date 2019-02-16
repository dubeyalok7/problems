/*
 * MissingNumberInArray.cpp
 *
 *  Created on: 09-Feb-2019
 *      Author: napster
 */

#include<iostream>

#if 0
#include <algorithm>

using namespace std;

long MNInArray(long arr[], int N)
{
	long st=1;
	for(int i=0;i<N-1;++i, ++st){
		if(arr[i] != st)
			return st++;
	}
	return st;
}

int cmp(const void * a, const void * b)
{
    return ( *(long*)a - *(long*)b );
}

int MissingNumberInArray()
{
	int T;
	cin >> T;

	while(T--)
	{
		long N;
		cin >> N;
		long arr[N-1];
		for(int i=0;i<N-1;++i){
			cin >> arr[i];
		}
		qsort(arr,N-1,sizeof(long), cmp);
		cout << MNInArray(arr, N) << endl;
	}
	return 0;
}
#endif
