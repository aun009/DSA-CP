#include<bits/stdc++.h>
using namespace std;

void solve() {

	vector<int> ans(7);


	for(int i=0; i<7; i++) {

		cin >> ans[i];

	}

	// for(int i=0; i<7; i++) {

	// 	cout << ans[i] << " " << endl;

	// }

	for(int i=0; i<7; i++) {

		ans[i] *= -1;

	}

	// for(int i=0; i<7; i++) {

	// 	cout << ans[i] << " " << endl;

	// }


	sort(ans.begin(), ans.end());

	// for(int i=0; i<7; i++) {

	// 	cout << ans[i] << " " << endl;

	// }

	long long sum = accumulate(ans.begin(), ans.end(), 0);

	// cout << ans[0] << endl;

	sum = sum - (ans[0] * 2);

	cout << sum << endl;

}


int main() {

	int t;
	cin >> t;

	while(t--) {

		solve();
	}

}