#define ll long long
#define pll pair<ll, ll>
#define fi first
#define se second

template <typename T>
struct AfflineSegTree {
    vector<T> st;
    vector<pll> lazy;
    int mod = 1e9 + 7;

    AfflineSegTree() {}
    AfflineSegTree(int n): st(n*4), lazy(n*4) {}

    void build(int id, int l, int r, const vector<ll> &a) {
        lazy[id] = {1, 0};
        if (l == r) {
            st[id] = a[l] % mod;
            return;
        }
        int m = (l + r) >> 1;
        build(id*2, l, m, a);
        build(id*2+1, m+1, r, a);
        st[id] = (st[id*2] + st[id*2+1]) % mod;
    }

    void push(int id, int l, int r) {
        int m = (l + r) >> 1;
        apply(id*2, l, m, lazy[id]);
        apply(id*2+1, m+1, r, lazy[id]);
        lazy[id] = {1, 0};
    }

    void apply(int id, int l, int r, pll val) {
        int len = r-l+1;
        st[id] = (st[id] * val.fi % mod + val.se * len % mod) % mod;
        lazy[id].fi = lazy[id].fi * val.fi % mod;
        lazy[id].se = (lazy[id].se * val.fi % mod + val.se) % mod;
    }

    void update(int id, int l, int r, int u, int v, pll val) {
        if (v < l || u > r)
            return;
        if (u <= l && v >= r) {
            apply(id, l, r, val);
            return;
        }
        push(id, l, r);
        int mid = (l + r) >> 1;
        update(id*2, l, mid, u, v, val);
        update(id*2+1, mid+1, r, u, v, val);
        st[id] = (st[id*2] + st[id*2+1]) % mod;
    }

    T getSumMod(int id, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (l >= u && r <= v) return st[id];
        int mid = (l + r) >> 1;
        push(id, l, r);
        T t1 = getSumMod(id*2, l, mid, u, v) % mod;
        T t2 = getSumMod(id*2+1, mid+1, r, u, v) % mod;
        return (t1 + t2) % mod;
    }
};

class Fancy {
public:
    int mx_sz = 1e5 + 6;
    int cur_sz = 0;
    AfflineSegTree<ll> st{mx_sz};

    Fancy() {
        
    }
    
    void append(int val) {
        cur_sz++;
        st.update(1, 1, mx_sz, cur_sz, cur_sz, {0, val});
    }
    
    void addAll(int inc) {
        st.update(1, 1, mx_sz, 1, cur_sz, {1, inc});
    }
    
    void multAll(int m) {
        st.update(1, 1, mx_sz, 1, cur_sz, {m, 0});
    }
    
    int getIndex(int idx) {
        if (idx+1 > cur_sz) return -1;
        return st.getSumMod(1, 1, mx_sz, idx+1, idx+1);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */