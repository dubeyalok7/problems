/*
 * CrosswordPuzzle.cpp
 *
 *  Created on: 28-Nov-2018
 *      Author: dubeyalok
 */

#include <bits/stdc++.h>
#if 0
using namespace std;

bool isSolve(vector<string> &crossword){
	int N = crossword.size();
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			if (crossword[i][j] == '-')
				return false;
		}
	return true;
}

bool SolveCrossWord(vector<string> &crossword, vector<string> words, bool &visited)
{
	if(isSolve(crossword))
		return true;

	return false;

}

// Complete the crosswordPuzzle function below.
vector<string> crosswordPuzzle(vector<string> crossword, string words) {
	bool visited[10][10] = {false};
	vector<string> word;
	char *tok = strtok(&words[0],";");
	word.push_back(tok);
	while(NULL != tok)
		word.push_back(strtok(NULL,";"));
	bool covered[words.size()]={false};

}

int CrosswordPuzzle()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> result = crosswordPuzzle(crossword, words);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    //fout.close();

    return 0;
}


#endif
