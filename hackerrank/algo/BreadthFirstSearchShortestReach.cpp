/*
 * BreadthFirstSearchShortestReach.cpp
 *
 *  Created on: 20-Jun-2018
 *      Author: dubeyalo
 */




#include <bits/stdc++.h>

using namespace std;
#if 0

vector<string> split_string(string);
/*
int bfsUtil(vector<int> adj[], int n, int s, int e)
{
	bool visited[n]={false};
	queue<pair<int, int> >q;
	q.push(make_pair(s,0));
	visited[s] = true;
	while(!q.empty())
	{
		pair<int,int> tmp = q.front();
		q.pop();
		int node = tmp.first;
		int dist = tmp.second;
		if(node == e)
			return dist;
		vector<int>::iterator itr;
		for(itr = adj[node].begin(); itr != adj[node].end(); ++itr){
			if(!visited[*itr]){
				visited[*itr] = true;
				q.push(make_pair(*itr, dist+6));
			}
		}

	}
	return -1;
}

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
	vector<int> vec;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int u = edges[i][0], v =edges[i][1];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(i!=s)
			vec.push_back(bfsUtil(adj, n, s, i));
	}
	return vec;
}
*/
vector<int>dist;
void bfs(int s,vector<vector<int>>a,vector<bool>visited)
{
    visited[s]=true;
    queue<int>q;
    q.push(s);
    dist[s]=0;
    while(!q.empty())
    {
        s=q.front();
        //cout<<s<<" ";
        q.pop();
        for(int i:a[s])
        {
            if(!visited[i]&&dist[i]==-1)
            {
                dist[i]=dist[s]+1;
                visited[i]=true;
                q.push(i);
            }
        }
    }
}


int BreadthFirstSearchShortestReach()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

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
