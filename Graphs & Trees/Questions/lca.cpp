#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];

int par[N];

// getting back from that node will be easy 
void dfs(int vertex, int parent=-1) {

	par[vertex] = parent;

	for(int child : g[vertex]) {
		if(child  ==  parent) continue;
		dfs(child, vertex);

		//par[child] = vertex;
	}

}

vector<int> path(int vertex) {

	vector<int> ans(N);

	while(vertex != -1) {

		ans.push_back(vertex);
		vertex = par[vertex];
	}

	reverse(ans.begin(), ans.end());
	return ans;

}

int main() {

	int n;
	cin >> n;

	for(int i=0; i<n-1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	// store all parents 
	dfs(1);

	int x, y;
	cin >> x >> y;

	vector<int> path_x = path(x);
	vector<int> path_y = path(y);

	int mn = min(path_x.size(), path_y.size());
	int lca = -1;

	for(int i=0; i<mn; i++) {
		if(path_x[i] == path_y[i]) {
			lca = path_x[i];
		} else {
			break;
		}
	}

	cout << lca << endl;

}