#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;

vector<int> graph2[N];
vector<pair<int, int>> graphWt[N];

void solve() {
    
	int n,m;
	cin >> n >> m;

	for(int i=1; i<=m; ++i) {

		int v1, v2; cin >> v1 >> v2;

		graph2[v1].push_back(v2);
		graph2[v2].push_back(v1);
	}


	for(int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for(int neighbor : graph2[i]) {
            cout << neighbor << " ";
        }
        cout << '\n';
    }

}

// if you want to assign there weights then use there (pair, pair)
// each and every one have there the pro and cons
// it is easy to find there the cycle and weight check is easy



void solve2() {

	int vertex, edge;
	cin >> vertex >> edge;

	for(int i=1; i<=edge; i++) { // because the edge means lines are more there
		int v1, v2, wt;
		cin >> v1 >> v2 >> wt;

		graphWt[v1].push_back({v2, wt});
		graphWt[v2].push_back({v1, wt});
	}


    for(int i = 1; i <= vertex; i++) {
        cout << i << " is connected to:\n";
        for(auto &edge : graphWt[i]) {
            // edge.first is the neighbor, edge.second is the weight
            cout << "  -> " << edge.first << " (weight: " << edge.second << ")\n";
        }
    }


}


int main() {
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}