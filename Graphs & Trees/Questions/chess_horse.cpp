#include <bits/stdc++.h>
using namespace std;

int vis[8][8];
int lev[8][8];

int convertX(string s) {
    return s[0] - 'a';
}

int convertY(string s) {
    return s[1] - '1';
}

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}



vector<pair<int, int>> movements = {
    {-1, 2}, {1, 2},
    {-1, -2}, {1, -2},
    {2, 1}, {-2, 1},
    {-2, -1}, {2, -1}
};

int bfs(string source, string destination) {
    int srcX = convertX(source);
    int srcY = convertY(source);
    int destX = convertX(destination);
    int destY = convertY(destination);

    // CRUCIAL: Reset visited and level arrays for every new test case
    memset(vis, 0, sizeof(vis));
    memset(lev, 0, sizeof(lev));

    queue<pair<int, int>> q; // Fixed missing '>'
    q.push({srcX, srcY});
    vis[srcX][srcY] = 1;
    lev[srcX][srcY] = 0;

    while(!q.empty()) {
        pair<int, int> v = q.front();
        int x = v.first, y = v.second;
        q.pop();

        // If we reached the destination, return the number of moves
        if (x == destX && y == destY) {
            return lev[x][y];
        }

        for(auto movement : movements) {
            // Calculate the new landing spot
            int childX = movement.first + x;
            int childY = movement.second + y;

            // Check if the landing spot is on the board AND hasn't been visited yet
            if(isValid(childX, childY) && !vis[childX][childY]) {
                q.push({childX, childY});
                vis[childX][childY] = 1;
                // The new level is the parent's level + 1 move
                lev[childX][childY] = lev[x][y] + 1; 
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t; 
    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        // Used "\n" instead of endl, it's faster for I/O!
        cout << bfs(s1, s2) << "\n"; 
    }

    return 0;
}