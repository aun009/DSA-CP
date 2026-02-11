#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    // store value and original index (0-based)
    vector<pair<int,int>> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) v.push_back({arr[i], i});

    sort(v.begin(), v.end()); // sort by value

    for (int i = 0; i + 1 < n; ++i) {
        int p1 = v[i].second % 2;
        int p2 = v[i+1].second % 2;
        if (p1 == p2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
