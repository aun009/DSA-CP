#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
int vis[N];

bool dfs(int vertex, int parent) {

    vis[vertex] = true;

    for(int child : g[vertex]) {
        if(child == parent) continue;
        if(vis[child]) return true;

        if(dfs(child, vertex)) return true;
    }

    return false;
}


void solve() {
    // cycle detection 
    int vertex, edges;
    cin >> vertex >> edges;

    for(int i=0; i<edges; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    bool isLoopExist = false;

    for(int i=1; i<=vertex; i++) {

        if(vis[i]) continue;
        if(dfs(i, -1)) {
            isLoopExist = true;
            break;
        }

    }

    cout << isLoopExist << endl;

}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}