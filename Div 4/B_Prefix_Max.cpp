#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int val = *max_element(arr.begin(), arr.end());

    cout << n * val << endl;
}


int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}