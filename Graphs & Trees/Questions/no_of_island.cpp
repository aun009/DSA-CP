#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<vector<bool>>& vis;

int dfs(int i, j, vector<vector<char>>& grid) {

	int n = grid.size();
	int m = grid[0].size();

	if(i >= n || j >= m || i<0 || j< 0) return;

	vis[i][j] = 1;

	dfs(i+1, j, grid);
	dfs(i-1, j, grid);
	dfs(i, j+1, grid);
	dfs(i , j-1, grid);

	
}

int numIslands(vector<vector<char>>& grid) {
     
     int n = grid.size();
	int m = grid[0].size();

	vis.assign(n, vector<bool> (m, false));

	int cnt = 0;

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(grid[i][j] == '1' && !vis[i][j]) {
				dfs(i, j, grid);
				cnt++;
			}
		}
	}


	return cnt;


}

int main() {
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}