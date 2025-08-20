#define ll long long

class Solution {
public:
    ll _pow(int a, int b) {
        ll ans = 1;
        for (int i = 0; i < b; i++) {
            ans *= a;
        }
        return ans;
    }

    int numberOfWays(int n, int x) {
        int mod = 1e9+7;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            ll t = _pow(i, x);
            if (t <= n) v.push_back(t);
        }
        vector<ll> dp(n+1);
        dp[0] = 1;
        for (int x : v) {
            for (int j = n; j >= x; j--) {
                dp[j] = (dp[j] + dp[j-x]) % mod;
            }
        }
        return dp[n];
    }
};