#include <iostream>
#include <vector>
using namespace std;

void solve() {
    
    int k,n;
    cin >> k >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++) cin >> arr[i];

    int maxLength = 0;

    for(int i=0; i<n; i++) {

        int sum = 0;

        for(int j=i; j<n; j++) {

            sum += arr[j];

            if(sum <= k) {

                maxLength = max(maxLength, j-i+1);

            }

            else if(sum > k) break;

        }

    }

    cout << maxLength << endl;
    
    
}

void solve1() {

    int k,n;
    cin >> k >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++) cin >> arr[i];


    int maxLen = 0;
    int sum = 0;
    int i = 0;
    int j=0;
    while(j < n) {

        sum += arr[j];
        j++;

        if(sum > k) {

            sum -= arr[i];
            i++;

        } 

        maxLen = max(maxLen, j- i+1);

    }

    cout << maxLen << endl;

}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}