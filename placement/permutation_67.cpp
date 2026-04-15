#include<bits/stdc++.h>
using namespace std;

void solve() {

	int n; cin >>n;

	vector<int> v(3*n+1);

	int cnt= 1;

	for(int i=1; i<=3*n; i += 3) {
		v[i] = cnt++;
	}

	for(int i=2; i<=3*n; i++) {
		if(v[i] == 0) {
			v[i] = cnt++;
		}
	}

	for(int i=1; i<= 3*n; i++) cout << v[i] << " ";

	cout << endl;

}

int main() {

	int t;
	cin >> t;

	while(t--) {
		solve();
	}

}