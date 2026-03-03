#include<bits/stdc++.h>
using namespace std;

#define long long ll


string process(string s1) {

	string res = "";



	for(auto ch : s1) {

		if(ch == '#') {

			if(!res.empty()) {
				res.pop_back();
			}

			else {
				res.push_back(ch);
			}

		}

	}

	return res;

}

int main() {
	
	string s1, s2;
	cin >> s1 >>s2;

	
	string fs = process(s1);
	string fs2 = process(s2);

	if(s1.length() != s2.length()) {

		cout << "NO" << endl;
	}

	
	if(s1.length() == s2.length()) {

		
		if(fs2 == fs) cout << "YES" << endl;
	else cout << "NO" << '\n';

	
	}

	return 0;
}