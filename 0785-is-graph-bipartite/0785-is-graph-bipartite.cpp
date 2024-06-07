class Solution {
public:
    vector<int> color;
    bool bfs(int u, vector<vector<int>> &graph){
        queue<int> q;
        q.push(u);
        color[u] = 0;
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int x : graph[v]){
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

    bool isBipartite(vector<vector<int>>& graph) {
        color.resize(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++){
            if(color[i] != -1) continue;
            if(!bfs(i, graph))
                return false;
        }
        return true;
    }
};