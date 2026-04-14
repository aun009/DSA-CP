#include <bits/stdc++.h>
using namespace std;

void solve() {
    
    int n;
    cin >> n;

    vector<int> arr1(n);
    vector<int> arr2(n);

    int cnt = 1;

    for(int i=0; i<n; i++) {
    	cnt++;

    	if(arr2[0] == arr1[i]) break;
    }

    cout << cnt << endl;

}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}