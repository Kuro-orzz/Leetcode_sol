class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = nums[0], ans = -1;
        for (int i = 1; i < nums.size(); i++) {
            ans = max(ans, nums[i] - mn);
            mn = min(mn, nums[i]);
        }
        return ans > 0 ? ans : -1;
    }
};