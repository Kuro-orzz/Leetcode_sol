#define all(x) (x).begin(),(x).end()

template <typename T>
struct SegTree {
    int n;
    vector<T> tree;

    SegTree() {}
    SegTree(int _n): n(_n), tree(_n*4) {}

    void update(int pos, T val) {
        update(1, 1, n, pos, val);
    }

    T getMin(int u, int v) {
        return getMin(1, 1, n, u, v);
    }

    void update(int id, int l, int r, int pos, T val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            tree[id] = val;
            return;
        }
        int mid = (l + r) >> 1;
        update(id*2, l, mid, pos, val);
        update(id*2+1, mid+1, r, pos, val);
        tree[id] = min(tree[id*2], tree[id*2+1]);
    }

    T getMin(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return 1e9;
        if (l >= u && r <= v) return tree[id];
        int mid = (l + r) >> 1;
        T t1 = getMin(id*2, l, mid, u, v);
        T t2 = getMin(id*2+1, mid+1, r, u, v);
        return min(t1, t2);
    }
};

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
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        Dsu dsu(c);
        for (int i = 0; i < connections.size(); i++) {
            dsu.merge(connections[i][0], connections[i][1]);
        }
        map<int, vector<int>> mp;
        for (int i = 1; i <= c; i++) {
            int par = dsu.find(i);
            mp[par].push_back(i);
        }
        map<int, SegTree<int>> st;
        vector<int> pos(c+1);
        for (auto &[val, arr] : mp) {
            st[val].n = arr.size() + 1;
            st[val].tree.assign(4 * (arr.size() + 1), 1e9);
            int cnt = 1;
            for (int x : arr) {
                pos[x] = cnt;
                st[val].update(cnt++, x);
            }
        }
        vector<int> ans, isOn(c+1, 1);
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][1];
            if (queries[i][0] == 1) {
                if (isOn[x]) ans.push_back(x);
                else {
                    int par = dsu.find(x);
                    int res = st[par].getMin(1, mp[par].size());
                    if (res == 1e9) ans.push_back(-1);
                    else ans.push_back(res);
                }
            } else if (queries[i][0] == 2) {
                isOn[x] = 0;
                int par = dsu.find(x);
                st[par].update(pos[x], 1e9);
            }
        }
        return ans;
    }
};