#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

class Solution {
public:
    ll dijkstra(int s, int n, vector<vector<pii>> &g) {
        vector<int> vis(n + 1);
        vector<ll> d(n + 1, LLONG_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({d[s], s});
        d[s] = 0;
        while (!pq.empty()) {
            auto [dist, u] = pq.top(); pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto [v, w] : g[u]) {
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    pq.push({d[v], v});
                }
            }
        }
        return d[n-1];
    }

    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pii>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].emplace_back(edges[i][1], edges[i][2]);
            adj[edges[i][1]].emplace_back(edges[i][0], edges[i][2] * 2);
        }
        ll ans = dijkstra(0, n, adj);
        return ans == LLONG_MAX ? -1 : ans;
    }
};