class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return 0;
        sort(nums.begin(), nums.end());
        int ans = n;
        for (int i = 0; i < n; i++) {
            int pos = upper_bound(nums.begin(), nums.end(), 1ll * nums[i] * k) - nums.begin();
            ans = min(ans, n - pos + i);
        }
        return ans;
    }
};