#include<bits/stdc++.h>
using namespace std;

#define ll long long


bool isPrime(int n) {

	if (n < 2) return false;

	for(int i=2; i*i<=n; i++) {
		if(n%i == 0) return false;
	}

	return true;

}



int main() {
	
	string s;
	cin >> s;

	int ans = 0;

	for(int i=0; i<s.length(); i++) {

	
	int weight = s[i] - 'a' + 1;
	if(i % 2 != 0) ans += weight * 3;
	else ans += weight * 2;

	}

	if(isPrime(ans)) cout << "Prime" << endl;
	else cout << ans << endl;

	return 0;
}