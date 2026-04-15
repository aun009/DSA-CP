#include<bits/stdc++.h>
using namespace std;

void solve() {

	int n = 7;
	vector<int> v(7); for(int &i : v) cin >> i;

	sort(v.begin(), v.end());

	int sum = 0;

	for(int i=0; i<n; i++) {
		if(i == n-1) sum += v[i]; else sum -= v[i];
	}

	cout << sum << endl;
}

int main() {

	int t;
	cin >> t;

	while(t--) {
		solve();
	}

}