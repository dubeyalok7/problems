/*
 * SubarrayWithGivenSum.cpp
 *
 *  Created on: 10-Feb-2019
 *      Author: napster
 */



#include <iostream>

using namespace std;

void find_max_index(int arr[], int N, int S)
{
	int lis[N]={0,};
	int s_idx = 0, e_idx = 0;
	int max =0, fs= 0, fe=0;

	for(int i = 0; i<N; i++){
		lis[i] = arr[i];
		s_idx = i;
		for(int j = i+1; j< N; ++j){
			if((lis[j-1] + arr[j] <= S))
				lis[j] = lis[j-1]+arr[j];
			else if(arr[j] < S){
				lis[j] = arr[j];
				s_idx = j;
			}
			if(lis[j] == S){
				e_idx= j;
				if(max < (e_idx-s_idx)){
					max = e_idx-s_idx;
					fs = s_idx + 1;
					fe = e_idx +1;
				}
			}
		}
	}
	cout << fs << " " << fe << endl;
}

int SubarrayWithGivenSum()
{
	int T;
	cin >> T;
	while(T--){
		int N, S;
		cin >> N >> S;
		int arr[N];
		for(int i =0; i< N; ++i)
			cin >> arr[i];
		find_max_index(arr, N, S);
	}
	return 0;
}
