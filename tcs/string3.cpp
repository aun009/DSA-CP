#include <bits/stdc++.h>
using namespace std;

// void solve() {
    
    
    
// }

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }


    // to print first non repeating char

    string str;
    cin >>str;

    int freq[26] = {0};

    string process;

    for(auto ch : str) {
    	char low = char(ch | ' ');
    	// process.push_back(low);

    	int index = low - 'a';

    	freq[index]++;

    }

    bool found = false;


    for(int i=0; i<str.length(); i++) {

    	char low = char(str[i] | ' ');
    	int index = low - 'a';

    	if(freq[index] == 1) {
    		cout << str[i] << endl;
    		found = true;
    		break;
    	}



    }

    if(!found) cout << -1 << endl;
    




    return 0;
}