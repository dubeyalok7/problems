/*
 * LCA.cpp
 *
 *  Created on: 21-Nov-2018
 *      Author: dubeyalo
 */
#include <bits/stdc++.h>

#if 0
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;
	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

class Solution
{
public:
	Node* insert(Node* root, int data)
	{
		if (root == NULL)
		{
			return new Node(data);
		}
		else
		{
			Node* cur;
			if (data <= root->data)
			{
				cur = insert(root->left, data);
				root->left = cur;
			}
			else
			{
				cur = insert(root->right, data);
				root->right = cur;
			}

			return root;
		}
	}

	/*The tree node has data, left child and right child
	 class Node {
	 int data;
	 Node* left;
	 Node* right;
	 };

	 */
	void search(Node *root, vector<Node *> &vec, int val)
	{
		if (root == NULL){
			return;
		}

		if(root->data < val){
			vec.push_back(root);
			search(root->left, vec, val);
		}
		if(root->data>val){
			vec.push_back(root);
			search(root->right, vec, val);
		}
		if(root->data == val){
			return;
		}
	}

	Node *lca(Node *root, int v1, int v2)
	{
		vector<Node *> vec1, vec2;
		search(root, vec1, v1);
		search(root, vec2, v2);
		for(int i=0;i< min(vec1.size(), vec2.size()); ++i){
			if(vec1[i]->data != vec2[i]->data)
				return vec1[i-1];
			else
				return vec1[i];
		}
		return root;
	}
};
//End of Solution

int LowestCommonAnchester()
{

	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0)
	{
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	int v1, v2;
	std::cin >> v1 >> v2;

	Node *ans = myTree.lca(root, v1, v2);

	std::cout << ans->data;

	return 0;
}

#endif
