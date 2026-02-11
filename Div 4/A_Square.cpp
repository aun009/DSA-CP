#include<bits/stdc++.h>
using namespace std;

string solve() {
    int a, b, c, d;
    cin >> a >> b >> c>> d;

    if((a == b && b == c && c == d)) return "YES";
    else return "NO";
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        cout << solve() << endl;
    }
  
  return 0;
}