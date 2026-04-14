#include <iostream>
using namespace std;

void solve() {
    
    string str;
    cin >>str;

   

    for(int i=0; i<str.length(); i++) {
    	int cnt =1; // count the current char

    	while(i+1 < str.length() && str[i] == str[i+1]) {

            cnt++;
            i++;

        }

        cout << str[i] << cnt;

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