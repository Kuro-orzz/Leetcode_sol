#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        // {robotPos, bulletRange}
        vector<pll> a;
        for (int i = 0; i < robots.size(); i++) {
            a.push_back({robots[i], distance[i]});
        }
        sort(a.begin(), a.end());
        
        sort(walls.begin(), walls.end());
        // [l, r]
        auto wall_range = [&](int l, int r){
            int L = lower_bound(walls.begin(), walls.end(), l) - walls.begin(); 
            int R = upper_bound(walls.begin(), walls.end(), r) - walls.begin();
            return R - L;
        };

        // {left, right}
        vector<vector<int>> dp(a.size(), vector<int>(2));
        a.push_back({INT_MAX, 0});
        dp[0][0] = wall_range(a[0].fi - a[0].se, a[0].fi);
        dp[0][1] = wall_range(a[0].fi, min(a[0].fi + a[0].se, a[1].fi - 1));
        for (int i = 1; i < dp.size(); i++) {
            // i-1 left, i left
            pii cur_left = {max(a[i].fi - a[i].se, a[i-1].fi + 1), a[i].fi};
            int left_left = dp[i-1][0] + wall_range(cur_left.fi, cur_left.se);
            // i-1 right, i left
            pii prev_right = {a[i-1].fi, min(a[i-1].fi + a[i-1].se, a[i].fi - 1)};
            cur_left.fi = max(prev_right.se + 1, cur_left.fi);
            int right_left = dp[i-1][1] + wall_range(cur_left.fi, cur_left.se);
            // i-1 right, i right
            pii cur_right = {a[i].fi, min(a[i].fi + a[i].se, a[i+1].fi - 1)};
            int right_right = wall_range(cur_right.fi, cur_right.se);

            dp[i][0] = max(left_left, right_left);
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + right_right;
        }
        
        return max(dp.back()[0], dp.back()[1]);
    }
};