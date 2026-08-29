class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 1);
        int l = 0, ans = 1;
        for (int r = 1; r < n; r++) {
            if (nums[r-1] >= nums[r]) l = r;
            v[r] = r-l+1;
            ans = max(ans, v[r] / 2);
            if (r >= v[r] && v[r - v[r]] >= v[r]) {
                ans = max(ans, v[r]);
            }
        }
        return ans;
    }
};