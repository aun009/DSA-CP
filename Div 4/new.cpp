#include<bits/stdc++.h>
using namespace std;



int main() {
  vector<int> a = {1, 2, 4, 6};
  int ans = find(a.begin(), a.end(), 4) - a.begin() + 1;
  cout << ans;
  return 0;
}