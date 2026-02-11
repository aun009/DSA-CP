#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

vector<pair<int, int>> graphW[N];

void solve() {
    
    int vertex, edge;
    cin >> vertex >> edge;

    for(int i=1; i<=edge; i++) {

    	int v1, v2, wt;
    	cin >> v1 >> v2 >> wt;

    	graphW[v1].push_back({v2, wt});
    	graphW[v2].push_back({v1, wt});

    }


    //lets print it 
    for(int i=1; i<=vertex; i++) {
    	cout << i << "--> ";
    	for(auto &it : graphW[i]) {
    		cout << it.first << " " << it.second << " ";
    	}

    	cout << endl;
    }

}

int main() {
    

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}