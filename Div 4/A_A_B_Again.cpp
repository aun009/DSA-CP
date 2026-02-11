#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >>n;

    int a[2];

    a[0] = n/10;
    a[1] = n % 10;

    cout << a[0] +a[1] << endl;
}

int main() {
  int t;
  cin >>t;
  while(t--) {
    solve();
  }
  return 0;
}