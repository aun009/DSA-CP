#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    
    string s1, s2;
    cin >> s1 >> s2;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if(s1 == s2) {
    	cout << "YES" << endl;
    }

    else cout << "NO" << endl;


    
}


void solve1() {

	string s1, s2;
	cin >> s1 >> s2;

	int freq[26] = {0}; // here logic would be add from 1st string and
	// remove from the second string 

	if(s1.length() != s2.length()) {
		cout << "NO" <<'\n';
		return;
	}

	for(int i=0; i<s1.length(); i++) {

		int index = s1[i] - 'a';
		int index2 = s2[i] - 'a';

		freq[index]++;
		freq[index2]--;

	}

	bool flag = true;

	for(auto el : freq) {

		if(el != 0) flag = false;

	}

	if(flag) cout << "YES" << '\n';
	else cout << "NO" << "\n";


}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve1();
    }

    return 0;
}