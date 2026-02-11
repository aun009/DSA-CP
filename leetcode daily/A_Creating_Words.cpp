#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s1, s2; cin >> s1 >> s2;

    // for(int i=0; i<s1.length(); i++) {
    //     cout << s1[0]
    // }

    swap(s1[0], s2[0]);

    cout << s1 << " " << s2 << "\n";

}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}