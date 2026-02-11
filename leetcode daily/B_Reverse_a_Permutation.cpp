#include <bits/stdc++.h>
using namespace std;

void run_test_case() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> position_of(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        position_of[p[i]] = i;
    }
    int idx_to_fill = 0;

    for (int val = n; val >= 1; val--) {
        int current_pos = position_of[val];

        if (current_pos < idx_to_fill) {
            continue;
        }

        if (current_pos == idx_to_fill) {
            idx_to_fill++;
            continue;
        }

        reverse(p.begin() + idx_to_fill, p.begin() + current_pos + 1);
        
        break;
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        run_test_case();
    }
    return 0;
}