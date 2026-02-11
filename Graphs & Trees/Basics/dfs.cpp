#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector<int> g[N];
bool vis[N];

void dfs(int vertex) {
    // take action on vertex after entering the vertex

    cout << vertex << "\n";
    // if(vis[vertex]) return;

    vis[vertex] = true;

    for(int child : g[vertex]) { // this will go all deep, for a single child 

        cout << " Parent " << vertex << " child " << child << endl;
        
        // take action on child before enterring the dfs
        if(vis[child]) continue;

 
        dfs(child);
      
        
       
        
        // take action on chiild after exiting child node
    }
    
    // take action on vertex before exiting the vertex 
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<9; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        g[v1].push_back(v2);
        g[v2].push_back(v2);
    }

    dfs(1);
    
}



int main() {
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}