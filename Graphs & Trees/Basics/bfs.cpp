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


	//now traverse all the child of the given vertex there 

	while(!q.empty()) {

		int curr_vertex = q.front();
		q.pop();

		for(auto child : g[curr_vertex]) {
			if(!vis[child]) {
				q.push(child);
				vis[child] = 1;
				level[child] = level[curr_vertex] + 1;
			}
		}

	}

	cout << endl;

	// at each time one node is popped out there , so 
	// TC -> V - node, E - Edges there 
	// whiile loop working for the v nodes ,
	// and e is there for the edges , for which the for loop is there running 


}

int main() {

	int n;
	cin >> n;
	for(int i=0; i<n-1; i++) {
		int v1, v2; cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	bfs(1);

	for(int i=1; i<=n; i++) {

		cout << i <<  " " << level[i] << endl;

	}



}
