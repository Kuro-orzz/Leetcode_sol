#define pii pair<int, int>
#define fi first
#define se second

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<pii> v = {{1, 0}};
        for (auto &it : restrictions) {
            v.push_back({it[0], it[1]});
        }
        v.push_back({n, 1e9});
        sort(v.begin(), v.end());
        
        vector<pii> mx = {{1, 0}};
        for (int i = 1; i < v.size(); i++) {
            int d_prev = v[i].fi - v[i-1].fi;
            pii t = {v[i].fi, min(v[i].se, mx.back().se + d_prev)};
            mx.push_back(t);
        }
        for (int i = (int)mx.size()-2; i >= 0; i--) {
            int d_next = v[i+1].fi - v[i].fi;
            mx[i] = {v[i].fi, min(mx[i].se, mx[i+1].se + d_next)};
        }

        int ans = 0;
        for (int i = 1; i < mx.size(); i++) {
            int d = mx[i].fi - mx[i-1].fi;
            if (abs(mx[i].se - mx[i-1].se) == d) {
                ans = max(ans, mx[i].se);
            } else if (abs(mx[i].se - mx[i-1].se) < d) {
                int diff = abs(mx[i].se - mx[i-1].se);
                ans = max(ans, max(mx[i-1].se, mx[i].se) + (d-diff)/2);
            }
        }
        return ans;
    }
};