#include<bits/stdc++.h>
using namespace std;

void printBinary(int n) {

    for(int i=31; i>=0; i--) {
      // cout << 'i' << i<< endl;
      cout << ((n>>i) & 1);
    }

    cout << endl;

}

int main() {
  // printBinary(5);

  for(char c ='A'; c <='D'; c++) {  // most significant bit -> after that binary is 1 therefor the small letters 
    cout << c << ' ';
    printBinary(int(c));
  }

  for(char c ='a'; c <='d'; c++) {  // most significant bit -> after that binary is 1 therefor the small letters 
    cout << c << ' ';
    printBinary(int(c));
  }

  // everything is there on the fifth bit if i unset it then it will work well 

  // from A --> a set bit
  // from a --> A unset bit 

  char A = 'A';
  char a = A | (1<<5);

  cout << A << " " << a;
  cout << char (A & ~(1 << 5)) << endl;

  // here this is amazing
  cout << char(1<<5) << endl; // this equals to 35 and 35 is val of space 
  cout << char('R' | ' '); // applicable to the capital letter to the small
  cout << char('r' & '_');
  return 0;
}