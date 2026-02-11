#include<bits/stdc++.h>
using namespace std;

int main() {
    double n;
    cin >> n;

    double st = 0, end = n, mid;
    double eps = 1e-6;  // Precision level, this can be the 0.01

    while(end - st > eps) { // While the gap between start and end is bigger than 0.000001, keep searching
        mid = (st + end) / 2.0;

        if(mid * mid < n) {
            st = mid;  // Don't add 1, use exact mid
        }
        else {
            end = mid;  // Don't subtract 1, use exact mid
        }
    }

    cout  << st << endl;

    cout << pow(n, 1.0/2) << endl;

    return 0;
}