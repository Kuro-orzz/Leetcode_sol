class Solution {
public:
    vector<int> bfs(int u, int n, vector<int> &g) {
        vector<int> vis(n), d(n, -1);
        queue<int> q;
        q.push(u);
        vis[u] = 1;
        d[u] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            if (g[v] == -1) continue;
            if (!vis[g[v]]) {
                q.push(g[v]);
                vis[g[v]] = 1;
                d[g[v]] = d[v] + 1;
            }
        }
        return d;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> d1 = bfs(node1, n, edges);
        vector<int> d2 = bfs(node2, n, edges);
        int ans = 1e9, pos = -1;
        for (int i = 0; i < n; i++) {
            if (d1[i] == -1 || d2[i] == -1) continue;
            if (max(d1[i], d2[i]) < ans) {;
                ans = max(d1[i], d2[i]);
                pos = i;
            }
        }
        return ans == 1e9 ? -1 : pos;
    }
};