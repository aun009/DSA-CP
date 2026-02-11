#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    cin >> str;

    int n = str.length();

    // for (int i = 0; i < n; i++) {/
        str.erase(n-2, 2);

        str.push_back('i');
    

    cout << str << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
