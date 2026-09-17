class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;
    stack<int> st;
    int cycle = -1;

    void dfs(int u) {
        vis[u] = 1;
        for (int v : adj[u]) {
            if (vis[v] == 1) {
                cycle = v;
                break;
            }
            if (!vis[v]) dfs(v);
        }
        st.push(u);
        vis[u] = 2;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        adj.resize(n);
        vis.resize(n, 0);
        for (int i = 0; i < n; i++) {
            if (edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
        }
        int longest_cycle = -1;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            cycle = -1;
            dfs(i);
            if (cycle != -1) { 
                while (!st.empty() && st.top() != cycle) st.pop();
                longest_cycle = max(longest_cycle, (int)st.size());
            }
            while (!st.empty()) st.pop();
        }
        return longest_cycle;
    }
};