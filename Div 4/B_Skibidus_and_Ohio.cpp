#include<bits/stdc++.h>
using namespace std;

int solve() {
    string str;
    cin >> str;
    int n = str.length();
    for(int i=1; i<n; i++) {
        if(str[i] == str[i-1] ) {
            return 1;
        }
    }

    return n;
}


int main() {
  int t;
  cin >> t;
  while(t--) {
    cout << solve() <<endl;
  }
  return 0;
}