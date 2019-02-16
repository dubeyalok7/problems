/*
 * MinimizeStringValue.cpp
 *
 *  Created on: 14-Feb-2019
 *      Author: napster
 */
#if 0
#include <iostream>

using namespace std;


int minStrValue(string str, int K)
{
	long freq[26]={0,};
	long sum= 0;
	for(int i=K+1; i<str.length();++i)
		freq[str[i]-'a']++;
	for(int i=0;i<26; ++i){
			freq[i]= (freq[i])*(freq[i]);

		sum += freq[i];
	}
	return sum;
}

int MinimizeStringValue()
{
	int T;
	cin >> T;
	while(T--)
	{
		string str;
		int K;
		cin >> str >> K;
		cout << minStrValue(str, K) << endl;
	}
	return 0;
}
#endif
