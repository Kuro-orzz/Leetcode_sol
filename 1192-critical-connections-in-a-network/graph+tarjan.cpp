class Solution {
public:
    int bridge = 0, cnt = 0;
    vector<int> vis, id, low;
    vector<vector<int>> adj, ans;

    void dfs(int u, int p){
        vis[u] = 1;
        id[u] = low[u] = ++cnt;
        for(int v : adj[u]){
            if(v == p)
                continue;
            if(id[v])
                low[u] = min(low[u], id[v]);
            else{
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] == id[v]) ans.push_back({u, v});
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vis = id = low = vector<int>(n, 0);
        adj.resize(n);
        for(int i = 0; i < connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i = 0; i < n; i++){
            if(!vis[i])
                dfs(i, 0);
        }
        return ans;
    }
};