#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];

int vis[N];
int level[N];

void bfs(int source) {

	queue<int> q;
	q.push(source);
	vis[source] = 1;

	while(!q.empty()) {

		int curr_vertex = q.front();
		q.pop();

		for(auto child : g[source]) {
			if(!vis[child]) {

				q.push(child);
				vis[child] = 1;
				level[child] = level[curr_vertex] + 1;
			}
		}

	}


	cout << endl;


}



int main() {

// graph input
	int n;
	cin >> n;
	for(int i=0; i<n-1; i++) {

		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);

	}

	bfs(1);

	for(int i=1; i<=n; i++) {

		cout << i <<  " " << level[i] << endl;

	}



}