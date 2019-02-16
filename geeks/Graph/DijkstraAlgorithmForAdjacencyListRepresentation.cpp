/*
 * DijkstraAlgorithmForAdjacencyListRepresentation.cpp
 *
 *  Created on: 27-Dec-2018
 *      Author: dubeyalo
 */
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct AdjListNode{
	int dest;
	int wt;
	AdjListNode *next;
};

struct AdjList{
	AdjListNode *head;
};

struct Graph{
	int V;
	AdjList *arr;
};

Graph *createGraph(int V)
{
	Graph *g = new Graph;
	g->V = V;
	g->arr = new AdjList[V];
	for(int i=0;i<V;i++)
		g->arr[i].head = NULL;
	return g;
}

AdjListNode *newNode(int dest, int wt)
{
	AdjListNode *n = new AdjListNode;
	n->dest = dest;
	n->wt = wt;
	n->next = nullptr;
	return n;
}

void addEdge(Graph *g, int src, int dest, int wt)
{
	AdjListNode *n = newNode(dest, wt);
	n->next = g->arr[src].head;
	g->arr[src].head = n;

	n = newNode(src,wt);
	n->next = g->arr[src].head;
	g->arr[dest].head = n;
}

struct MinHeapNode{
	int v, dist;
};

struct MinHeap
{
	int size, capacity;
	int *pos;
	MinHeapNode **array;
};

MinHeapNode *newMinHeapNode(int v, int dist)
{
	MinHeapNode *n = new MinHeapNode;
	n->v = v;
	n->dist = dist;
	return n;
}

MinHeap *createMinHeap(int capacity)
{
	MinHeap *mh = new MinHeap;
	mh->pos = new int[capacity];
	mh->size = 0;
	mh->capacity = capacity;
	mh->array = (MinHeapNode **) malloc(capacity * (sizeof(struct MinHeapNode *)));
	return mh;
}

void swapMinHeapNode(MinHeapNode **a, MinHeapNode **b)
{
	MinHeapNode *t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(MinHeap *mh, int idx)
{
	int smallest = idx;
	int left = idx*2+1;
	int right = idx*2 +2;
	if(left < mh->size && mh->array[left]->dist < mh->array[smallest]->dist)
		smallest = left;
	if(right < mh->size && mh->array[right]->dist < mh->array[smallest]->dist)
		smallest = right;
	if(smallest != idx)
	{
		MinHeapNode *smallestNode = mh->array[idx];
		MinHeapNode *idxNode = mh->array[smallest];

		mh->pos[smallestNode->v] = idx;
		mh->pos[idxNode->v] = smallest;

		swapMinHeapNode(&mh->array[smallest], &mh->array[idx]);
		minHeapify(mh, smallest);
	}
}

int isEmpty(MinHeap *mh){
	return mh->size == 0;
}

MinHeapNode *extractMin(MinHeap *mh)
{
	if(isEmpty(mh))
		return NULL;

	MinHeapNode *root = mh->array[0];
	MinHeapNode *last = mh->array[mh->size-1];
	mh->array[0] = last;

	mh->pos[root->v] = mh->size-1;
	mh->pos[last->v] = 0;
	--mh->size;
	minHeapify(mh, 0);
	return root;
}

void decreaseKey(MinHeap *mh, int v, int dist)
{
	int i = mh->pos[v];
	mh->array[i]->dist = dist;

	while(i  && mh->array[i]->dist < mh->array[(i-1)/2]->dist)
	{
		mh->pos[mh->array[i]->v] = (i-1)/2;
		mh->pos[mh->array[(i-1)/2]->v] = i;
		swapMinHeapNode(&mh->array[i], &mh->array[(i-1)/2]);
		i = (i-1)/2;
	}
}

bool isInMinHeap(MinHeap *mh, int v)
{
	return (mh->pos[v]< mh->size);
}

void printArr(int dist[], int n)
{
	printf("Vertex Distance from src\n");
	for(int i=0;i<n;i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(Graph *g, int src)
{
	int V = g->V;
	int dist[V];
	MinHeap *mh = createMinHeap(V);

	for(int v=0; v<V; ++v)
	{
		dist[v]= INT_MAX;
		mh->array[v] = newMinHeapNode(v, dist[v]);
		mh->pos[v] = v;
	}

	mh->array[src] = newMinHeapNode(src, dist[src]);
	mh->pos[src] = src;
	dist[src] = 0;
	decreaseKey(mh, src, dist[src]);

	mh->size = V;
	while(!isEmpty(mh))
	{
		MinHeapNode *mhn = extractMin(mh);
		int u = mhn->v;
		AdjListNode *pCrawl = g->arr[u].head;
		while(pCrawl != NULL)
		{
			int v= pCrawl->dest;
			if(isInMinHeap(mh, v) && dist[u]!= INT_MAX && pCrawl->wt + dist[u]< dist[v])
			{
				dist[v] = dist[u] + pCrawl->wt;
				decreaseKey(mh, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
	}

	//print the calculated shortest
	printArr(dist, V);
}
// Driver program to test above functions
int DijkstraAlgorithmForAdjacencyListRepresentation()
{
    // create the graph given in above fugure
    int V = 9;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    dijkstra(graph, 0);

    return 0;
}
#endif
