#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long  n;
    cin >>n;
    vector<long long > arr(n, 0);
    for(long long  i=0; i<n; i++) cin >> arr[i];

    // if all array is even or all is odd then prlong long  the same array
    bool evenFlag = false;
    bool oddFlag = false;

    long long  cnt = 0;

    for(auto i : arr) {
        if(i & 1) {
            cnt++;
            if(cnt == arr.size()) {
                oddFlag = true;
                // cnt = 0; 
            }
        }
    }

    cnt = 0;

    for(auto i : arr) {
        if((i & 1) == 0) {
            cnt++;
            if(cnt == arr.size()) {
                evenFlag = true;
            }
        }
    }

    if(oddFlag  || evenFlag) {
        for(long long  i : arr) {
            cout << i <<" ";
            // return;
        }

        cout<< endl;
    }

    else {
        sort(arr.begin(), arr.end());
        for(long long  i : arr) {
            cout << i <<" ";
        }
        
        cout<< endl;
    }
}

int  main() {
  
    long long  t;
    cin >> t;

    while(t--) {
        solve();
    }

  return 0;
}