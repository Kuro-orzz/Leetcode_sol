#define pii pair<int, int>
#define fi first
#define se second

class BinLift {
public:
    int n;
    vector<vector<int>> up;
    vector<int> lg;
    BinLift(int n): n(n), up(n, vector<int>(17)), lg(17) {}

    void preprocess(vector<pii> &a, int maxDiff) {
        int r = 0;
        for (int i = 0; i < n; ++i) {
            while (r < n && a[r].fi -a[i].fi <= maxDiff)
                r++;
            up[i][0] = r-1;
        } 
        lg[0] = 1;
        for (int j = 1; j < 17; ++j) {
            lg[j] = lg[j-1]*2;
            for (int u = 0; u < n; ++u)
                up[u][j] = up[up[u][j - 1]][j - 1];
        }
    } 
};

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pii> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[v[i].se] = i;
        }
        vector<int> group(n);
        int g = 0;
        for (int i = 1; i < n; i++) {
            if (v[i].fi-v[i-1].fi > maxDiff) g++;
            group[i] = g;
        }
        BinLift tree(n);
        tree.preprocess(v, maxDiff);
        vector<int> ans;
        for (auto it : queries) {
            int x = mp[it[0]];
            int y = mp[it[1]];
            if (group[x] != group[y]) {
                ans.push_back(-1);
            }
            else {
                if (x > y) swap(x, y);
                if (x == y) {
                    ans.push_back(0);
                    continue;
                }
                int step = 0;
                int cur = x;
                for (int i = 16; i >= 0; i--) {
                    if (tree.up[cur][i] < y) {
                        cur = tree.up[cur][i];
                        step += tree.lg[i];
                    }
                }
                ans.push_back(step+1);
            }
        }
        return ans;
    }
};