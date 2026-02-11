#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);

}

// log n time complexity

int main() {

    cout <<gcd(4, 12) << endl;
    cout <<gcd(14, 12) << endl;

    cout << (4*12)/ gcd(4, 12) << endl;

    cout << __gcd(12, 4) << endl;

    // gcd(gcd(a,b), c)

  return 0;
}