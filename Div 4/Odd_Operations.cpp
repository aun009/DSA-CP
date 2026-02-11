#include<bits/stdc++.h>
using namespace std;






#include<bits/stdc++.h>
using namespace std;

bool hasOddDigit(long long num) {
    string s = to_string(num);
    for(char c : s) {
        if((c - '0') % 2 != 0) return true;
    }
    return false;
}

void solve() {
    long long n;
    cin >> n;

    if (n % 2 != 0) {
        cout << 0 << endl;
        return;
    }

    if (hasOddDigit(n)) {
        cout << 1 << endl;
        return;
    }
    if (n < 10) {
        cout << -1 << endl;
        return;
    }

    string s = to_string(n);
    for(char c : s) {
        long long digit = c - '0';
        long long next_val = n - digit;
        
        if (hasOddDigit(next_val)) {
            cout << 2 << endl;
            return;
        }
    }

    cout << 3 << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}