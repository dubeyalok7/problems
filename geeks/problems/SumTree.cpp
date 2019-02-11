/*
 * SumTree.cpp
 *
 *  Created on: 14-Feb-2019
 *      Author: napster
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
bool isSumTree(struct Node* node);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
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
     cout << isSumTree(root) << endl;
  }
  return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// Should return true if tree is Sum Tree, else false

bool isLeaf(Node *node)
{
	if(node == NULL)
		return false;
	if((node->left == NULL)&&(node->right==NULL))
		return true;
	return false;
}
bool isSumTree(Node* root)
{
	int ls;
	int rs;

	if((root == NULL)||(isLeaf(root)))
		return true;

	if(isSumTree(root->left)&&isSumTree(root->right))
	{
		if(root->left == NULL)
			ls = 0;
		else if(isLeaf(root->left))
			ls = root->left->data;
		else
			ls = 2*root->left->data;

		if(root->right == NULL)
			rs = 0;
		else if(isLeaf(root->right))
			rs = root->right->data;
		else
			rs = 2*root->right->data;

		return (root->data == ls + rs);
	}
	return false;
}
#endif
