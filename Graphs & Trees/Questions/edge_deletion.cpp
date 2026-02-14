const int M = 1e9 + 7;

void dfs(int vertex, int parent, vector<vector<int>> &g, vector<int> &A, vector<long long> &subtreeSum) {
    
    subtreeSum[vertex] = A[vertex - 1]; // this because of 1 based indexing 

    for (int child : g[vertex]) {
        if (child == parent) continue;

        dfs(child, vertex, g, A, subtreeSum);
        subtreeSum[vertex] += subtreeSum[child];
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int>> &B) {

    int n = A.size();

    vector<vector<int>> g(n + 1);
    vector<long long> subtreeSum(n + 1, 0);

    for (auto &edge : B) {
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }

    dfs(1, -1, g, A, subtreeSum);

    long long ans = 0;

    for (int i = 2; i <= n; i++) {
        long long part1 = subtreeSum[i];
        long long part2 = subtreeSum[1] - part1;

        ans = max(ans, part1 * part2);  // ✅ NO MOD HERE
    }

    return ans % M;  // ✅ MOD ONLY AT END
}
