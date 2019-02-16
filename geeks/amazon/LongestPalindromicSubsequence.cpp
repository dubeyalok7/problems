/*
 * LongestPalindromicSubsequence.cpp
 *
 *  Created on: 16-Feb-2019
 *      Author: napster
 */

#if 0
#include <iostream>
#include <string.h>

using namespace std;

inline int max(int a, int b) { return a>b?a:b; }

int lpsRec(char str[], int st, int en)
{
	if(st == en)
		return 1;

	if((str[st] = str[en]) && (st+1 == en))
		return 2;
	if(str[st] == str[en])
		return lpsRec(str,  st+1, en-1)+2;

	return max(lpsRec(str,st+1, en), lpsRec(str,st, en -1));

}

int lpsDP(char str[], int N)
{
	if(N==1)
		return 1;
	int mat[N][N];
	for(int i=0;i<N;i++)
		mat[i][i]=1;

	for(int cl =2; cl <=N; ++cl)
	{
		for(int i=0; i<N-cl+1;i++)
		{
			int j = i + cl-1;
			if(str[i] == str[j] && cl ==2)
				mat[i][j] = 2;
			else if(str[i]==str[j])
				mat[i][j] = mat[i+1][j-1]+2;
			else
				mat[i][j] = max(mat[i+1][j], mat[i][j-1]);
		}
	}
	return mat[0][N-1];
}

/* Driver program to test above functions */
int LongestPalindromicSubsequence()
{
    char seq[] = "GEEKSFORGEEKS";
    int n = strlen(seq);
    cout << "The length of the LPS is " << lpsRec(seq, 0, n-1) <<endl;
    cout << "The length of the LPS is " << lpsDP(seq, n) <<endl;
    return 0;
}
#endif
