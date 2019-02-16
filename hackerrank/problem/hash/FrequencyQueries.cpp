/*
 * FrequencyQueries.cpp
 *
 *  Created on: 13-Aug-2018
 *      Author: dubeyalo
 */

#include <bits/stdc++.h>

using namespace std;
#if 0
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
#if 0
vector<int> freqQuery(vector<vector<int>> queries) {
	map<int, int> freq;
	map<int, int> datas;
	vector<int> output;
	for (auto &q : queries)
	{
		switch (q[0])
		{
		case 1:
			datas[q[1]]++;
			freq[datas[q[1]]]++;
			freq[datas[q[1]] - 1]--;
			if (freq[datas[q[1] - 1]] < 0)
			{
				freq[datas[q[1] - 1]] = 0;
			}

			break;

		case 2:
			datas[q[1]]--;
			freq[datas[q[1]]]++;
			freq[datas[q[1]] + 1]--;

			if (freq[datas[q[1]] + 1] < 0)
			{
				freq[datas[q[1]] + 1] = 0;
			}

			if (datas[q[1]] < 0)
			{
				datas[q[1]] = 0;
			}
			break;

		case 3:
			if (freq.find(q[1]) != freq.end() && freq[q[1]] > 0)
			{
				output.push_back(1);
			}

			else
			{
				output.push_back(0);
			}
			break;
		}
	}

	return output;
}
#endif
#if 0
// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
	vector<int> vec;
	map<int, int>m;
	map<int, int>::iterator it;
	for(auto i = 0; i<queries.size(); ++i){
		switch(queries[i][0]){
		case 1:
			if(m.find(queries[i][1])==m.end())
				m.insert(make_pair(queries[i][1], 1));
			else
				m[queries[i][1]]++;
			break;
		case 2:
			it = m.find(queries[i][1]);
			if(it != m.end())
				m.erase(it);
			break;
		case 3:
			bool flag = false;
			for(it = m.begin(); it != m.end(); ++it)
				if(it->second == queries[i][1]){
					flag = true;
					break;
				}
			if(flag)
				vec.push_back(1);
			else
				vec.push_back(0);
			break;
		}
	}
	return vec;
}
#endif
int FrequencyQueries()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];

        if (i != ans.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    //fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
#endif
