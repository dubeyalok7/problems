/*
 * MaximumDifferenceBetweenNodeAndItsAncestor.cpp
 *
 *  Created on: 18-Jun-2018
 *      Author: dubeyalo
 */

#include <bits/stdc++.h>
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
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
int maxDiff(Node *root);
int MaximumDifferenceBetweenNodeAndItsAncestor()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
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
        m[n2]  = child;
         }
   cout<<maxDiff(root)<<endl;
 }
  return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/* Your are required to
complete this method*/

void InOrder(Node *root)
{
	if(!root)
		return;
	InOrder(root->left);
	cout << root->data << " ";
	InOrder(root->right);
}
void preOrder(Node *root)
{
	if (!root)
		return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

int Max(int a, int b)
{
	return a > b ? a : b;
}

int maxDiff(Node* root)
{
    queue<Node *> q;
    q.push(root);
    int max = 0;
    while(!q.empty())
    {
    	int cnt = q.size(), diff = 0;
    	while (cnt--)
		{
			Node *node = q.front();
			q.pop();
			if ((node->left) && (!node->right))
				diff = node->data - node->left->data;
			if ((node->right) && (!node->left))
				diff = node->data - node->right->data;
			if (node->left && node->right)
				diff = Max((node->data - node->left->data),
						(node->data - node->right->data));
			if (max < diff)
				max = diff;

			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push((node->right));
		}
    }
    return max;
}
#endif


