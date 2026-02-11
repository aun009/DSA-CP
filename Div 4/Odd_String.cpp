#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n;

    cin >> n;

    string str;
    cin >>str;

    int freqCount[26] = {0};

    for (char c : str) freqCount[c - 'a']++;

    for(int i=0; i<26; i++) {
        if (freqCount[i] > 2) {         
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

    
}


int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}