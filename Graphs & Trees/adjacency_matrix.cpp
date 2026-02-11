#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;

int graph[N+1][N+1]; // global variables are always 0 that's why we use this there 

void solve() {
    
    int n, m; // n --> vertices, m --> edges

    cin >> n >> m;

    for(int i=0; i<m; i++) {
    	int v1, v2; 

    	cin >> v1 >> v2;

    	graph[v1][v2] = 1;
    	graph[v2][v1] = 1;
    }


    for(int i=1; i<=n; i++) {
    	for(int j=1; j<=n; j++) {
    		cout << graph[i][j];
    	}

    	cout << '\n';
    }


}

int main() {
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}