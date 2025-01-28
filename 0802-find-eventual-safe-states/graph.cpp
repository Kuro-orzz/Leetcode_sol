class Solution {
public:
    vector<vector<int>> graph;
    set<int> s;
    vector<int> vis;

    bool dfs(int u){
        vis[u] = 1;
        bool t = true;
        for(int x : graph[u]){
            if(vis[x] == 2) continue;
    	    else if(vis[x] == 1 || !dfs(x)) 
                t = false;
        }
        if(t){
            vis[u] = 2;
            s.insert(u);
        }
        return t;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        this->graph = graph;
        int n = graph.size();
        vis.resize(n, 0);
        for(int i = 0; i < n; i++)
            if(!vis[i]) dfs(i);
        vector<int> ans;
        for(int x : s)
            ans.push_back(x);
        return ans;
    }
};