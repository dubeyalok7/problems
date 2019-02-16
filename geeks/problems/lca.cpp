/*
 * lca.cpp
 *
 *  Created on: 30-Jan-2019
 *      Author: dubeyalo
 */
#if 0
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
 and a pointer to right child */
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
Node * LCA(Node*, int, int);
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
int LCA()
{
	int t;
	struct Node *child;
	scanf("%d", &t);
	while (t--)
	{
		map<int, Node*> m;
		int n;
		scanf("%d", &n);
		struct Node *root = NULL;
		if (n == 1)
		{
			int a;
			cin >> a;
			cout << a << endl;
		}
		else
		{
			while (n--)
			{
				Node *parent;
				char lr;
				int n1, n2;
				scanf("%d %d %c", &n1, &n2, &lr);
				//  cout << n1 << " " << n2 << " " << (char)lr << endl;
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
			int a, b;
			cin >> a >> b;
			Node * k = LCA(root, a, b);
			cout << k->data << endl;
		}
	}
	return 0;
}

Node * findLCA(Node* root ,int n1 ,int n2 )
{
	    if (root == NULL) return NULL;

	    if (root->data == n1 || root->data == n2)
	        return root;

	    Node *left_lca  = findLCA(root->left, n1, n2);
	    Node *right_lca = findLCA(root->right, n1, n2);

	    if (left_lca && right_lca)
	    	return root;

	    return (left_lca != NULL)? left_lca: right_lca;
}

#endif