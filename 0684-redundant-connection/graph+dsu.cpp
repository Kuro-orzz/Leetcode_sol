struct DSU {
    vector<int> par, sz;

    DSU(){}

    DSU(int n): par(n+1), sz(n+1, 1) {
        for(int i = 0; i <= n; i++)
            par[i] = i;
    }

    int find(int u){
        if(u == par[u])
            return u;
        return par[u] = find(par[u]);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        DSU dsu(edges.size());
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(dsu.find(u) == dsu.find(v)){
                ans = edges[i];
                continue;
            }
            dsu.merge(u, v);
        }
        return ans;
    }
};