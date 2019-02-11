/*
 * Dijkstra.cpp
 *
 *  Created on: 20-Dec-2018
 *      Author: dubeyalo
 */
#include <stdio.h>
#include <limits.h>

#if 0
#define V 9

int minDist(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_idx;
	for(int v =0; v < V; v++){
		if(!sptSet[v] && dist[v]<= min){
			min = dist[v], min_idx = v;
		}
	}
	return min_idx;
}

// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];
	bool sptSet[V];

	for(int i=0;i<V;i++)
		dist[i] = INT_MAX, sptSet[i] = false;
	dist[src] = 0;
	for(int cnt = 0; cnt < V-1; cnt++){
		int u = minDist(dist, sptSet);
		sptSet[u] = true;
		for(int v=0; v< V;v++){
			if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+ graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
		}
	}
	printSolution(dist, V);
}

// driver program to test above function
int Dijkstra()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);

    return 0;
}
#endif

#if 0
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

class Graph{
	int V;
	list<pair<int, int >> *adj;
public:
	Graph(int _V){
		V = _V;
		adj = new list<pair<int, int>>[V];
	}

	void addEdge(int u, int v, int wt){
		adj[u].push_back(make_pair(v, wt));
		adj[v].push_back(make_pair(u, wt));
	}

	void shortestPath(int src);
};

void Graph::shortestPath(int src)
{
	set<pair<int, int>> setds;
	vector<int> dist(V,INF);
	setds.insert(make_pair(0, src));
	dist[src]=0;
	while(!setds.empty()){
		pair<int, int> tmp = *setds.begin();
		setds.erase(setds.begin());
		int u = tmp.second;
		list<pair<int, int>>::iterator it;
		for(it = adj[u].begin();it != adj[u].end(); ++it){
			int v = (*it).first;
			int wt = (*it).second;
			if(dist[v] > dist[u] + wt){
				if(dist[v]!= INF)
					setds.erase(setds.find(make_pair(dist[v], v)));
				dist[v] = dist[u] + wt;
				setds.insert(make_pair(dist[v], v));
			}
		}
	}
	// Print shortest distances stored in dist[]
	    printf("Vertex   Distance from Source\n");
	    for (int i = 0; i < V; ++i)
	        printf("%d \t\t %d\n", i, dist[i]);
}

// Driver program to test methods of graph class
int Dijkstra()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}
#endif
