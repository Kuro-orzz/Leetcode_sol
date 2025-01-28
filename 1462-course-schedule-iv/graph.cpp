class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;

    void dfs(int u){
        vis[u] = 1;
        for(int x : adj[u]){
            if(vis[x]) continue;
            dfs(x);
        }
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adj.resize(numCourses);
        for(auto it : prerequisites)
            adj[it[0]].push_back(it[1]);
        vector<bool> ans;
        for(int i = 0; i < queries.size(); i++){
            int u = queries[i][0];
            int v = queries[i][1];
            vis = vector<int>(numCourses, 0);
            dfs(u);
            if(vis[v]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};