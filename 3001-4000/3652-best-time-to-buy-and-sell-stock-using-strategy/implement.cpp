#define ll long long

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<ll> pref(n+1), cur(n+1);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + prices[i-1];
            cur[i] = cur[i-1] + prices[i-1] * strategy[i-1];
        }
        ll ans = cur[n];
        for (int i = k; i <= n; i++) {
            ans = max(ans, cur[i-k] + pref[i] - pref[i-k/2] + cur[n] - cur[i]);
        }
        return ans;
    }
};