#include<bits/stdc++.h>
using namespace std;


const int N = 1e5+10;
int n, cows; 
int positions[N];


bool canPlaceCows(int midDist) {  // 

  int cow_cnt = cows;
  int lastposition = -1;

  for(int i=0; i<n; i++) {
    if(positions[i] - lastposition >= midDist || lastposition == -1) {  // here this loop , checks based on the dist it checks all possible solns there 
      cow_cnt--;
      lastposition = positions[i];
    }
    if(cow_cnt == 0) break;

  }

  return cow_cnt == 0;

}


int main() {

  int t;
  cin >> t;
  while(t--) {

       cin >> n >> cows; 

    for(int i=0; i<n; i++) {
      cin >> positions[i];
    }

    sort(positions, positions+n);

    int st = 0, end = 1e9, mid;

    while(end - st > 1) {

      mid = (st + end) /2;

      if(canPlaceCows(mid)) {
        st = mid;

      } else {
        end = mid -1;
      }
    }


    if(canPlaceCows(st)) cout << st << endl;
    else cout << end << endl;



  }


  return 0;
}