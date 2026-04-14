#include <bits/stdc++.h>
using namespace std;



int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }

    string line;

    getline(cin, line);

    stringstream ss(line);

    vector<int> arr;

    int num;

    while(ss >> num) {

    	arr.push_back(num);

    }


    int n = arr.size();

    cout << n;

    return 0;
}