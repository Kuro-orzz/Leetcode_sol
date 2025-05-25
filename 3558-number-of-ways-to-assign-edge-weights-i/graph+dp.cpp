class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> adj;
    vector<int> lv, dp;

    void dfs(int u, int par = 0) {
        lv[u] = lv[par] + 1;
        for (int v : adj[u]) {
            if (v == par) continue;
            if (u == 1) dp[v] = 1;
            else {
                dp[v] = dp[u] * 2 % mod;
            }
            dfs(v, u);
        }
    }
    
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        adj.resize(n+1);
        for (int i = 0; i < (int)edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dp.resize(n + 1);
        lv.resize(n+1);
        dfs(1);
        int node_mx = 1;
        for (int i = 2; i <= n; i++) {
            if (lv[node_mx] < lv[i]) {
                node_mx = i;
            }
        }
        return dp[node_mx];
    }
};