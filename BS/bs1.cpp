#include<bits/stdc++.h>
using namespace std;



int main() {
  
    int arr[5] = {1, 3, 5, 7, 9};

    int st = 0, end = 4;

    int target = 5;

    while(end - st > 1) {
        int mid = st + end / 2;
        if(target < arr[mid]) {
            end = mid  - 1;
        } else {
            st = mid;
        }
    }

    if(arr[st] == target) cout << st << endl;
    if(arr[end] == target) cout << end << endl;

  return 0;
}