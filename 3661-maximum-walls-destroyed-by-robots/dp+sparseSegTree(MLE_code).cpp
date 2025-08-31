#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

const int mod = 1e9 + 7;

struct Node {
    Node *left = nullptr, *right = nullptr;
    ll val;
    pll lazy = {1, 0};
    
    Node(): val(0), lazy({1, 0}) {}
    
    Node operator+(const Node& b) const {
        Node res;
        res.val = (val + b.val) % mod;
        return res;
    }

    ~Node() {
        delete left;
        delete right;
    }
};

class SparseSegTree {
private:
    Node *r = new Node();
    int n;

    void push(Node *cur, int l, int r) {
        int m = (l + r) >> 1;
        if (!cur->left) cur->left = new Node();
        if (!cur->right) cur->right = new Node();
        apply(cur->left, l, m, cur->lazy);
        apply(cur->right, m+1, r, cur->lazy);
        cur->lazy = {1, 0};
    }

    void apply(Node *cur, int l, int r, pll x) {
        ll b = x.fi, c = x.se;
        int len = r-l+1;
        cur->val = (cur->val * b % mod + c * len % mod) % mod;
        cur->lazy.fi = cur->lazy.fi * b % mod;
        cur->lazy.se = (cur->lazy.se * b % mod + c) % mod;
    }

    void update(Node *cur, int l, int r, int u, int v, pll x) {
        if (l > v || r < u) return;
        if (u <= l && r <= v) {
            apply(cur, l, r, x);
            return;
        }
        push(cur, l, r);
        ll mid = (l + r) >> 1;
        update(cur->left, l, mid, u, v, x);
        update(cur->right, mid+1, r, u, v, x);
        cur->val = (cur->left->val + cur->right->val) % mod;
    }

    ll query(Node *cur, int l, int r, int u, int v) {
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return cur->val;
        push(cur, l, r);
        int mid = (l + r) >> 1;
        ll t1 = query(cur->left, l, mid, u, v) % mod;
        ll t2 = query(cur->right, mid+1, r, u, v) % mod;
        return (t1 + t2) % mod;
    }

public:
    SparseSegTree() {}
    SparseSegTree(int _n): n(_n) {}

    void update(int u, int v, pll val) { update(r, 1, n, u, v, val); }
    
    ll query(int u, int v) { return query(r, 1, n, u, v); }
};

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        // {robotPos, bulletRange}
        vector<pll> a;
        for (int i = 0; i < robots.size(); i++) {
            a.push_back({robots[i], distance[i]});
        }
        sort(a.begin(), a.end());
        
        SparseSegTree wallPos(1e9 + 6);
        for (int i = 0; i < walls.size(); i++) {
            wallPos.update(walls[i], walls[i], make_pair(1, 1));
        }

        // {left, right}
        vector<vector<int>> dp(a.size(), vector<int>(2));
        a.push_back({INT_MAX, 0});
        dp[0][0] = wallPos.query(a[0].fi - a[0].se, a[0].fi);
        dp[0][1] = wallPos.query(a[0].fi, min(a[0].fi + a[0].se, a[1].fi - 1));
        for (int i = 1; i < dp.size(); i++) {
            // i-1 left, i left
            pii cur_left = {max(a[i].fi - a[i].se, a[i-1].fi + 1), a[i].fi};
            int left_left = dp[i-1][0] + wallPos.query(cur_left.fi, cur_left.se);
            // i-1 right, i left
            pii prev_right = {a[i-1].fi, min(a[i-1].fi + a[i-1].se, a[i].fi - 1)};
            cur_left.fi = max(prev_right.se + 1, cur_left.fi);
            int right_left = dp[i-1][1] + wallPos.query(cur_left.fi, cur_left.se);
            // i-1 right, i right
            pii cur_right = {a[i].fi, min(a[i].fi + a[i].se, a[i+1].fi - 1)};
            int right_right = wallPos.query(cur_right.fi, cur_right.se);

            dp[i][0] = max(left_left, right_left);
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + right_right;
        }
        
        return max(dp.back()[0], dp.back()[1]);
    }
};