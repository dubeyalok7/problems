/*
 * MiniMaxSum.cpp
 *
 *  Created on: 19-Jun-2018
 *      Author: dubeyalo
 */




#include <bits/stdc++.h>

using namespace std;
#if 0

vector<string> split_string(string);

void minMaxSumUtil(vector<int> &arr,int *buff, unsigned long int *min, unsigned long int *max,int idx, int i, int N)
{
	if(idx==4){
		unsigned long int sum = 0;
		for(int i =0;i<idx;i++)
			sum += buff[i];
		if (*max < sum)
			*max = sum;
		if (*min > sum)
			*min = sum;
		return;
	}

	if(i>=N)
		return;
	buff[idx]=arr[i];
	minMaxSumUtil(arr, buff,min,max,idx+1,i+1,N);
	minMaxSumUtil(arr, buff,min,max,idx,i+1,N);
}

// Complete the miniMaxSum function below.
void miniMaxSum(vector<int> arr) {
	unsigned long int min = ULONG_MAX;
	unsigned long int max = 0;
	int buff[arr.size()];
	minMaxSumUtil(arr,buff, &min, &max,0, 0, arr.size());
	cout << min << " " << max << endl;
}

int MiniMaxSum()
{
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
#endif
