#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<pii> adj[n];
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int> vis(n, 0);
        vector<vector<int>> par(n);
        for(int i = 0; i < n; i++)
            par[i].push_back(i);
        vector<int> d(n, INT_MAX);
        d[0] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            int u = pq.top().se;
            int dist = pq.top().fi;
            pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(auto it : adj[u]){
                int v = it.fi;
                int w = it.se;
                if(d[u] + w <= d[v]){
                    if(d[u] + w < d[v])
                        par[v].clear();
                    par[v].push_back(u);
                    d[v] = d[u] + w;
                    pq.push({d[v], v});
                }
            }
        }
        map<pii, int> path;
        int t = n-1;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(t);
        visited[t] = true;
        while(!q.empty()){
            t = q.front();
            q.pop();
            for(int i : par[t]){
                path[{i, t}] = 1;
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        vector<bool> ans(edges.size(), false);
        for(int i = 0; i < edges.size(); i++){
            if(path[{edges[i][0], edges[i][1]}] || path[{edges[i][1], edges[i][0]}])
                ans[i] = true;
        }
        return ans;
    }
};