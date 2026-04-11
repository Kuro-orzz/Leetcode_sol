#define ll long long
#define pll pair<ll, ll>
#define fi first
#define se second

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<pll>> dp(n, vector<pll>(m, {LLONG_MAX, LLONG_MIN}));
        if (grid[0][0] < 0) dp[0][0].fi = grid[0][0];
        else dp[0][0].se = grid[0][0];
        for (int j = 1; j < m; j++) {
            if (grid[0][j] < 0) {
                if (dp[0][j-1].fi != LLONG_MAX) dp[0][j].se = dp[0][j-1].fi * grid[0][j];
                if (dp[0][j-1].se != LLONG_MIN) dp[0][j].fi = dp[0][j-1].se * grid[0][j];
            } else {
                if (dp[0][j-1].fi != LLONG_MAX) dp[0][j].fi = dp[0][j-1].fi * grid[0][j];
                if (dp[0][j-1].se != LLONG_MIN) dp[0][j].se = dp[0][j-1].se * grid[0][j];
            }
        }
        for (int i = 1; i < n; i++) {
            if (grid[i][0] < 0) {
                if (dp[i-1][0].fi != LLONG_MAX) dp[i][0].se = dp[i-1][0].fi * grid[i][0];
                if (dp[i-1][0].se != LLONG_MIN) dp[i][0].fi = dp[i-1][0].se * grid[i][0];
            } else {
                if (dp[i-1][0].fi != LLONG_MAX) dp[i][0].fi = dp[i-1][0].fi * grid[i][0];
                if (dp[i-1][0].se != LLONG_MIN) dp[i][0].se = dp[i-1][0].se * grid[i][0];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (dp[i-1][j].fi == 0 || dp[i-1][j].se == 0) dp[i][j].se = max(dp[i][j].se, 0ll);
                if (dp[i][j-1].fi == 0 || dp[i][j-1].se == 0) dp[i][j].se = max(dp[i][j].se, 0ll);
                if (grid[i][j] == 0) dp[i][j] = {0, 0};
                if (grid[i][j] < 0) {
                    if (dp[i-1][j].se != LLONG_MIN) {
                        dp[i][j].fi = min(dp[i][j].fi, dp[i-1][j].se * grid[i][j]);
                    }
                    if (dp[i][j-1].se != LLONG_MIN) {
                        dp[i][j].fi = min(dp[i][j].fi, dp[i][j-1].se * grid[i][j]);
                    }

                    if (dp[i-1][j].fi != LLONG_MAX) {
                        dp[i][j].se = max(dp[i][j].se, dp[i-1][j].fi * grid[i][j]);
                    }
                    if (dp[i][j-1].fi != LLONG_MAX) {
                        dp[i][j].se = max(dp[i][j].se, dp[i][j-1].fi * grid[i][j]);
                    }
                } else {
                    if (dp[i-1][j].fi != LLONG_MAX) {
                        dp[i][j].fi = min(dp[i][j].fi, dp[i-1][j].fi * grid[i][j]);
                    }
                    if (dp[i][j-1].fi != LLONG_MAX) {
                        dp[i][j].fi = min(dp[i][j].fi, dp[i][j-1].fi * grid[i][j]);
                    }

                    if (dp[i-1][j].se != LLONG_MIN) {
                        dp[i][j].se = max(dp[i][j].se, dp[i-1][j].se * grid[i][j]);
                    }
                    if (dp[i][j-1].se != LLONG_MIN) {
                        dp[i][j].se = max(dp[i][j].se, dp[i][j-1].se * grid[i][j]);
                    }
                }
            }
        }
        if (dp[n-1][m-1].se == LLONG_MIN) return -1;
        return dp[n-1][m-1].se % (int)(1e9 + 7);
    }
};