class Solution {
public:
    vector<vector<int>> adj;
    vector<int> d, vis;
    int bfs(int u, int n){
        queue<int> q;
        q.push(u);
        vis[u] = 1;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(int v : adj[t]){
                if(!vis[v]){
                    d[v] = min(d[v], d[t]+1);
                    if(v == n-1)
                        return d[v];
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        return d[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        adj.resize(n);
        d.resize(n);
        vis.resize(n, 0);
        for(int i = 0; i < n; i++){
            d[i] = i;
            adj[i].push_back(i+1);
        }
        adj[n-1].pop_back();
        for(int i = 0; i < queries.size(); i++){
            int a = queries[i][0];
            int b = queries[i][1];
            if(a > b) swap(a, b);
            adj[a].push_back(b);
            for(int i = 0; i < n; i++)
                vis[i] = 0;
            int ans = bfs(0, n);
            res.push_back(ans);
        }
        return res;
    }
};