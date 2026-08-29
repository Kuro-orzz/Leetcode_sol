class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;

    void dfs(int u, int par = -1) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (vis[v] || v == par) continue;
            dfs(v, u);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        adj.resize(n);
        vis.assign(n, 0);
        for (int i = 0; i < invocations.size(); i++) {
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        dfs(k);
        int remove = 1;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            for (int x : adj[i]) {
                if (vis[x]) remove = 0;
            }
        }
        vector<int> ans;
        if (remove) {
            for (int i = 0; i < n; i++) {
                if (vis[i]) continue;
                ans.push_back(i);
            }
        } else {
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};