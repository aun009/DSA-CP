#include <bits/stdc++.h>
using namespace std;

void solve() {
    

}

int n, m;
vector<vector<bool>> vis;

void dfs(int i, int j, vector<vector<char>>& grid) {
    if(i < 0 || j < 0 || i >= n || j >= m) return;
    if(grid[i][j] == '0' || vis[i][j]) return;

    vis[i][j] = true;

    // 4 directions
    dfs(i+1, j, grid);
    dfs(i-1, j, grid);
    dfs(i, j+1, grid);
    dfs(i, j-1, grid);
}

int numIslands(vector<vector<char>>& grid) {
	
	n = grid.size();
    m = grid[0].size();

    vis.assign(n, vector<bool>(m, false));

    int cnt = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == '1' && !vis[i][j]) {
                dfs(i, j, grid);
                cnt++;   // one full island explored
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