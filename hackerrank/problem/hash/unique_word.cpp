/*
 * unique_word.cpp
 *
 *  Created on: 11-Dec-2018
 *      Author: dubeyalo
 */

#include <bits/stdc++.h>

using namespace std;

#if 0

#define ALPHASIZE 26
struct TrieNode{
	TrieNode *charray[ALPHASIZE];
	bool flag;
	TrieNode(){
		flag = false;
		for(int i=0; i<ALPHASIZE; i++)
			charray[i] = nullptr;
	}
};

class Trie{
	TrieNode *head;
public:
	Trie(){ head = new TrieNode();}

	TrieNode *getNode(void){
		TrieNode *pNode = new TrieNode();
		return pNode;
	}

	void insert(string str){
		TrieNode *pCrawl = head;
		for(unsigned int i=0;i<str.length(); ++i){
			int idx;
			if(str[i]>='a' && str[i]<= 'z')
				idx = str[i]-'a';
			if(str[i]>='A' && str[i]<= 'Z')
				idx = str[i]-'A';
			if(pCrawl->charray[idx] == nullptr)
				pCrawl->charray[idx] = getNode();
			pCrawl = pCrawl->charray[idx];
		}
		pCrawl->flag = true;
	}

	bool search(string str) {
		TrieNode *pCrawl = head;
		for(unsigned int i=0;i<str.length(); i++){
			int idx;
			if(str[i]>='a' && str[i]<= 'z')
				idx = str[i]-'a';
			if(str[i]>='A' && str[i]<= 'Z')
				idx = str[i]-'A';
			if(!pCrawl->charray[idx])
				return false;
			pCrawl = pCrawl->charray[idx];
		}
		return ((pCrawl != nullptr)&&(pCrawl->flag));
	}

	bool validate(const char *str){
		if(!search(str)){
			insert(str);
			return true;
		}
		return false;
	}


	void deleteNode(TrieNode *node){
		if(node == NULL)
			return;
		for(int i=0;i<ALPHASIZE; ++i)
			if(node->charray[i])
				deleteNode(node->charray[i]);
		free(node);
	}
	~Trie(){
		deleteNode(head);
	}
};

int unique_word(){
	FILE *fp = fopen("/home/dubeyalo/workspace/Hacker/inputs.txt", "r");
	FILE *fp1 = fopen("/home/dubeyalo/workspace/Hacker/output.txt", "w+");
	char buff[1000];
	Trie *trie = new Trie();
	if(fp == NULL){
		printf("Invalid file");
		return -1;
	}
	while(!feof(fp)){
		fscanf(fp, "%s", buff);
		if(trie->validate(buff))
			fprintf(fp1, "%s ", buff);
	}
	printf("\n\nReading completed\n");
	fclose(fp);
	fclose(fp1);
	delete trie;
	return 0;
}
#endif
