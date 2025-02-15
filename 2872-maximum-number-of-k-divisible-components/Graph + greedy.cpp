#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    vector<long long> values;
    vector<vector<int>> adj;
    vector<int> par;
    vector<int> lv;
    priority_queue<pii, vector<pii>> pq;

    void dfs(int u, int p = -1, int depth = 0){
        par[u] = p;
        lv[u] = depth;
        int cnt = 0;
        for(int x : adj[u]){
            if(x == p) continue;
            dfs(x, u, depth+1);
            cnt++;
        }
        if(cnt == 0) pq.push({lv[u], u});
    }

    int split(int n, int k){
        vector<int> vis(n, 0);
        int ans = 0;
        while(!pq.empty()){
            pii u = pq.top(); pq.pop();
            int v = u.se;
            if(par[v] == -1){
                ans++;
                continue;
            }
            if(values[v] % k == 0) ans++;
            else values[par[v]] += values[v];
            if(vis[par[v]]) continue;
            vis[par[v]] = 1;
            pq.push({lv[par[v]], par[v]});
        }
        return ans;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->values = vector<long long>(values.begin(), values.end());
        adj.resize(n);
        par.resize(n);
        lv.resize(n);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0);
        return split(n, k);
    }
};