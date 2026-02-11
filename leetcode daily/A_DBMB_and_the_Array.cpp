#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, s, x; 
    cin >> n >> s >> x;
    vector<int> a(n);
    int total_sum = 0;
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
        total_sum += a[i];
    }

    if(total_sum > s) {
        cout << "NO" << endl;
        return;
    }

    
    if ((s - total_sum) % x == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
  int t;
  cin >>t;
  while(t--) {
    solve();
  }
  return 0;
}