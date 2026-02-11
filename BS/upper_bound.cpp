#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &v, int el) {
  
  // inside working of the lower bound 
  int st = 0;
  int n = v.size();
  int end = n-1;

  int ans = v.size();

  while(st <= end) {
    int mid = st + (end-st) / 2;
    if(v[mid] >= el) {
      ans = mid;
      end = mid-1;
    }

    else if(v[mid] < el) {
      st = mid +1;
    }

  }

  return ans;

}

int upperBound(vector<int> &v, int el) {
  int st, end, ans; st = 0; end = v.size()-1, ans = v.size();
  ans = v.size();

  while(st <= end) {
    int mid = st + (end - st)/2;

    if(v[mid] > el) {
      ans = mid;
      end = mid -1;
    }

    else {
      st = mid  + 1;
    }
  }

  return ans;
}

int main() {
  
  vector<int> a = {1, 2, 4, 4, 4, 6, 8};
  
  int target = 2;

  // auto lb = upper_bound(a.begin(), a.end(), target);
  // // cout << lb << endl;
  // cout << lb - a.begin();
  cout << lowerBound(a, 4) << "\n";

  cout << upperBound(a, 4);

  return 0;
}