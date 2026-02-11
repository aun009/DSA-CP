#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n, a, b; cin >> n >>a>>b;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) cin >> arr[i];

    int ans = 0;
    bool jacket_on = false;

    for(auto i : arr) {
        if(i < a && !jacket_on) {
            ans++;
            jacket_on = true;
        }

        else if(i > b) jacket_on = false;
    }

    cout << ans << endl;

}


int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}