/*
 * verticalTreePrint.cpp
 *
 *  Created on: 13-Jun-2018
 *      Author: dubeyalo
 */

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
/* A binary tree node has data, pointer to left child
 and a pointer to right child */

#if 0

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
void
verticalOrder(Node *root);
/* Helper function that allocates a new node with the
 given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/* Driver program to test size function*/
int verticalTreePrint()
{
	freopen("/home/dubeyalo/workspace/geeks/inputs.txt","r", stdin);
	int t;
	struct Node *child;
	scanf("%d", &t);
	while (t--)
	{
		map<int, Node*> m;
		int n;
		scanf("%d ", &n);
		struct Node *root = NULL;
		while (n--)
		{
			Node *parent;
			char lr;
			int n1, n2;
			scanf("%d %d %c", &n1, &n2, &lr);
			if (m.find(n1) == m.end())
			{
				parent = newNode(n1);
				m[n1] = parent;
				if (root == NULL)
					root = parent;
			}
			else
				parent = m[n1];
			child = newNode(n2);
			if (lr == 'L')
				parent->left = child;
			else
				parent->right = child;
			m[n2] = child;
		}
		verticalOrder(root);
		cout << endl;
	}
	return 0;
}

/*Please note that it's Function problem i.e.
 you need to write your solution in the form of Function(s) only.
 Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
 and a pointer to right child
 struct Node
 {
 int data;
 Node* left;
 Node* right;
 }; */
/* Should print vertical order such that each vertical line
 is separated by $*/


/***********************   Recursion Method   ****************************************/
#if 0
void findMinMax(Node *root, int *min, int *max, int hd)
{
	if(root == NULL)
		return;

	if(hd < *min)  *min = hd;
	if(hd > *max)  *max = hd;
	findMinMax(root->left, min, max, hd -1);
	findMinMax(root->right, min, max, hd+1);
}

void verticalTraversal(Node *root, int vl, int idx)
{
	if(root == NULL)
		return;
	if(vl == idx)
		cout << root->data << " ";
	verticalTraversal(root->left, vl, idx-1);
	verticalTraversal(root->right, vl, idx+1);
}

void verticalOrder(Node *root)
{
	int  min=0, max=0;
	findMinMax(root, &min, &max, 0);
	for(int vl = min; vl <= max; vl++){
		verticalTraversal(root,vl, 0);
		cout << "$";
	}
	cout << endl;
}

queue<pair<Node*, int>> que;
	int hd = 0;
	map < int,vector<int> > m;

	que.push(make_pair(root, hd));
	while(!que.empty())
	{
		pair<Node*, int> tmp = que.front();

	}
#endif

/************************    Queue Method   ****************************************/

void verticalOrder(Node *root)
{
	if(root == NULL)
		return;
	int hd = 0;
	queue<pair<Node *, int> > que;
	map < int,vector<int> > m;

	que.push(make_pair(root, hd));

	while(!que.empty())
	{
		pair<Node *, int> tmp = que.front();
		que.pop();

		hd = tmp.second;
		Node *node = tmp.first;

		m[hd].push_back(node->data);
		if(node->left)
			que.push(make_pair(node->left, hd-1));
		if(node->right)
			que.push(make_pair(node->right, hd+1));
	}
	map<int, vector<int> >::iterator itr;;
	for(itr = m.begin(); itr!= m.end(); itr++){
		for(int i=0; i<itr->second.size(); i++){
			cout << itr->second[i] << " ";
		}
		cout << "$";
	}
}

#endif
