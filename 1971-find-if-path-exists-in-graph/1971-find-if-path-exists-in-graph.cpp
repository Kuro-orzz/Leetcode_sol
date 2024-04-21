class Solution {
public:
    vector<int> adj[200001];
    bool visited[200001];
    void dfs(int u){
        visited[u] = true;
        for(int v : adj[u])
            if(!visited[v])
                dfs(v);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(source);
        return visited[destination] ? true : false;
    }
};