class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        vector<int> ans(n);
        int sumRight = 0;
        for (int i = 0; i < n; i++) {
            ans[i] = abs(sum - nums[i] - sumRight * 2);
            sumRight += nums[i];
        }
        return ans;
    }
};