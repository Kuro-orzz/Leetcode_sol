class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }
};