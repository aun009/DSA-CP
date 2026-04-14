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


    string str;
    cin >> str;

    int freq[26] = {0};

    for(int i=0; i<str.length(); i++) {

    	// do lowercase
    	char low = str[i] | ' ';


    	if(low >= 'a' && low <= 'z') {
    		// find the index now
    		int index = low - 'a';

    		cout << low << " " << index <<endl;


    		freq[index]++;
    	}

    }


    cout << "Character Frequencies:" << endl;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0) {
            // Convert index back to character: index + 'a'
            char actualChar = i + 'a';
            cout << actualChar << " : " << freq[i] << endl;
        }
    }

    

    return 0;
}