/*
 * SmallestRangeInKlists.cpp
 *
 *  Created on: 13-Jun-2018
 *      Author: dubeyalo
 */



#include<iostream>
#include<limits.h>
#include <algorithm>

using namespace std;
#if 0

#define N 1000
void findSmallestRange(int arr[][N], int n, int k);
// Driver program to test above functions
int SmallestRangeInKlists()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
	    findSmallestRange(arr, n, k);
    }
	return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// you are required to complete this function
// function should print the required range

struct arr_t
{
	int num, idx;
};

bool comp(arr_t a, arr_t b){
	return a.num < b.num ? true : false;
}

int Min(int a, int b)
{
	return a < b ? a : b;
}

int MaxSmall(int a, int b)
{
	return a > b ? a : b;
}

void findSmallestRangeUtil(arr_t arr[], int n)
{
	int a = -1,b =-1;
	for (int i = 0; i < n - 3; i++)
	{
		if ((arr[i].idx != arr[i + 1].idx) && (arr[i + 1].idx != arr[i + 2].idx)
				&& (arr[i].idx != arr[i + 2].idx))
		{
			int min = Min((arr[i+1].num - arr[i].num), (arr[i+2].num-arr[i+1].num));
			int max = MaxSmall((arr[i+1].num - arr[i].num), (arr[i+2].num-arr[i+1].num));
			if(min == max){
				a = arr[i].num ,b = arr[i+2].num;
				break;
			}
		}
	}
	cout << a << " " << b << endl;
	return;
}

void findSmallestRange(int arr[][N], int n, int k)
{
	int size = n * k;
	arr_t Arr[size];
	int ii = 0;
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			Arr[ii].num =arr[i][j];
			Arr[ii].idx = i;
			ii++;
		}
	}
	sort(Arr,Arr+size,comp);
	for(int i =0; i<size;i++)
		cout << Arr[i].num << " ";
	cout << endl;
	findSmallestRangeUtil(Arr, size);
}

#endif
