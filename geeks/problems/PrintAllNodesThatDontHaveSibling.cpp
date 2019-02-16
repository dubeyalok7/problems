/*
 * PrintAllNodesThatDontHaveSibling.cpp
 *
 *  Created on: 14-Jun-2018
 *      Author: dubeyalo
 */

//Initial Template for C++
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
void printSibling(Node *);
/* Driver program to test size function*/
int PrintAllNodesThatDontHaveSibling()
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
   printSibling(root);
   cout<<endl;
  }
  return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C++
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/* Prints the nodes having no siblings.  */
#include <algorithm>

void printSibling(Node* node)
{
	queue<Node *> que;
	que.push(node);
	vector<int> v;
	if(node == NULL) return ;

	while(!que.empty())
	{
		int cnt = que.size();
		while (cnt--)
		{
			Node *tmp = que.front();
			que.pop();
			if (!tmp->left && tmp->right)
				v.push_back(tmp->right->data);
			if (tmp->left && !tmp->right)
				v.push_back(tmp->left->data);
			if(tmp->left) que.push(tmp->left);
			if(tmp->right) que.push(tmp->right);
		}
	}
	if (v.size())
	{
		sort(v.begin(), v.end());
		vector<int>::iterator itr;
		for (itr = v.begin(); itr != v.end(); itr++)
		{
			cout << *itr << " ";
		}
	}
	else {
		cout << "-1 ";
	}
}

#endif
