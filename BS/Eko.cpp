#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e6+10;


int n;
ll m;
ll trees[N];

bool isWoodSufficient(int h) {
    ll wood = 0;
    for(int i=0; i<n; i++) {
        if(trees[i] >= h) {
            wood += (trees[i] - h);
        }
    }

    return wood >= m;
}


int main() {
  
    cin >>n>> m;
    for(int i=0; i < n; i++) cin >> trees[i];

    ll low =0, high = 1e9, mid;

    //  so the output will be like , T T T T T F F --> so we just need to find that first T there 

    while(high - low > 1) {
        mid = (high + low) /2;

        if(isWoodSufficient(mid)) {
            low = mid; // cause the answer can be the current True also there 
        }
        else {
            high = mid - 1; // cause we dont need to consider the False there 
        }
    } 

    if(isWoodSufficient(high)) {
        cout << high << endl;
    } else {
        cout << low <<endl;
    }

    

  
  return 0;
}