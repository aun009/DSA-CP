#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector<int> g[N];
int depth[N], height[N];

int dfs(int vertex, int parent=0) {

	// no vis concept here instead of that we can use there, we can share there the parent 
	// it is optimised version 

	for(int child : g[vertex]) {

		if(child == parent) continue; // in place of just the vis array there , we used it to skip the all the connected nodes , but here in this tree concept there , 
		// there we only had the same connection betn the parent and its child thats it , we just skip that and we dont have there the need of vis there 

		depth[child] = depth[vertex] + 1;

		dfs(child, vertex);

		// when all the child ends, when it returns do this operation 

		height[vertex] = max(height[vertex], height[child]+1);
	}

}

int main() {
    

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);


	int n;
	cin >> n;

    for(int i=0; i<n-1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1);

    for(int i=1; i<=n; i++) {
    	cout << depth[i] << " " << height[i] << endl;
    }

    return 0;
}