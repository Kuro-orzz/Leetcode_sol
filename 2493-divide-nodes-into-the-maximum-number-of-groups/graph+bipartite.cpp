class Solution {
public:
    vector<vector<int>> adj;
    vector<int> color, d, visited;

    bool checkBipartite(int u){
        queue<int> q;
        q.push(u);
        color[u] = 0;
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int x : adj[v]){
                if(color[x] == -1){
                    color[x] = 1-color[v];
                    q.push(x);
                }
                else if(color[x] == color[v])
                    return false;
            }
        }
        return true;
    }

    int bfs(int u, int n){
        vector<int> vis(n+1, 0);
        queue<int> q;
        vis[u] = 1;
        q.push(u);
        int d = 0;
        while(!q.empty()){
            int sz = q.size(); d++;
            for(int i = 0; i < sz; i++){
                int u = q.front(); q.pop();
                for(int v : adj[u])
                    if(!vis[v]){
                        vis[v] = 1;
                        q.push(v);
                    }
            }
        }
        return d;
    }

    int calGroup(int u){
        queue<int> q;
        visited[u] = 1;
        q.push(u);
        int res = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            res = max(res, d[u]);
            for(int v : adj[u])
                if(!visited[v]){
                    visited[v] = 1;
                    q.push(v);
                }
        }
        return res;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        adj.resize(n+1);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        color.resize(n+1, -1);
        for(int i = 1; i <= n; i++){
            if(color[i] != -1) continue;
            if(!checkBipartite(i))
                return -1;
        }
        d.resize(n+1, 0);
        for(int i = 1; i <= n; i++)
            d[i] = bfs(i, n);
        visited.resize(n+1, 0);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(!visited[i])
                ans += calGroup(i);
        }
        return ans;
    }
};