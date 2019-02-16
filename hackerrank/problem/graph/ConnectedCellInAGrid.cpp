/*
 * ConnectedCellInAGrid.cpp
 *
 *  Created on: 25-Oct-2018
 *      Author: dubeyalo
 */

#include <bits/stdc++.h>

using namespace std;
#if 0

const int rNum[8]={-1,-1, 0, 1, 1, 1, 0,-1};
const int cNum[8]={ 0,-1,-1,-1, 0, 1, 1, 1};

bool isSafe(vector<vector<int>> grid, int x, int y, int R, int C)
{
	return ((x>=0)&&(x<R)&&(y>=0)&&(y<C)&&(grid[x][y]));
}
/*
1 0 1 1 0
* 1 0 0 1
0 1 1 1 0
0 0 0 0 1
1 1 1 0 0
*/

void dfs(vector<vector<int>> &grid, bool **visited, int &area, int R , int C, int x, int y)
{
	visited[x][y] = true;
	for(int i=0;i<8;i++){
		int nx = x+ rNum[i];
		int ny = y+ cNum[i];
		if(isSafe(grid, nx, ny, R,C) && (!visited[nx][ny])){
			dfs(grid, visited,(++area),R , C , nx, ny);
		}
	}
}

// Complete the maxRegion function below.
int maxRegion(vector<vector<int>> grid) {
	int R = grid.size();
	int Max = INT_MIN, area=0;
	int C = grid[0].size();
	bool **visited = new bool*[R];
	for(int i=0;i<R;i++)
		visited[i] = new bool[C];

	for(int i =0; i<R;i++)
		for(int j=0;j<C;j++)
			visited[i][j] = false;

	for(int i=0;i< R; i++){
		for (int j = 0; j < C; j++)
		{
			if(grid[i][j]&&(!visited[i][j]))
			{	area=1;
				dfs(grid, visited, area, R, C, i, j);
				if (area > Max)
					Max = area;
				area=0;
			}
		}
	}
	return Max;
}

int ConnectedCellInAGrid()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int> > grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    cout << res << "\n";

    //fout.close();

    return 0;
}

#endif
