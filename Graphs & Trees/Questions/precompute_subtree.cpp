#include <bits/stdc++.h>
using namespace std;

// Shortcuts for common types
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())


const int N = 1e+5;

vector<int> g[N];

int subtree_sum[N]; // now we precomputed everything there
int even_ct[N];




void dfs(int vertex, int parent=0) {

	subtree_sum[vertex] += vertex;

	// for the even question there 

	if(vertex % 2 == 0) even_ct[vertex]++;

	// if there is tree then only try to skip the parent node, dont use the vis array concept
	for(int child : g[vertex]) {
		if(child == parent) continue;

		dfs(child, vertex);
		// here assume left side of the node will come which is 
		// vertex, and we will perform operation on that

		subtree_sum[vertex] += subtree_sum[child];

		even_ct[vertex] += even_ct[child];
	}

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

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
    	cout << subtree_sum[i] << " " << even_ct[i] << endl;
    }

    /*int query;
    cin >> query;

    while(query--) {
    	int v;
    	cin >>v;
    	cout << subtree_sum[v];
    }
*/
    return 0;
}