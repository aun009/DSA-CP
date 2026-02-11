#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector<int> g[N];

vector<vector<int>> cc;
vector<int> curr_cc;

bool vis[N];

// int cnt = 0;

void dfs(int vertex) {

	vis[vertex] = true;
	curr_cc.push_back(vertex);
	for(int child : g[vertex]) {

		if(vis[child]) continue;
		dfs(child);
	}


}

void solve() {
	
    int n, e;
    cin >> n >> e;

    // take input of array
    for(int i=0; i<e; i++) {
    	int v1, v2;
    	cin >> v1 >> v2;
    	g[v1].push_back(v2);
    	g[v2].push_back(v1);
    }

    int cnt = 0;


    for(int i=1; i<=n; i++) {
    	if(vis[i]) continue;
    	curr_cc.clear();
    	dfs(i);
    	cc.push_back(curr_cc);
    	cnt++;
    }

    cout << cc.size() << endl;
}



int main() {
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}