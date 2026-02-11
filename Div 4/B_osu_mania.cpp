#include<bits/stdc++.h>
using namespace std;


// void solve() {
//     int n;
//     cin >>n;

//     vector<vector<char>> sign(n, vector<char>(4));

//     for(int i=0; i<n; i++) {  // rows
//         for(int j=0; j<4; j++) { // columns
//             cin >> sign[i][j];
//         }
//     }

//     vector<int> ans;

//     for(int i=n-1; i>=0; i--) {  // rows
//         for(int j=0; j<4; j++) { // columns
//             if(sign[i][j] == '#') {
//                 ans.push_back(j+1);
//             }
//         }
//     }

//     for(auto i : ans) {
//         cout << i << " ";
//     }

//     cout << endl;
    
// }


void solve() {

    int n;
    cin >> n;

    vector<string>a(n);
    for(auto &i : a) cin >> i;

    for(int i=n-1; i>=0; i--) {
        cout << find(a[i].begin(), a[i].end(), '#') - a[i].begin() + 1 << " \n"[i==0];
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