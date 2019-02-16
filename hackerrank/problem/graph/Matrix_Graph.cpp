/*
 * Matrix_Graph.cpp
 *
 *  Created on: 26-Oct-2018
 *      Author: dubeyalo
 */

#include <bits/stdc++.h>

#if 0

using namespace std;

vector<string> split_string(string);

// Complete the minTime function below.

void print(vector<vector<int> > &mat){
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat.size();++j){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

int bfs(vector<vector<int>> &roads, int src, int dest, int N, int &x, int &y)
{
	//print(roads);
	queue<pair<int,int>> q;
	q.push(make_pair(src, INT_MAX));
	bool visited[roads.size()];
	visited[src]= true;
	while(!q.empty()){
		pair<int, int> curr = q.front();
		q.pop();
		if(curr.first == dest)
			return curr.second;
		for(int i=0;i<N; ++i){
			if((!visited[i])&& (roads[curr.first][i]!=INT_MAX)){
				visited[i]=true;
				pair<int, int> n;
				n.second = min(roads[curr.first][i], curr.second);
				if(roads[curr.first][i] == n.second){
					x = curr.first;
					y = i;
				}
				n.first = i;
				q.push(n);
			}
		}
	}
	return 0;
}

int minTime(vector<vector<int>> roads, vector<int> machines, int N, int E) {
	vector<vector<int> > mat(N,vector<int>(N));
	for(int i=0;i <N;++i)
		for(int j=0;j<N;j++)
			mat[i][j] = INT_MAX;
	for(int i=0;i<=E;i++)
		mat[roads[i][0]][roads[i][1]] = roads[i][2];
	int min = 0,x,y;

	for(int i=0;i<E;i++){
		for(int j=i+1;j<=E;j++){
			int ret= bfs(mat,machines[i],machines[j], N, x,y);
			if(ret!= INT_MAX){
				min += ret;
				mat[x][y]=INT_MAX;
				mat[y][x]=INT_MAX;
			}
		}
	}

	return min;
}

int Matrix_Graph()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> roads(n - 1);
    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> roads[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> machines(k);

    for (int i = 0; i < k; i++) {
        int machines_item;
        cin >> machines_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        machines[i] = machines_item;
    }

    int result = minTime(roads, machines, n, k);

    cout << result << "\n";

    //fout.close();

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
