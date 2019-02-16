/*
 * EqualToProduct.cpp
 *
 *  Created on: 11-Feb-2019
 *      Author: napster
 */
#include <iostream>
#include <map>

#if 0

using namespace std;

bool isProductEqual(uint64_t arr[], uint64_t N, uint64_t P)
{
	map<uint64_t, int> m;
	map<uint64_t, int>::iterator it;
	for(int i=0;i<N;i++){
		if(m.find(arr[i]) != m.end())
			m[arr[i]]++;
		else
			m.insert(make_pair(arr[i], 1));
	}
	for(uint64_t i=0; i<N; ++i){
	    if((arr[i]==0)|| (P%arr[i]))
			continue;
		long num = P/arr[i];
		it = m.find(num);
		if(it == m.end())
			continue;
		if((num == arr[i])&& (it->second > 1))
			return true;
		else if((num == arr[i])&& (it->second == 1))
			return false;
		if(num != arr[i])
			return true;
	}
	return false;
}

int EqualToProduct()
{
	int T;
	cin >> T;
	while(T--){
		uint64_t N, P;
		cin >> N >> P;
		uint64_t arr[N];
		for(uint64_t i =0; i<N; i++)
			cin >> arr[i];
		cout << (isProductEqual(arr, N, P)?"Yes":"No") << endl;
	}
	return 0;
}
/*
5
8 46
5 7 9 22 15 344 92 8
5 25
1 2 3 4 5
8 63
5 7 9 22 15 344 92 8
5 2
1 2 3 4 5
2 18446744073709551614
2 9223372036854775807

 */
#endif
