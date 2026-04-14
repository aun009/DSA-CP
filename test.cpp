#include <bits/stdc++.h>
using namespace std;

// void solve() {
//     int n;
//     cin >> n;
//     cout << n;
    
// }

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    int n;
    cin >> n;
    double dist = 0;
    if(n >= 0 && n <= 1000) dist = 0.05;
    else if(n >= 1001 && n <= 5000) dist = 0.10;
    else if(n < 0) {
        cout << "Error" << endl;
        return 0;
    }
    else dist = 0.15;

    double final_price = n - (dist * n);

    cout << fixed << setprecision(2) << final_price << endl;

    return 0;
}