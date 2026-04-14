#include <iostream>
using namespace std;

void solve() {
    
    
    
}

int knapsack(int wt[], int val[], int w, int n) {

	if(n == 0 || w == 0) return 0;

	if(wt[n-1] <= w) {

		return max(val[n-1] + knapsack(wt, val, w- wt[n-1], n-1) , 
			knapsack(wt, val, w, n-1));

	}

	if(wt[n-1] > w) {

		return knapsack(wt, val, w, n);

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