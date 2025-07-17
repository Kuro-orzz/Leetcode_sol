template <typename T>
struct SegTree {
    int n;
    vector<T> tree;

    SegTree() {}
    SegTree(int _n): n(_n), tree(_n*4) {}

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

    T get(int id, int l, int r, int u, int v) {
        if (l > v || r < u || tree[id]) return -1;
        if (l == r) return l;
        int mid = (l + r) >> 1;
        int t = get(id*2, l, mid, u, v);
        if (t != -1) return t;
        return get(id*2+1, mid+1, r, u, v);
    }
};

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [&](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int ans = 0;
        int n = 1e5;
        SegTree<int> st(n);
        for (auto &it : events) {
            int query = st.get(1, 1, n, it[0], it[1]);
            if (query == -1) continue;
            st.update(1, 1, n, query, 1);
            ans++;
        }
        return ans;
    }
};