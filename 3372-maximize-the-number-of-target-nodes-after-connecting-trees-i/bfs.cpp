#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    vector<vector<int>> adj1, adj2;
    vector<int> vis;

    int bfs(int u, int k, vector<vector<int>> &adj) {
        fill(vis.begin(), vis.end(), 0);
        queue<pii> q;
        q.push({u, 0});
        vis[u] = 1;
        int target = 0;
        while (!q.empty()) {
            pii v = q.front(); q.pop();
            if (v.se <= k) target++;
            for (int node : adj[v.fi]) {
                if (!vis[node]) {
                    vis[node] = 1;
                    q.push({node, v.se+1});
                }
            }
        }
        return target;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1, m = edges2.size()+1;
        adj1.resize(n);
        adj2.resize(m);
        for (size_t i = 0; i < edges1.size(); i++) {
            adj1[edges1[i][0]].push_back(edges1[i][1]);
            adj1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for (size_t i = 0; i < edges2.size(); i++) {
            adj2[edges2[i][0]].push_back(edges2[i][1]);
            adj2[edges2[i][1]].push_back(edges2[i][0]);
        }

        vis.resize(max(n, m));
        int bonus = 0;
        for (int i = 0; i < m; i++) {
            bonus = max(bonus, bfs(i, k-1, adj2));
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(bfs(i, k, adj1) + bonus);
        }

        return ans;
    }
};