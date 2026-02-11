#include<bits/stdc++.h>
using namespace std;


// void solve() {
//     int x, y, k;
//     cin >> x >> y >> k;

//     if(x > y) cout << (x+k-1) / k + max((x+k-1) /k-1, (y+k-1) / k) << endl; 
//     else cout << (y+k-1) / k + max((y+k-1) /k, (x+k-1) / k) << endl;
// }


void solve() {
  int x, y, k;
  cin >> x >> y >> k;
  
  int move_x = (((x+k -1) / k) * 2) -1;
  int move_y = (((y+k-1)/k) * 2 );
  cout << max(move_x, move_y) << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}