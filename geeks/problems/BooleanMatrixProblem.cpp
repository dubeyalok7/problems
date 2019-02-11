/*
 * BooleanMatrixProblem.cpp
 *
 *  Created on: 13-Feb-2019
 *      Author: napster
 */
#if 0
#include <iostream>

using namespace std;
#include <vector>

void modifiedMat(vector<vector<int>> &mat, int R, int C)
{
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(mat[i][j]){

			}
		}
	}
}

int BooleanMatrixProblem()
{
	int T;
	cin >> T;
	while(T--)
	{
		int R,C;
		cin >> R >>C;
		vector<vector<int>> vec(R,vector<int>());
		for(int i=0;i<R;++i){
			for(int j=0; j<C;++j){
				int val; cin >> val;
				vec[i].push_back(val);
			}
		}
		modifiedMat(vec, R, C);
	}
	return 0;
}
#endif
