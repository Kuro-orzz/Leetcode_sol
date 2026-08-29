#define all(x) (x).begin(),(x).end()

struct Dsu {
    vector<int> par, sz;

    Dsu() {}
    Dsu(int n): par(n+1), sz(n+1, 1) {
        iota(all(par), 0);
    }

    int find(int v) {
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }

    bool same_component(int u, int v) {
        return find(u) == find(v);
    }

    int component_size(int u) {
        u = find(u);
        return sz[u];
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        Dsu dsu(n);
        vector<int> dist(n+1, INT_MAX);
        for (int i = 0; i < roads.size(); i++) {
            int u = dsu.find(roads[i][0]);
            int v = dsu.find(roads[i][1]);
            dsu.merge(roads[i][0], roads[i][1]);
            dist[u] = dist[v] = min({dist[u], dist[v], roads[i][2]});
        }    
        return dist[dsu.find(n)];
    }
};