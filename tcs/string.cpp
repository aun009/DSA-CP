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


    cout << abs(int('A') - int('a')) << endl;

    cout << char('A' + 32) << endl;

    cout << char('a' - 32) << endl;

    char ch = 'A';

    ch = ch ^ 32;

    cout<< ch << '\n';

    // ch is now lowercase

    ch = ch & '_';

    cout <<ch << endl;


    // now ch is in the uppercase

    ch = ch | ' ';

    cout << ch <<endl;



    string str;
    cin >> str;

    for(auto ch : str) {

    	cout << char(ch & '_');

    }

    cout << endl;

    for(auto ch : str) {

    	cout << char(ch | ' ');

    }






    return 0;
}