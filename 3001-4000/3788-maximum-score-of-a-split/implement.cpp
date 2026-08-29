#define ll long long

class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<ll> prefSum(n + 1, 0), suffMin(n+2, INT_MAX);
        for (int i = 1; i <= n; i++) {
            prefSum[i] = prefSum[i-1] + nums[i-1];
        }
        for (int i = n-1; i >= 0; i--) {
            suffMin[i] = min(suffMin[i+1], 1ll * nums[i]);
        }
        ll ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, prefSum[i] - suffMin[i]);
        }
        return ans;
    }
};