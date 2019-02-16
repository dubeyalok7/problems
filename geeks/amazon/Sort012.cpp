/*
 * Sort012.cpp
 *
 *  Created on: 17-Feb-2019
 *      Author: napster
 */
#if 0
#include <iostream>

using namespace std;

void printArray(int arr[], int N)
{
	for(int i=0 ;i<N; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void sort012(int arr[], int N)
{
	int a0 = 0,a1 = 0,a2 = 0;
	for(int i=0; i<N; i++){
		switch(arr[i]){
		case 0: a0++; break;
		case 1: a1++; break;
		case 2: a2++; break;
		}
	}
	int k=0;
	for(int i=0;i<a0;i++)
		arr[k++] = 0;
	for(int i=0;i<a1;i++)
		arr[k++] = 1;
	for(int i=0; i<a2;i++)
		arr[k++] = 2;
}

// Driver Code
int Sort012()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    sort012(arr, arr_size);

    cout << "array after segregation ";
    printArray(arr, arr_size);

    getchar();
    return 0;
}
#endif
