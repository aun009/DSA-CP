#include <bits/stdc++.h>
using namespace std;

long long sides[4];
long long best;

void dfs(int i, long long r, long long g, long long b, long long cost, int mix) {
    if (cost >= best) return;

    if (i == 4) {
        long long res = cost;
        if (mix == 1) {
            if (r > 0) res++;
            if (g > 0) res++;
            if (b > 0) res++;
        } else if (mix > 1) {
            res += mix * 2;
        }
        best = min(best, res);
        return;
    }

    if (r >= sides[i]) dfs(i + 1, r - sides[i], g, b, cost + 1, mix);
    if (g >= sides[i]) dfs(i + 1, r, g - sides[i], b, cost + 1, mix);
    if (b >= sides[i]) dfs(i + 1, r, g, b - sides[i], cost + 1, mix);

    dfs(i + 1, r, g, b, cost, mix + 1);
}

void solve() {
    long long L, W, R, G, B;
    cin >> L >> W >> R >> G >> B;

    sides[0] = L;
    sides[1] = L;
    sides[2] = W;
    sides[3] = W;

    best = 20;
    dfs(0, R, G, B, 0, 0);

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
