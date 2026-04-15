#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);

void solve() {
    
    int n;
    cin >> n;

    if(n <= 1) {
        cout << "NO" << endl;
        return;
    }

    bool is_prime = true;

    for(int i=2; i<n; i++) {

        if(n % i == 0) is_prime = false;

    }


    cout << is_prime;
}

void solve1() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << false << endl;
        return;
    }

    if(n == 2) {
        cout << true << endl;
        return;
    }

    bool is_prime = true;

    for(int i=2; i*i <= n; i++) {

        if(n % i == 0) is_prime = false; 
        cout << i << " " << sqrt(n) << " " << is_prime <<endl;
    }

    cout << is_prime;
}


vector<int> primes;

// sieve
void solve3() {

    
    isPrime[0] = isPrime[1] = false;

    for(int i =2; i<N; i++) {
        if(isPrime[i]) {

            primes.push_back(i);
            for(int j= 2*i; j <N; j += i) {
                isPrime[j] = false;
            }
        }
    } // n log log n


    for(int i =2; i<N; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    } 

}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve3();
    int t;
    cin >> t;
    while (t--) {
        // solve3();

        int n;
        cin >> n;
        
        // Now checking if a number is prime takes O(1) time!
        // if (isPrime[n]) {
        //     cout << "YES\n";
        // } else {
        //     cout << "NO\n";
        // }

        cout << primes[n-1];



    }
    return 0;
}