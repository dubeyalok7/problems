/*
 * max_staircase.cpp
 *
 *  Created on: 19-Jul-2018
 *      Author: dubeyalo
 */

#include <bits/stdc++.h>

using namespace std;


#if 0
void validate(string arr[], int N)
{
	vector<int > vec;
	int cnt=0, val=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<arr[i].length();j++){
			if((arr[i][j]=='1')||(arr[i][j]=='2')||(arr[i][j]=='3')){
				val++;
			}
			else{
				val = 0;
				break;
			}
		}
		if(val){
			cnt++;
			vec.push_back(atoi(arr[i].c_str()));
		}
	}
	if(!cnt){
		cout << "-1";
		return;
	}

	sort(vec.begin(), vec.end());
	vector<int>::iterator itr;
	for(itr = vec.begin(); itr != vec.end(); itr++)
		cout << *itr << " ";
	cout << endl;
}
#endif
/*
void validate(int arr[], int N)
{
	vector<int> vec;
	bool flag = true;
	for(int i=0;i<N;i++){
		int tmp = arr[i];
		while(tmp){
			int lb = tmp%10;
			tmp/=10;
			if((lb!=1)||(lb!=2)||(lb!=3))
				break;
		}
		if(!tmp){
			flag = false;
			vec.push_back(arr[i]);
		}
	}
	if(flag){
		cout << -1 << endl;
	}

	sort(vec.begin(), vec.end());
	vector<int>::iterator itr;
	for (itr = vec.begin(); itr != vec.end(); itr++)
		cout << *itr << " ";
	cout << endl;
}

int main()
{
	int T;
	int num;
	cin >> T;
	while(T--){
		cin >> num;
		int arr[num];
		for(int i=0;i<num;i++)
			cin >> arr[i];
		validate(arr, num);
	}
	return 0;
}
*/

