#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;
int n, f;
double rad[N];  // Use double for precision
const double PI = 3.141592653589793;

// Check if we can give (f+1) people pieces of volume 'vol'
bool canGivePiece(double vol) {
    
    int totalPieces = 0;  // Count how many pieces we can make
    
    // For each pie, calculate how many pieces of size 'vol' we can cut
    for(int i = 0; i < n; i++) {
        double pieVolume = PI * rad[i] * rad[i];  // Volume = π*r²*h, h=1
        int piecesFromThisPie = (int)(pieVolume / vol);  // How many pieces?
        totalPieces += piecesFromThisPie;
    }
    
    // We need (f+1) pieces total (f friends + you)
    return totalPieces >= (f + 1);
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        cin >> n >> f;
        
        for(int i = 0; i < n; i++) {
            cin >> rad[i];
        }
        
        // Binary search bounds
        double low = 0.0;
        double high = 0.0;
        
        // Find the maximum possible volume (largest pie)
        for(int i = 0; i < n; i++) {
            double pieVol = PI * rad[i] * rad[i];
            high = max(high, pieVol);
        }
        
        // Binary search on the answer (volume)
        double eps = 1e-6;  // Precision
        
        // Run for fixed iterations (100 is safe for precision 10^-5)
        for(int iter = 0; iter < 100; iter++) {
            double mid = (low + high) / 2.0;
            
            if(canGivePiece(mid)) {
                // We CAN give everyone piece of size 'mid'
                // Try for LARGER piece
                low = mid;
            } else {
                // We CANNOT give everyone piece of size 'mid'
                // Try SMALLER piece
                high = mid;
            }
        }
        
        // Output with precision
        cout << fixed << setprecision(4) << low << endl;
    }
    
    return 0;
}