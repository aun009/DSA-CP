#include <bits/stdc++.h>
using namespace std;

void solve1() {

	string s;
    if (!(cin >> s)) return ;

    int count = 1;
    for (int i = 0; i < s.length(); i++) {
        // If the next character is the same, just increase the count
        if (i + 1 < s.length() && s[i] == s[i + 1]) {
            count++;
        } else {
            // If it's different (or we reach the end of the string), print and reset
            cout << s[i] << count;
            count = 1;
        }
    }
    cout << endl;

}




int main() {
    
    

    solve1();

    return 0;
}