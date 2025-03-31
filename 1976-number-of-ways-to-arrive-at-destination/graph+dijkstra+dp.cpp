#define ll long long
#define pli pair<ll, int>
#define fi first
#define se second
class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<pli>> adj;
    vector<int> vis;

    int dijkstra(int u, int n){
        vector<ll> d(n, 1e18);
        vector<ll> dp(n, 0);
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({0, u});
        d[u] = 0;
        dp[0] = 1;
        while(!pq.empty()){
            pli cur = pq.top(); pq.pop();
            if(vis[cur.se]) continue;
            vis[cur.se] = 1;
            for(auto it : adj[cur.se]){
                int v = it.fi;
                int w = it.se;
                if(d[cur.se] + w < d[v]){
                    d[v] = d[cur.se] + w;
                    dp[v] = dp[cur.se];
                    pq.push({d[v], v});
                }
                else if(d[cur.se] + w == d[v])
                    dp[v] = (dp[v] + dp[cur.se]) % mod;
            }
        }
        return dp[n-1];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        adj.resize(n);
        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vis.resize(n, 0);
        return dijkstra(0, n);
    }
};