/*
 * SherlockAndAnagrams.cpp
 *
 *  Created on: 10-Aug-2018
 *      Author: napster
 */

#include <bits/stdc++.h>

using namespace std;

string sortStr(string s) {
	int ch[26]={0};
	string str;
	for(int i=0;i<s.length(); i++)
		ch[s[i]-'a']++;
	for(int i=0;i<26;i++)
		for(int j=0;j<ch[i];j++)
			str.push_back(i +'a');
	return str;
}

void subString(string s, map<string, int> &m)
{
	for(auto i=0;i<s.length()-1;i++){
		for(auto j=i+1; j < s.length();j++)
			if(s[i]==s[j]){
				string str = s.substr(i,1);
				if(m.find(str)==m.end())
					m.insert(make_pair(str,1));
				else
					m[str]++;
			}
	}

	for (int i = 0; i < s.length(); i++) {
		for (int len = 2; len <= s.length() - i; len++) {
			string str = s.substr(i, len);
			str = sortStr(str);
			if (m.find(str) == m.end()) {
				m.insert(make_pair(str, 1));
			} else
				m[str]++;
		}
	}
}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
	int cnt = 0;
	map<string, int> m;
	subString(s, m);
	map<string, int>::iterator itr;
	for(itr = m.begin(); itr != m.end(); ++itr){
		if(itr->first.length()==1)
			cnt+= itr->second;
		else if(itr->second > 1){
			if(itr->second%2)
				cnt+= itr->second;
			else
				cnt += itr->second/2;
		}
	}
	return cnt;
}

int SherlockAndAnagrams()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);
        int result = sherlockAndAnagrams(s);
        cout << result << "\n";
    }
    return 0;
}

