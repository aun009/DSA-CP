#include<bits/stdc++.h>
using namespace std;

#define long long ll
const int N = 1e5+10;
bool vis[N];

vector<int> g[N];

void dfs(int vertex) {

		cout << vertex << "\n"; // do operation on vertex after entering the vertex

	vis[vertex] = true;

	for(int child : g[vertex]) {

		// do operation on child before entering the dfs

		cout <<  vertex << " " << child  << endl;


		if(vis[child]) continue;

		dfs(child);

		cout << vertex << "--> " << child << endl; // it runs when the node is leaf 


		// do operation on child after exiting the child

	}

	// take action on vertex before exiting the vertex

	cout << vertex << "\n";

}

int main() {

	int n;
	cin >> n;

	for(int i=0; i<n; i++) {
		int v1, v2;
		cin >> v1 >> v2;

		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	dfs(1);


	
	return 0;
}