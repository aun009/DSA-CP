#include<bits/stdc++.h>
using namespace std;

void printBinary(int n) {
    for(int i=10; i>=0; i--) {
        cout << ((n>>i) & 1);
    }

    cout << endl;
}

int main() {
//   printBinary(8);

  int a = 7;
  // find the bit is set bit or not
//   if(((n>>3)& 1) != 0) cout << "set" << endl;
//   else cout << "unset\n"; 

    printBinary(a);

    cout <<"ok"<<'\n';
    
    int i=3;
    cout <<"ok"<<'\n';
    
    cout << "setting bit at specific index to 1 "<< endl;
    
    printBinary(a | (1<<i)); // set bit 
    
    cout <<"ok"<<'\n';

    printBinary(a & (~(1<<i))); // unset bit 

    // printBinary(~a);

    // toggle bit , make 0 to 1 and 1 to 0 , we use ^ 
    
    printBinary(5 ^ (1 << 1));

    // count number of set bits

    int cnt = 0;
    for(int i=31; i>=0; i--) {
      if((a & (1<<i) ) != 0) {
        cnt++;
      }
    }

    cout << cnt << endl;

    cout << __builtin_popcount(a) << endl;
    cout << __builtin_popcountll((1ll<<35)-1);

  return 0;
}