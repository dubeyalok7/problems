/*
 * CountInversionsInAnArray.cpp
 *
 *  Created on: 17-Feb-2019
 *      Author: napster
 */
#if 0
#include <iostream>

using namespace std;

int merge(int arr[], int l, int m, int r)
{
	int count = 0;
	int i, j, k;
	int n1 = m - l +1;
	int n2 = r - m;

	int L[n1], R[n2];

	for(i =0; i<n1; ++i)
		L[i] = arr[l+i];
	for(j =0; j<n2; ++j)
		R[j] = arr[m + j + 1];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray

	while(i<n1 && j<n2)
	{
		if(L[i]<= R[j])
			arr[k++] = L[i++];
		else
		{
			arr[k++] = R[j++];
			count++;
		}
	}

	while(i<n1)
		arr[k++] = L[i++];

	while(j<n2)
		arr[k++] = R[j++];

	return count;
}

int mergeSort(int arr[], int l, int r)
{
	int inv_count = 0;
	if(l < r)
	{
		int m = l + (r-l)/2;
		inv_count = mergeSort(arr, l, m);
		inv_count += mergeSort(arr, m+1, r);
		inv_count += merge(arr, l, m, r);
	}
	return inv_count;
}

int getInvCount(int arr[], int n)
{
	return mergeSort(arr,0,  n-1);

}
// Driver Code
int CountInversionsInAnArray()
{
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " Number of inversions are " << getInvCount(arr, n) << endl;
    for(int i=0; i< n; i++)
    	cout << arr[i] << " ";
    cout << endl;
    return 0;
}
#endif
