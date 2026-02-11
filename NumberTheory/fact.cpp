#include<bits/stdc++.h>
using namespace std;

int M = 47;

long long fact(long long n) {
    long long ans = 1;
    for(long long i=2; i<=n; i++) {
        // ans *= (i) % M;
        ans = (ans*i) % M;
    }

    return ans;
}

int main() {
//   cout << fact(20);

    // cout << 8%7;
    // cout << 1e9 + 7;

    // cout << (2 << 2) << endl;

    // cout << (1<<1) << endl;

    cout << INT_MAX << endl;

    int a = (1LL<<31)-1; // here first (1<<32) this is 33 bit and after that -1 comes and then it becomes 32, till then make 1 as the long long insted of integer

    cout << a << endl;

    unsigned int b= (1<<32)-1; // only stores +ve , in normal int 1 bit is stored for the whether num is +ve or -ve
    cout << b << endl;
  return 0;
}