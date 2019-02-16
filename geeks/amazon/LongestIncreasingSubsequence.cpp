/*
 * LongestIncreasingSubsequence.cpp
 *
 *  Created on: 09-Feb-2019
 *      Author: napster
 */
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
#if 0
int lisUtil(int arr[], vector<vector<int>> &mat, int n)
{
	int max = INT_MIN,cnt;
	for(int i=0;i<n; i++){
		cnt=1;
		int val = arr[i];
		mat[i][i] = cnt;
		for(int j=i;j<n;j++){
				if(val < arr[j]){
				val = arr[j];
				mat[i][j] = ++cnt;
			}

		}
	}
	for(int i=0; i<n; ++i){
		if(mat[i][n-1] > max)
			max = mat[i][n-1];
	}
	return max;
}

int lis(int arr[], int n)
{
	vector<vector<int>> mat;
	mat.resize(n,vector<int>(n));
	for(int i=0;i<n;++i){
		for(int j=0; j< n; j++)
			mat[i][j]=0;
	}
	return lisUtil(arr, mat, n);
}

int lis( int arr[], int n )
{
    int lis[n], max =INT_MIN;

    lis[0] = 1;

    for (int i = 1; i < n; i++ )
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
    for(int i=0;i<n; i++)
    	if(max < lis[i])
    		max= lis[i];
    return max;
}


int lis(int arr[], int n)
{

}

int LongestIncreasingSubsequence()
{
    int T;
    cin >> T;
    while(T--){
    	int N;
    	cin >> N;
    	int arr[N];
    	for(int i=0;i<N; ++i)
    		cin >> arr[i];
    	cout << lis(arr, N) << endl;
    }
    return 0;
}
#endif
