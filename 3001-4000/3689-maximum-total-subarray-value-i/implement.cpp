class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = -1, mn = 1e9;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }
        return 1ll * (mx - mn) * k;
    }
};