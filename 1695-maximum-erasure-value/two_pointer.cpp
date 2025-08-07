class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, curSum = 0;
        vector<int> cnt(10006);
        for (int l = 0, r = 0; r < n; r++) {
            cnt[nums[r]]++;
            curSum += nums[r];
            while (cnt[nums[r]] > 1) {
                curSum -= nums[l];
                cnt[nums[l]]--;
                l++;
            }
            ans = max(ans, curSum);
        }
        return ans;
    }
};