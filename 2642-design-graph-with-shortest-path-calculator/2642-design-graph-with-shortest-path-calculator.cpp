#define pii pair<int, int>
#define fi first
#define se second
class Graph {
public:
    int nodes = 0;
    vector<vector<int>> e;
    Graph(int n, vector<vector<int>>& edges) {
        nodes = n;
        e = edges; 
    }
    
    void addEdge(vector<int> edge) {
        e.push_back(edge);
    }
    
    int shortestPath(int node1, int node2) {
        vector<pii> adj[nodes];
        for(int i = 0; i < e.size(); i++)
            adj[e[i][0]].push_back({e[i][1], e[i][2]});
        vector<bool> vis(nodes, false);
        vector<int> d(nodes, INT_MAX);
        d[node1] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, node1});
        while(!pq.empty()){
            int u = pq.top().se;
            int dist = pq.top().fi;
            pq.pop();
            if(vis[node2]) break;
            if(vis[u]) continue;
            vis[u] = true;
            for(auto it : adj[u]){
                int v = it.fi;
                int w = it.se;
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    pq.push({d[v], v});
                }
            }
        }
        if(d[node2] == INT_MAX)
            return -1;
        return d[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */