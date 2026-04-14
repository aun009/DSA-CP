#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> nums = {4, 1, 2, 2, 3, 4, 4, 1,1, 1, 0};

    // find the max occuring element

    unordered_map<int, int> mp;

    for(auto el : nums) {
        mp[el]++;
    }


    // int max_el = *max_elemet(mp.second.begin())

    int maxFreq = 0;
    int maxFreqEl = nums[0];

    for(auto const& [val, cnt] : mp) {
        if(cnt > maxFreq) {
            maxFreqEl = val;
            maxFreq = cnt;
        }
    }


    cout << maxFreqEl << " " <<maxFreq << endl;
    
    
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--) {
        solve();
    // }

    return 0;
}