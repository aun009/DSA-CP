#include<bits/stdc++.h>
using namespace std;



// xor of same numbers is always zero
// 101
// 101
// 000

// x ^ x = 0
// x ^ 0 = x
// order dont matter in xor a ^ b^ c == b ^ c ^ a == c ^ a ^ b

int main() {

    int a=5, b = 2;
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;

    cout << a  <<  b;
  
  return 0;
}

