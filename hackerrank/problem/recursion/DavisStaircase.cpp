/*
 * DavisStaircase.cpp
 *
 *  Created on: 28-Nov-2018
 *      Author: dubeyalo
 */


#include <bits/stdc++.h>

using namespace std;

#if 0

// Complete the stepPerms function below.
int stepPath(int n, int *buff) {
	if(n<=0)
		return 0;
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	if(n==3)
		return 4;
	if(n<1000){
		if(!buff[n]){
			buff[n] = stepPath(n-1, buff) + stepPath(n-2, buff) + stepPath(n-3,buff);
			return buff[n];
		} else
			return buff[n];

	}
	return stepPath(n-1, buff) + stepPath(n-2, buff) + stepPath(n-3,buff);
}

int stepPerms(int n) {
	int buff[1000]={0,};
	return stepPath(n, buff);
}

int DavisStaircase()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        cout << res << "\n";
    }

    //fout.close();

    return 0;
}

#endif

