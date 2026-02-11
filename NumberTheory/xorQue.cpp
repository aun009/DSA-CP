#include<bits/stdc++.h>
using namespace std;



int main() {

    int arr[5] = {2, 2,6, 4, 4};

    for(auto el : arr) {
        if((el&1)) {
            cout << el << endl;
            break;
        }
    }

    // if we want element in array whose count is odd , use xor -> xor all elements in an array

    int ans = 0;

    for(auto it : arr) {
        ans ^= it;
    } 

    cout << ans << endl;



  
  return 0;
}