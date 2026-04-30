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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        Dsu dsu(n);
        for (int i = 0; i < allowedSwaps.size(); i++) {
            dsu.merge(allowedSwaps[i][0], allowedSwaps[i][1]);
        }
        unordered_map<int, multiset<int>> mp1;
        unordered_map<int, vector<int>> mp2;
        for (int i = 0; i < n; i++) {
            int par = dsu.find(i);
            mp1[par].insert(source[i]);
            mp2[par].push_back(target[i]);
        }
        int ans = 0;
        for (auto &it : mp2) {
            int par = it.first;
            for (int &x : it.second) {
                if (mp1[par].count(x)) {
                    mp1[par].erase(mp1[par].find(x));
                }
            }
            ans += mp1[par].size();
        }
        return ans;
    }
};