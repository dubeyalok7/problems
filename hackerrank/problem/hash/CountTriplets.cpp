/*
 * CountTriplets.cpp
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

void hmap_update(vector<long> c, int combo, vector<long> &vec)
{
    int n = c.size();
    for (int i = 0; i < n; ++i) {
        if ((combo >> i) & 1)
            vec.push_back(c[i]);
    }
}

void combo(vector<long> c, int k, map<vector<long>, int> &m)
{
    int n = c.size();
    int combo = (1 << k) - 1;       // k bit sets
    while (combo < 1<<n) {
    	vector<long> vec;
    	hmap_update(c, combo, vec);
        if(m.find(vec)== m.end())
        	m.insert(make_pair(vec,0));
        else
        	m[vec]++;

        int x = combo & -combo;
        int y = combo + x;
        int z = (combo & ~y);
        combo = z / x;
        combo >>= 1;
        combo |= y;
    }
}


bool isGP(vector<long> vec, int r)
{
	if(vec[0] != vec[1]/r)
		return false;
	if(vec[1] != vec[2]/r)
		return false;
	return true;
}

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
	int cnt=0;
	map<vector<long>, int> m;
	int buff[3];
	combo(arr, 3, m);
	map<vector<long>, int>::iterator itr;
	for(itr = m.begin(); itr != m.end();++itr){
		if(isGP(itr->first, r)){
			cnt += 1 + itr->second;
		}
	}
	return cnt;
}

int CountTriplets()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    cout << ans << "\n";

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
