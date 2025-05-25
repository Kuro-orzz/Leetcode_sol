struct Lca {
    vector<vector<int>> tree, up;
    vector<int> h;

    Lca() {}
    Lca(int n): tree(n+1), up(n+1, vector<int>(20)), h(n+1, 0) {}

    void dfs(int u, int p) {
        for(int v : tree[u]) {
            if(v == p) continue;
            up[v][0] = u;
            h[v] = h[u] + 1;
            for(int j = 1; j < 20; j++) {
                up[v][j] = up[up[v][j-1]][j-1];
            }
            dfs(v, u);
        }
    }

    void addEdge(int u, int v) {
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    int query(int u, int v) {
        if(h[u] < h[v]) swap(u, v);
        int k = h[u]-h[v];
        u = ancestor_k(u, k);
        if(u == v) return u;

        k = __lg(h[u]);
        for(int j = k; j >= 0; j--) {
            if(up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

    int dist(int u, int v) {
        int node = query(u, v);
        return h[u] + h[v] - 2 * h[node];
    }

    int ancestor_k(int u, int k) {
        for(int j = 0; (1 << j) <= k; j++) {
            if(k >> j & 1)
                u = up[u][j];
        }
        return u;
    }
};

class Solution {
public:
    int mod = 1e9 + 7;
    
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        Lca lca(n);
        for (int i = 0; i < (int)edges.size(); i++) {
            lca.addEdge(edges[i][0], edges[i][1]);            
        }
        lca.dfs(1, -1);
        vector<int> p(n + 1);
        p[1] = 1;
        for (int i = 2; i < n+1; i++) {
            p[i] = p[i-1] * 2 % mod;
        }
        vector<int> ans;
        for (int i = 0; i < (int)queries.size(); i++) {
            int u = queries[i][0], v = queries[i][1];
            if (u == v) ans.push_back(0);
            else {
                int d = lca.dist(u, v);
                ans.push_back(p[d]);    
            }
        }
        return ans;
    }
};