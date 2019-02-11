/*
 * FindFirstSetBit.cpp
 *
 *  Created on: 13-Feb-2019
 *      Author: napster
 */
#if 0
#include <iostream>

using namespace std;

int FindFirstSetBit()
{
	int T;
	cin >> T;
	while(T--){
		int N, cnt = 1;
		cin >> N;
		while(!(N&1)){
			N>>=1;
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
#endif
