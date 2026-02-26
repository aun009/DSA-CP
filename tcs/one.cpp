#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0; // Always safe to check input
    
    vector<int> entry(n);
    vector<int> leaving(n); // Renamed to avoid 'exit' conflict
    
    for(int i = 0; i < n; i++) cin >> entry[i];
    for(int i = 0; i < n; i++) cin >> leaving[i];

    int max_guests = 0; 
    int current_guests = 0; // Track the running state here
    
    for(int i = 0; i < n; i++) {
        // Add new guests, remove leaving guests
        current_guests += entry[i];
        current_guests -= leaving[i];
        
        // Update the maximum seen so far
        max_guests = max(max_guests, current_guests);
    }

    cout << max_guests << endl;

    return 0;
}