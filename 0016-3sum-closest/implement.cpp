class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1e9;
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                for (int i = l + 1; i < r; i++) {
                    if (abs(ans-target) > abs(target-nums[l]-nums[i]-nums[r]))
                        ans = nums[l] + nums[i] + nums[r];
                }
            }
        }
        return ans;
    }
};