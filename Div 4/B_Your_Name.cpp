#include<bits/stdc++.h>
using namespace std;

string solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    map<char, int> mp1;

    for(int i=0; i<s.length(); i++) {
        mp1[s[i]]++;
        mp1[t[i]]--;
    }

    for (auto it : mp1) {
        if (it.second != 0) {
            return "NO";
        }
    }

    return "YES";

}

int main() {
  int t;
  cin >> t;
  while(t--) {
    cout << solve() << endl;
  }
  return 0;
}