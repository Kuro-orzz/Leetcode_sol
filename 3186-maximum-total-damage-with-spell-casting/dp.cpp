#define ll long long

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        sort(power.begin(), power.end());
        vector<int> v, cnt;
        for (int i = 0; i < n; i++) {
            v.push_back(power[i]);
            cnt.push_back(1);
            while (i + 1 < n && power[i] == power[i+1]) {
                cnt[cnt.size()-1]++;
                i++;
            }
        }
        int m = v.size();
        vector<vector<ll>> dp(m, vector<ll>(2));
        dp[0][0] = 0;
        dp[0][1] = 1ll * v[0] * cnt[0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            if (abs(v[i-1] - v[i]) <= 2) {
                if (i - 2 >= 0 && abs(v[i-2] - v[i]) <= 2) {
                    if (i - 3 >= 0) dp[i][1] = max(dp[i-3][1], dp[i-3][0]);
                } else if (i - 2 >= 0) dp[i][1] = max(dp[i-2][1], dp[i-2][0]);
            } else dp[i][1] = max(dp[i-1][1], dp[i-1][0]);
            dp[i][1] += v[i] * cnt[i];
        }
        return max(dp[m-1][0], dp[m-1][1]);
    }
};