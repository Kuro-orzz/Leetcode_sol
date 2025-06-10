#define all(x) (x).begin(),(x).end()

struct Dsu {
    vector<int> par, sz, mn_val;

    Dsu() {}
    Dsu(int n): par(n+1), sz(n+1, 1), mn_val(n+1) {
        iota(all(par), 0);
        iota(all(mn_val), 0);
    }

    int find(int v) {
        if(v == par[v]) return v;
        mn_val[par[v]] = min(mn_val[par[v]], mn_val[v]);
        return par[v] = find(par[v]);
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        mn_val[a] = min(mn_val[a], mn_val[b]);
        sz[a] += sz[b];
    }

    int getMinVal(int u) {
        u = find(u);
        return mn_val[u];
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        Dsu g(26);
        for (int i = 0; i < n; i++) {
            int k1 = s1[i] - 'a';
            int k2 = s2[i] - 'a';
            g.merge(k1, k2);
        }
        string ans = "";
        for (int i = 0; i < baseStr.size(); i++) {
            ans += g.getMinVal(baseStr[i]-'a') + 'a';
        }
        return ans;
    }
};