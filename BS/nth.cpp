#include<bits/stdc++.h>
using namespace std;

double precision = 1e-6;

double multiply(double mid, int n) {

    double ans = 1;

    for(int i=0; i<n; i++) {
        ans *= mid;
    }

    return ans;
}

int main() {
    
    double n;
    cin >> n;
    double low = 0, high = n, mid;

    while(high - low > precision) {
        mid = low + (high - low)/2;

        if(multiply(mid, n) < n) {
            low = mid;
        }

        else {
            high = mid;
        }

    }

    cout << low << endl;


  return 0;
}