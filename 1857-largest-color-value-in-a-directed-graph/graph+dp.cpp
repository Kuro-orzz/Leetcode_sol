class Solution {
public: 
    string colors;
    vector<vector<int>> adj, dp;
    vector<int> vis;
    int ans = 0;

    bool isCycle(int u) {
        vis[u] = 1;
        for (int v: adj[u]) {
            if (vis[v] == 1) return true;
            if (vis[v] == 0 && isCycle(v)) return true;
        }
        vis[u] = 2;
        return false;
    }

    void dfs(int u) {
        int c = colors[u]-'a';
        vis[u] = 1;
        dp[u][c] = 1;
        for (int v : adj[u]) {
            if (!vis[v]) dfs(v);
            for (int i = 0; i < 26; i++) {
                dp[u][i] = max(dp[u][i], dp[v][i] + (c == i));
            }
        }
        ans = max(ans, *max_element(dp[u].begin(), dp[u].end()));
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        this->colors = colors;
        int n = colors.size();
        adj.resize(n);
        for (size_t i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vis.resize(n);
        for (int i = 0; i < n; i++) {
            if (!vis[i] && isCycle(i)) return -1;
        }
        fill(vis.begin(), vis.end(), 0);
        dp.assign(n, vector<int>(26));
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i);
        }
        return ans;
    }
};