#include <bits/stdc++.h>
using namespace std;

void solve() {
    

}

void dfs(int i, int j, int initialColor, int newColor ,vector<vector<int>>& image) { // in place of vector we have i, j

	int n = image.size();
	int m = image[0].size();

	// in place of handling all the edge cases one by one there , reject all of them at once
	if(i < 0 || j < 0) return; // here 2 type of invalid cases are already written 
	if(i >= n || j >= m) return;
	if(image[i][j] != initialColor) return;

	image[i][j] = newColor;

	dfs(i-1, j, initialColor, color, image);
	dfs(i+1, j, initialColor, color, image);
	dfs(i, j-1, initialColor, color, image);
	dfs(i, j+1, initialColor, color, image);

}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(initialColor != newColor)
        	dfs(sr, sc, initialColor, color, image);
        return image;
}

int main() {
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}