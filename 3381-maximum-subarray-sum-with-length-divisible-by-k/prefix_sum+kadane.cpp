#define ll long long

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> pref(n+1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + nums[i-1];
        }
        ll ans = pref[k];
        for (int i = 1; i <= k; i++) {
            ll sum = 0;
            for (int j = k+i-1; j <= n; j += k) {
                ll cur = pref[j] - pref[j-k];
                sum += cur;
                ans = max(ans, sum);
                sum = max(sum, 0ll);
            }
        }
        return ans;
    }
};