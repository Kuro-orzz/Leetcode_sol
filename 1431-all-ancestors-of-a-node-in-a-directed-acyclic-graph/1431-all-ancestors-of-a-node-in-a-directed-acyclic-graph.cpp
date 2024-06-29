class Solution {
public:
    vector<vector<int>> ans, adj;
    vector<int> st, vis;
    void dfs(int par, int u){
        vis[u] = 1;
        if(u != par)
            st.push_back(u);
        for(int v : adj[u]){
            if(!vis[v])
                dfs(par, v);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ans.resize(n);
        adj.resize(n);
        vis.resize(n);
        for(int i = 0; i < edges.size(); i++)
            adj[edges[i][1]].push_back(edges[i][0]);
        for(int i = 0; i < n; i++){
            st.clear();
            for(int j = 0; j < n; j++)
                vis[j] = 0; 
            dfs(i, i);
            for(int j = 0; j < st.size(); j++)
                ans[i].push_back(st[j]);
        }
        for(int i = 0; i < n; i++)
            sort(ans[i].begin(), ans[i].end()); 
        return ans;
    }
};