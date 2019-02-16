/*
 * TwoStrings.cpp
 *
 *  Created on: 10-Aug-2018
 *      Author: dubeyalok
 */

#include <bits/stdc++.h>

using namespace std;
#if 0
// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
	int str[26] ={0};
	for(auto i = 0; i<s1.length();i++)
		str[s1[i]-'a']++;
	for(auto i=0;i<s2.length();i++)
		if(str[s2[i]-'a'])
			return "YES";
	return "NO";
}

int TwoStrings()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        cout << result << "\n";
    }

    //fout.close();

    return 0;
}
#endif
