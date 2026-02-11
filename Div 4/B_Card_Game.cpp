#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    int ans = 0;

    // Game 1
    if ((a1 > b1) + (a2 > b2) > (a1 < b1) + (a2 < b2)) ans++;

    // Game 2
    if ((a1 > b2) + (a2 > b1) > (a1 < b2) + (a2 < b1)) ans++;

    // Game 3
    if ((a2 > b1) + (a1 > b2) > (a2 < b1) + (a1 < b2)) ans++;

    // Game 4
    if ((a2 > b2) + (a1 > b1) > (a2 < b2) + (a1 < b1)) ans++;

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