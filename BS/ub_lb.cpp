#include<bits/stdc++.h>
using namespace std;

int lb(vector<int> &arr, int target) {

  int n = arr.size();
  int st = 0;
  int end = n-1;

  int ans = 0;

  while(st <= end) {
    int mid = st + (end - st) / 2;

    // lower bound means , if we got the element then search for its first occuranece there 

    if(arr[mid] >= target) {
      ans = mid;
      end = mid -1;
    }

    else {
      st = mid +1;
    }
  }
  
}



int ub(vector<int> &arr, int target) {
  int n = arr.size();
  int st = 0;
  int end = n-1;

  int ans = 0;

  while(st <= end) {
    int mid = st + (end - st) / 2;
    
    if(arr[mid] > target) {
      ans = mid;
      end = mid - 1;
    }
    else {
      st = mid + 1;
    }
  }

  return ans;
}


int main() {
  
  vector<int> arr = {1, 3, 4, 4, 4, 5};

  cout << lb(arr, 4) << endl;

  cout << ub(arr, 4) << endl;

  return 0;
}

