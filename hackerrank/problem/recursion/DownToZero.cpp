/*
 * DownToZero.cpp
 *
 *  Created on: 03-Jan-2019
 *      Author: dubeyalo
 */


#include <bits/stdc++.h>

using namespace std;

vector<int> getDivisors(int n)
{
	vector<int> q;
    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
        	q.push_back(i);
        	q.push_back(n/i);
        }
    }
    return q;
}

int check(int n, vector<int> q, int i,int idx, int *cnt)
{
	if(n==0)
		return 1;
	if(i>=q.size())
		return 0;
	int min=0;
	if((q[i]!= q[idx])&&(q[i]*q[idx]==n)){
		min = check(max(q[i],q[idx]),cnt);
		if(*cnt>min)
			*cnt = min;
	}

	return cnt;
}

/*
 * Complete the downToZero function below.
 */
int downToZero(int n) {
	vector<int> q;
	int cnt=0;
	check(n, q, 0, 0, &cnt);
	return cnt;
}

int DownToZero()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = downToZero(n);

        cout << result << "\n";
    }

    //fout.close();

    return 0;
}


