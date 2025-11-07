#define ll long long

class Solution {
public:
    const int mod = 1e9 + 7;
    
    int countCoprime(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<ll>> cnt(n, vector<ll>(151, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt[i][mat[i][j]]++;
            }
        }
        vector<vector<ll>> dp(n, vector<ll>(151, 0));
        for (int i = 0; i < n; i++) {
            for (int prev = 1; prev <= 150; prev++) {
                if (!i) { dp[i][prev] += cnt[i][prev]; continue; }
                vector<int> v(151);
                for (int x = 1; x <= 150; x++) {
                    v[__gcd(prev, x)] += cnt[i][x];
                }
                for (int x = 1; x <= 150; x++) {
                    dp[i][x] = (dp[i][x] + dp[i-1][prev] * v[x]) % mod;
                }
            }
        }
        return dp[n-1][1];
    }
};