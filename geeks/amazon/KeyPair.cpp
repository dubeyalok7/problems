/*
 * KeyPair.cpp
 *
 *  Created on: 09-Feb-2019
 *      Author: napster
 */
#include <iostream>

using namespace std;
#if 0
void sUtil(int arr[], int buff[], int N, int X, int idx, int i, int r, bool &val)
{
	if(r==idx){
		if((buff[0]+buff[1])==X)
			val = true;
		return;
	}
	if(i >= N)
		return;
	buff[idx]=arr[i];
	sUtil(arr, buff, N, X, idx+1, i+1, r, val);
	sUtil(arr, buff, N, X, idx, i+1, r, val);
}

bool solution(int arr[], int N, int X)
{
	bool val =false;
	int buff[2];
	sUtil(arr, buff, N, X, 0, 0, 2, val);
	return val;
}


int cmp(const void * a, const void * b)
{
    return ( *(long*)a - *(long*)b );
}

bool solution(int arr[], int N, int X)
{
	qsort(arr, N, sizeof(int), cmp);
	int l =0, r= N-1;
	while(l<r){
		if((arr[l]+arr[r]) == X)
			return true;
		if((arr[l]+arr[r]) < X)
			l++;
		else
			r--;
	}
	return false;
}

int KeyPair()
{
	int T;
	cin >> T;
	while(T--){
		int N, X;
		cin >> N >> X;
		int arr[N];
		for(int i=0;i<N;++i)
			cin >> arr[i];
		cout << (solution(arr, N, X)?"Yes":"No") << endl;
	}

	return 0;
}
#endif
