/*
 * BoxStackingProblem.cpp
 *
 *  Created on: 16-Feb-2019
 *      Author: napster
 */
#if 0
#include <iostream>

using namespace std;

struct Box{
	int h, w, d;
};

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

int compare(const void *a, const void *b)
{
	return (((*(Box *)b).d * (*(Box *)b).w) - ((*(Box *)a).d)*((*(Box *)a).w));
}

int maxStackHeight(Box arr[], int N)
{
	Box rot[3*N];
	int idx = 0;

	for(int i =0; i<N; ++i)
	{
		//Copy original box
		rot[idx].h = arr[i].h;
		rot[idx].d = max(arr[i].d, arr[i].w);
		rot[idx].w = min(arr[i].d, arr[i].w);
		idx++;

		//First rotation box
		rot[idx].h = arr[i].w;
		rot[idx].d = max(arr[i].h, arr[i].d);
		rot[idx].w = min(arr[i].h, arr[i].d);
		idx++;

		//Second rotation box
		rot[idx].h = arr[i].d;
		rot[idx].d = max(arr[i].h, arr[i].w);
		rot[idx].w = min(arr[i].h, arr[i].w);
		idx++;
	}

	N = 3*N;
	qsort(rot, N, sizeof(rot[0]), compare);

	int msh[N], max = 0;

	for(int i=0; i<N; ++i)
		msh[i] = rot[i].h;

	for(int i =1; i<N;++i){
		for(int j = 0; j<i; j++){
			if((rot[i].w < rot[j].w)&&
			   (rot[i].d < rot[j].d) &&
			   (msh[i] < msh[j] + rot[i].h))
			{
				msh[i] = msh[j] + rot[i].h;
			}
		}
	}
	for(int i=0 ;i < N; ++i)
		if(max < msh[i])
			max = msh[i];
	return max;
}

/* Driver program to test above function */
int BoxStackingProblem()
{
  Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  int n = sizeof(arr)/sizeof(arr[0]);

  printf("The maximum possible height of stack is %d\n",
         maxStackHeight (arr, n) );

  return 0;
}
#endif
