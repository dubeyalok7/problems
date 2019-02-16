/*
 * FindTheNearestClone.cpp
 *
 *  Created on: 20-Aug-2018
 *      Author: dubeyalok
 */
#include <bits/stdc++.h>
#if 0
using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
/************************************************************************************************/

class Graph
{
	vector<int> *adj;
	int N;
public:
	Graph(int _N) :
			N(_N)
	{
		adj = new vector<int> [N];
	}

	void add_edge(int u, int v);
	int bfs(int src, vector<long> &ids);
	~Graph(){
		delete[] adj;
	}
};

void Graph::add_edge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int Graph::bfs(int src, vector<long> &ids)
{
	queue<pair <int, int>> q;
	int dist = 0;
	int visited[N];
	memset(visited, false, sizeof(int) * (N));
	visited[src] = true;
	q.push(make_pair(src, dist));
	while (!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();
		if((curr.first != src)&&(ids[curr.first-1] == ids[src -1]))
			return curr.second;
		for (auto it = adj[curr.first].begin(); it != adj[curr.first].end();
				++it)
		{
			if (!visited[*it])
			{
				dist = curr.second + 1;
				visited[*it] = true;
				q.push(make_pair(*it, dist));
			}
		}
	}
	return -1;
}

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to,
		vector<long> ids, int val)
{
	Graph g(graph_nodes+1);
	for(int i = 0;i<graph_from.size(); i++){
		g.add_edge(graph_from[i], graph_to[i]);
	}

	int sd = g.bfs(val,ids);
	return sd;
}

/************************************************************************************************/
int FindTheNearestClone()
{
	//ofstream fout(getenv("OUTPUT_PATH"));
	freopen("/home/dubeyalo/workspace/Hacker/inputs.txt", "r", stdin);

	int graph_nodes;
	int graph_edges;

	cin >> graph_nodes >> graph_edges;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> graph_from(graph_edges);
	vector<int> graph_to(graph_edges);

	for (int i = 0; i < graph_edges; i++)
	{
		cin >> graph_from[i] >> graph_to[i];
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	string ids_temp_temp;
	getline(cin, ids_temp_temp);

	vector<string> ids_temp = split_string(ids_temp_temp);

	vector<long> ids(graph_nodes);

	for (int i = 0; i < graph_nodes; i++)
	{
		long ids_item = stol(ids_temp[i]);

		ids[i] = ids_item;
	}

	int val;
	cin >> val;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

	cout << ans << "\n";

	//fout.close();

	return 0;
}

vector<string> split_string(string input_string)
{
	string::iterator new_end = unique(input_string.begin(), input_string.end(),
			[] (const char &x, const char &y)
			{
				return x == y and x == ' ';
			});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ')
	{
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos)
	{
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(
			input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}

#endif
