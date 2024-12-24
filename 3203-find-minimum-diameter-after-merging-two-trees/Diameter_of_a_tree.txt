#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    vector<vector<int>> adj1, adj2;

    pii bfs(int u, int n, vector<vector<int>>& adj){
        vector<int> vis(n+1, 0);
        queue<pii> q;
        q.push({u, 0});
        vis[u] = 1;
        pii ans = {u, 0};
        while(!q.empty()){
            pii v = q.front(); q.pop();
            ans = v;
            for(int x : adj[v.fi])
                if(!vis[x]){
                    q.push({x, v.se+1});
                    vis[x] = 1;
                }
        }
        return ans;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();
        adj1.resize(n+1);
        adj2.resize(m+1);
        for(int i = 0; i < edges1.size(); i++){
            adj1[edges1[i][0]].push_back(edges1[i][1]);
            adj1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for(int i = 0; i < edges2.size(); i++){
            adj2[edges2[i][0]].push_back(edges2[i][1]);
            adj2[edges2[i][1]].push_back(edges2[i][0]);
        }
        pii a = bfs(0, n, adj1);
        pii b = bfs(a.fi, n, adj1);
        int dist1 = b.se;
        pii c = bfs(0, m, adj2);
        pii d = bfs(c.fi, m, adj2);
        int dist2 = d.se;
        return max({(dist1+1)/2+(dist2+1)/2+1, dist1, dist2});
    }
};