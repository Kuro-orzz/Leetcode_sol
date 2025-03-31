class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;
    int cnt = 0;

    bool dfs(int u){
        cnt++;
        vis[u] = 1;
        bool res = true;
        for(int v : adj[u]){
            if(vis[v]) continue;
            if(!dfs(v))
                res = false;
        }
        return res && adj[u].size() == cnt;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vis.resize(n, 0);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            cnt = -1;
            if(dfs(i))
                ans++;
        }
        return ans;
    }
};