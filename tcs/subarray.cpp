#include <iostream>
using namespace std;

const int N = 1e5+10;

void solve() {

	int n;

	cin >> n;
    
    int arr[n];

    int negative = 0;

    for(int i=0; i<n; i++) {

    	cin >> arr[i];
    	if(arr[i] < 0) negative++;

    }

    int maxSum = 0;

    for(int i=0; i<n; i++) {

    	int total = 1;

    	if(!(negative & 1)) {

    		total = total*arr[i];

    		maxSum = max(total, maxSum);

    	}

    	if(total < 0) total = 1;

    	total = total*arr[i];

    	maxSum = max(total, maxSum);


    }


    
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